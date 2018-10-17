#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"

#include <ctime>
#include <cassert>
#include <cstdio>
#include <stdexcept>
#include "Messages.hpp"

/*****************************************************************************/


Date::Date()
{
	time_t currentTime = time(nullptr);

	tm* currentTM = gmtime(&currentTime);

	m_year = currentTM->tm_year + 1900;
	m_month = currentTM->tm_mon + 1;
	m_day = currentTM->tm_mday;
	m_mins = currentTM->tm_min;
	m_hour = currentTM->tm_hour;
}


/*****************************************************************************/


Date::Date(int _year, int _month, int _day, int _hour, int _mins, int _sec)
	: m_year(_year), m_month(_month), m_day(_day), m_hour(_hour), m_mins(_mins), m_seconds(_sec)
{
	if (!isValid())
		throw std::logic_error(Messages::DateWrongFormat);
}


/*****************************************************************************/


Date::Date(const char * _yyyyMMDDHHMNSS, char _sep, char _timeSep)
{
	char sep1, sep2, sep3, sep4, sep5;
	int nMatched = sscanf(_yyyyMMDDHHMNSS, "%d%c %d%c %d%c %d%c %d%c %d", &m_year, &sep1, &m_month, &sep2, &m_day, &sep3, &m_hour, &sep4, &m_mins, &sep5, &m_seconds);
	if (nMatched != 11 || sep1 != _sep || sep2 != _sep || sep3 != _sep || sep4 != _timeSep || sep5 != _timeSep)
		throw std::logic_error(Messages::DateWrongFormat);

	if (!isValid())
		throw std::logic_error(Messages::DateWrongFormat);
}
/*****************************************************************************/


bool Date::isValid() const
{
	if (m_year == 0)
		return false;

	if (m_month < 1 || m_month > 12)
		return false;

	if (m_day < 1)
		return false;

	if (m_hour < 0 || m_hour > 23)
		return false;

	if (m_mins < 0 || m_mins > 59)
		return false;

	if (m_seconds < 1 || m_seconds > 59)
		return false;

	else if (m_month == 2 && isLeapYear())
		return m_day <= 29;

	else
	{
		static const int s_daysInMonth[] = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		return m_day <= s_daysInMonth[m_month - 1];
	}
}


/*****************************************************************************/


bool Date::isLeapYear() const
{
	if (m_year % 4 != 0)
		return false;

	else if (m_year % 100 == 0)
		return (m_year % 400 == 0);

	return true;
}


/*****************************************************************************/


bool Date::operator == (Date d) const
{
	return m_year == d.getYear() && m_month == d.getMonth() && m_day == d.getDay() && m_hour == d.getHour() && m_mins == d.getMinutes() && m_seconds == d.getSeconds();
}



/*****************************************************************************/


bool Date::operator != (Date d) const
{
	return !(*this == d);
}


/*****************************************************************************/


bool Date::operator < (Date d) const
{
	if (m_year < d.getYear())
		return true;

	else if (m_year == d.getYear())
	{
		if (m_month < d.getMonth())
			return true;

		else if (m_month == d.getMonth())
			return m_day < d.getDay();
	}

	return false;
}


/*****************************************************************************/


bool Date::operator > (Date d) const
{
	return d < *this;
}


/*****************************************************************************/


bool Date::operator <= (Date d) const
{
	return (*this < d) || (*this == d);
}


/*****************************************************************************/


bool Date::operator >= (Date d) const
{
	return (d < *this) || (*this == d);
}


/*****************************************************************************/


std::ostream & operator << (std::ostream & o, Date d)
{
	o << d.getYear() << '/' << d.getMonth() << '/' << d.getDay();
	return o;
}


/*****************************************************************************/


std::istream & operator >> (std::istream & i, Date & d)
{
	char buf[100];
	i >> buf;

	d = Date(buf);
	return i;
}


/*****************************************************************************/
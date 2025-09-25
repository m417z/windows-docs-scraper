# MI_Timestamp structure

## Description

**MI_Timestamp** specifies a timestamp or a specific point in time.

## Members

### `year`

A four digit number representing the year in the form yyyy.

### `month`

A two digit number representing the month in the form mm. (01-12)

### `day`

A two digit number representing the day of the month in the form dd. (01-31)

### `hour`

A two digit number representing the hour on a 24-hour clock in the form hh. (00-23)

### `minute`

A two digit number representing minutes in the form mm. (00-59)

### `second`

A two digit number representing seconds in the form ss. (00-59)

### `microseconds`

A six digit number in the form mmmmmm representing the microseconds. (000000-999999)

### `utc`

The offset from Coordinated Universal Time in minutes. Timezones west of Greenwich use negative numbers while timezones east of Greenwich use positive numbers.
# WS_DATETIME structure

## Description

This structure is used to represent dates and times.

Represents dates and times with values ranging from 12:00:00 midnight,
January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M.,
December 31, 9999 A.D. (C.E.) to an accuracy of 100 nanoseconds.

The functions [WsDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsdatetimetofiletime) and [WsFileTimeToDateTime](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfiletimetodatetime)
can be used to convert a **WS_DATETIME** to and from a FILETIME.

## Members

### `ticks`

The time in 100 nanosecond units, with 0 representing 12:00:00 midnight January 1, Anno Domini (Common Era). The
largest representable value is 3155378975999999999, which corresponds to 100 nanoseconds prior to 12:00:00 midnight
January 1, 10000.

### `format`

The format that is used when representing this time as text.
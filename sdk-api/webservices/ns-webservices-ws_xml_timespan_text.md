# WS_XML_TIMESPAN_TEXT structure

## Description

Represents a time span formatted as the text "[+|-][d?.]HH:mm:ss[.fffffff]"

* d is a series of digits representing the day.
* HH is a two digit number representing the hour of the day, from to 0 to 23.
* mm is a two digit number representing the minute of the hour, from to 0 to 59.
* ss is a two digit number representing the second of the minute, from to 0 to 59.
* fffffff is up to 7 decimal digits representing the fraction of a second.

## Members

### `text`

The base type for all types that derive from [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text).

### `value`

The timespan.
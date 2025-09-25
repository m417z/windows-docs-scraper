# FAX_LOG_LEVEL_ENUM enumeration

## Description

The **FAX_LOG_LEVEL_ENUM** enumeration defines the event logging levels for a logging category.

## Constants

### `fllNONE:0`

The fax server does not log events.

### `fllMIN`

The fax server logs only severe failure events, such as errors.

### `fllMED`

The fax server logs events of moderate severity, as well as severe failure events. This would include errors and warnings.

### `fllMAX`

The fax server logs all events.

## See also

[IFaxEventLogging::get_GeneralEventsLevel](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging-generaleventslevel-vb)

[IFaxEventLogging::get_InboundEventsLevel](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging-inboundeventslevel-vb)

[IFaxEventLogging::get_InitEventsLevel](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging-initeventslevel-vb)

[IFaxEventLogging::get_OutboundEventsLevel](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging-outboundeventslevel-vb)
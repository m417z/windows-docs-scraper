# IFaxActivityLogging::get_LogOutgoing

## Description

The **IFaxActivityLogging::get_LogOutgoing** property is a Boolean value that indicates whether the fax service logs entries for outgoing faxes in the activity log database.

This property is read/write.

## Parameters

## Remarks

If this property is equal to **TRUE**, the fax service logs entries for outgoing fax jobs in the activity log database. If this property is equal to **FALSE**, the fax service does not log entries.

To read or write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxActivityLogging](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxactivitylogging)

[IFaxActivityLogging](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxactivitylogging)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-logging-options)
# IGPMStatusMessage::OperationCode

## Description

Returns a code related to the GPMC operation. The code corresponds to warnings or other errors that occurred during the operation. In the case of warnings, the operation continues. In the case of other errors, the operation stops.

The operation codes are internal identifiers that are defined in Gpmgmt.dll. You can extract a text description of the operation code by using the [Message property](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/igpmstatusmessage-property-methods) of [IGPMStatusMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmessage) or by using [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage).

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMStatusMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmessage)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)
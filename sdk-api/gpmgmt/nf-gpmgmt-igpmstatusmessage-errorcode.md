# IGPMStatusMessage::ErrorCode

## Description

Returns the error that occurred during the GPMC operation. If the operation was interacting with another system component, the error code is typically one returned by that component. Usually this is the first error GPMC hits while executing the operation. This error code is internally mapped to the operation error code returned by the [OperationCode](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmstatusmessage-operationcode) method.

For example, if GPMC calls [LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida) while resolving the destination of a security group in a GPO import operation, and **LookupAccountSid** returns **E_ACCESSDENIED**, then the error code for the message will be **E_ACCESSDENIED** and the operation code of the message will be STATUS_ENTRY_DEST_UNRESOLVED.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMStatusMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmessage)

[IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection)
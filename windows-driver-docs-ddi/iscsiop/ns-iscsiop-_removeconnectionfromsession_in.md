# _RemoveConnectionFromSession_IN structure

## Description

The RemoveConnectionFromSession_IN structure holds the input data for the [RemoveConnectionFromSession](https://learn.microsoft.com/windows-hardware/drivers/storage/removeconnectionfromsession) method, which is used to remove a connection from a session.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

### `UniqueConnectionId`

A 64-bit integer that uniquely identifies the connection. Do not confuse this value with the connection ID (CID).

## Remarks

You must implement this class.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[RemoveConnectionFromSession](https://learn.microsoft.com/windows-hardware/drivers/storage/removeconnectionfromsession)
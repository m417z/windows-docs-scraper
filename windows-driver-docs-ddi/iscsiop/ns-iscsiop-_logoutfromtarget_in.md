# _LogoutFromTarget_IN structure

## Description

The LogoutFromTarget_IN structure holds the input data for the [LogoutFromTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logoutfromtarget) method, which is used to log out from an iSCSI target.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[LogoutFromTarget_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_logoutfromtarget_out)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)
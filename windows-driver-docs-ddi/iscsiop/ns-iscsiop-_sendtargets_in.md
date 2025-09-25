# _SendTargets_IN structure

## Description

The SendTargets_IN structure holds the input data for the [SendTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/sendtargets) method.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The LoginToTarget and AddConnectionToSession methods both return this value in their UniqueSessionId parameter.

### `SendTargetsText`

The authentication key text in the PDU.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[SendTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/sendtargets)

[SendTargets_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_sendtargets_out)
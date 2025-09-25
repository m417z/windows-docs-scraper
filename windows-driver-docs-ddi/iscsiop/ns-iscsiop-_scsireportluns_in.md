# _ScsiReportLuns_IN structure (iscsiop.h)

## Description

The ScsiReportLuns_IN structure holds the input data for the [ScsiReportLuns](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6) method.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their *UniqueSessionId* parameter.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[ScsiReportLuns](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6)

[ScsiReportLuns_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsireportluns_out)
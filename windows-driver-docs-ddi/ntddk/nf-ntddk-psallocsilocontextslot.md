## Description

This routine allocates a slot that can be used to insert, retrieve, and delete an object in all silos.

## Parameters

### `Reserved` [in]

This parameter is reserved for future use and **must be set to zero**.

### `ReturnedContextSlot` [out]

A pointer to a caller-allocated variable that receives the newly allocated slot index. This parameter is required and it cannot be **NULL**.

## Return value

The following NT status codes are returned.

| Return code | Description |
|--|--|
| **STATUS_INSUFFICIENT_RESOURCES** | There are no more slots available in the system. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

Use of this API is uncommon because all silo monitors are assigned a storage slot when calling the [PsRegisterSiloMonitor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psregistersilomonitor) routine. That slot can be retrieved with the [PsGetSiloMonitorContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetsilomonitorcontextslot) routine and used by a driver for its context operations.

## See also

[PsFreeSiloContextSlot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psfreesilocontextslot)
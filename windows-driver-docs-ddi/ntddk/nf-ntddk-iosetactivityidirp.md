## Description

The IoSetActivityIdIrp routine associates an activity ID with an IRP.

## Parameters

### `Irp` [in]

The IRP to associate the activity ID with.

### `Guid` [in, optional]

A pointer to the GUID that represents the ID to store in the IRP. If NULL, IoSetActivityIdIrp attempts to retrieve the activity ID from the current thread if it was the thread that originally issued the request.

## Return value

IoSetActivityIdIrp returns STATUS_SUCCESS if the call is successful. Possible error return values include the following.

| Return code | Description |
|--|--|
| **STATUS_NOT_SUPPORTED** | No GUID was provided and the ETW activity ID was unavailable. |
| **STATUS_UNSUCCESSFUL** | The I/O tracing provider has not been enabled on the IRP. |

## Remarks

Drivers should use IoSetActivityIdIrp only on IRPs that have been allocated using [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp) (and freed using [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)). Otherwise, memory leakage may result.
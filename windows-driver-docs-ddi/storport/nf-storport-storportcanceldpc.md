# StorPortCancelDpc function

## Description

**StorPortCancelDpc** attempts to cancel the execution of a StorPort deferred procedure call (DPC).

## Parameters

### `HwDeviceExtension`

Pointer to the hardware device extension for the host bus adapter (HBA).

### `Dpc`

Pointer to the [STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc) DPC object to be cancelled.

### `ReturnValue`

Pointer to a **BOOLEAN** in which this function will return one of the following values.

| Return Value | Description |
| --- | --- |
| TRUE | The specified *Dpc* was successfully removed from the system's DPC queue. |
| FALSE | The specified *Dpc* was not removed from the system's DPC queue. |

## Return value

This function returns one of the following status codes.

| Return Code | Description |
| --- | --- |
| STOR_STATUS_INVALID_PARAMETER | *Dpc* or *ReturnValue* are NULL. |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | This function completed successfully. Use the value returned in *ReturnValue* to determine whether the Dpc was removed from the queue. |

## Remarks

If the specified StorPort DPC is in the DPC queue, **StorPortCancelDpc** removes it from the queue, canceling a call to the associated DPC routine. If it is not in the queue, it was either executing or had finished executing, and therefore could not be removed.

This routine is implemented using inline function definitions, so that miniport drivers that use it do not have to link to libraries that are dependent on the version of the operating system. Miniport drivers can use this routine without sacrificing backward compatibility with versions of the operating system that do not support DPCs in storage miniport drivers.

## See also

[STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc)

[StorPortInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc)

[StorPortIssueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportissuedpc)
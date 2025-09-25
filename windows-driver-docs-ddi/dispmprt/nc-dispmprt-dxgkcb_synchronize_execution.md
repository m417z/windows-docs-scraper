# DXGKCB_SYNCHRONIZE_EXECUTION callback function

## Description

The **DxgkCbSynchronizeExecution** function synchronizes a specified function, implemented by the display miniport driver, with the display miniport driver's [DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine) function.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `SynchronizeRoutine` [in]

A pointer to a function, implemented by the display miniport driver, that will be synchronized with *DxgkDdiInterruptRoutine*. The function must conform to the following prototype:

```cpp
BOOLEAN SynchronizeRoutine(PVOID Context);
```

### `Context` [in]

A pointer to a context block, created by the display miniport driver, that will be passed to *SynchronizeRoutine*.

### `MessageNumber` [in]

The number of the interrupt message with which *SynchronizeRoutine* will be synchronized. If the interrupt is line-based, this parameter must be zero.

### `ReturnValue` [out]

A pointer to a Boolean variable that receives the return value of *SynchronizeRoutine*.

## Return value

**DxgkCbSynchronizeExecution** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|One of the parameters is invalid.|
|STATUS_UNSUCCESSFUL|The function was unable to synchronize execution, possibly because the interrupt had not been connected yet.|

## See also

[DxgkDdiInterruptRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_interrupt_routine)

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)
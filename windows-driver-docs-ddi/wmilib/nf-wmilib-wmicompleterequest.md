# WmiCompleteRequest function

## Description

The **WmiCompleteRequest** routine indicates that a driver has finished processing a WMI request in a *DpWmiXxx* routine.

## Parameters

### `DeviceObject` [in]

A pointer to the driver's [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Irp` [in, out]

A pointer to the IRP.

### `Status` [in]

Specifies the status to return for the IRP.

### `BufferUsed` [in]

Specifies the number of bytes needed in the buffer passed to the driver's *DpWmiXxx* routine. If the buffer is too small, the driver sets *Status* to STATUS_BUFFER_TOO_SMALL and sets *BufferUsed* to the number of bytes needed for the data to be returned. If the buffer passed is large enough, the driver sets *BufferUsed* to the number of bytes actually used.

### `PriorityBoost` [in]

Specifies a system-defined constant by which to increment the run-time priority of the original thread that requested the operation. WMI calls [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) with *PriorityBoost* when it completes the IRP. See **IoCompleteRequest** for more information on *PriorityBoost*.

## Return value

**WmiCompleteRequest** returns the value that was passed to it in the *Status* parameter unless *Status* was set to STATUS_BUFFER_TOO_SMALL. If the driver set *Status* equal to STATUS_BUFFER_TOO_SMALL, **WmiCompleteRequest** builds a WNODE_TOO_SMALL structure and returns STATUS_SUCCESS. The return value from **WmiCompleteRequest** should be returned by the driver in its *DpWmiXxx* routine.

## Remarks

A driver calls **WmiCompleteRequest** from a *DpWmiXxx* routine after it finishes all other processing in that routine, or after the driver finishes all processing for a pending IRP. **WmiCompleteRequest** fills in a **WNODE_*XXX*** with any data returned by the driver and calls **IoCompleteRequest** to complete the IRP.

A driver should always return the return value from **WmiCompleteRequest** in its *DpWmiXxx* routine.

A driver must not call **WmiCompleteRequest** from its [DpWmiQueryRegInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback) routine.

## See also

[DpWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_execute_method_callback)

[DpWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_function_control_callback)

[DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_datablock_callback)

[DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback)

[DpWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_datablock_callback)

[DpWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_dataitem_callback)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
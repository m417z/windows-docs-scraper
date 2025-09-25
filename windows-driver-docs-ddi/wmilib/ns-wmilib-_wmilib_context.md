# _WMILIB_CONTEXT structure

## Description

The **WMILIB_CONTEXT** structure provides registration information for a driver's data blocks and event blocks and defines entry points for the driver's WMI library callback routines.

## Members

### `GuidCount`

Specifies the number of blocks registered by the driver.

### `GuidList`

Pointer to an array of **GuidCount** [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structures that contain registration information for each block.

### `QueryWmiRegInfo`

Pointer to the driver's [DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback) routine, which is a required entry point for drivers that call WMI library support routines.

### `QueryWmiDataBlock`

Pointer to the driver's [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_datablock_callback) routine, which is a required entry point for drivers that call WMI library support routines.

### `SetWmiDataBlock`

Pointer to the driver's [DpWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_datablock_callback) routine, which is an optional entry point for drivers that call WMI library support routines. If the driver does not implement this routine, it must set this member to **NULL**. In this case, WMI returns STATUS_WMI_READ_ONLY to the caller in response to any [IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance) request.

### `SetWmiDataItem`

Pointer to the driver's [DpWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_dataitem_callback) routine, which is an optional entry point for drivers that call WMI library support routines. If the driver does not implement this routine, it must set this member to **NULL**. In this case, WMI returns STATUS_WMI_READ_ONLY to the caller in response to any [IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item) request.

### `ExecuteWmiMethod`

Pointer to the driver's [DpWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_execute_method_callback) routine, which is an optional entry point for drivers that call WMI library support routines. If the driver does not implement this routine, it must set this member to **NULL**. In this case, WMI returns STATUS_INVALID_DEVICE_REQUEST to the caller in response to any [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request.

### `WmiFunctionControl`

Pointer to the driver's [DpWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_function_control_callback) routine, which is an optional entry point for drivers that call WMI library support routines. If the driver does not implement this routine, it must set this member to **NULL**. In this case, WMI returns STATUS_SUCCESS to the caller in response to any **IRP_MN_ENABLE_*XXX*** or **IRP_MN_DISABLE_*XXX*** request.

## Remarks

A driver that handles WMI IRPs by calling WMI library support routines stores an initialized **WMILIB_CONTEXT** structure (or a pointer to such a structure) in its device extension. A driver can use the same **WMILIB_CONTEXT** structure for multiple device objects if each device object supplies the same set of data blocks.

When the driver receives an [IRP_MJ_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-system-control) request, it calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) with a pointer to its **WMILIB_CONTEXT** structure, a pointer to its device object, and a pointer to the IRP. **WmiSystemControl** determines whether the IRP contains a WMI request and, if so, handles the request by calling the driver's appropriate *DpWmiXxx* routine.

Memory for this structure can be allocated from paged pool.

## See also

[DpWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_execute_method_callback)

[DpWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_function_control_callback)

[DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_datablock_callback)

[DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback)

[DpWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_datablock_callback)

[DpWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_dataitem_callback)

[WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
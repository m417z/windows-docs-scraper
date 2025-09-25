# WmiSystemControl function

## Description

The **WmiSystemControl** routine is a dispatch routine for drivers that use [WMI library support routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to handle WMI IRPs.

## Parameters

### `WmiLibInfo` [in]

A pointer to a [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that contains registration information for a driver's data blocks and event blocks and defines entry points for the driver's WMI library callback routines.

### `DeviceObject` [in]

A pointer to the driver's [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Irp` [in, out]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp).

### `IrpDisposition` [out]

A pointer to an enumeration value of type **SYSCTL_IRP_DISPOSITION** that indicates how the IRP was handled. **WmiSystemControl** always sets this value, even when it returns a non-success NTSTATUS code.

**SYSCTL_IRP_DISPOSITION** is an enumeration in Wmilib.h and contains the following values:

#### IrpProcessed

The IRP was processed and possibly completed. If the driver's *DpWmi*Xxx routine called by **WmiSystemControl** did not complete the IRP, the driver must call [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) to complete the IRP after **WmiSystemControl** returns.

#### IrpNotCompleted

The IRP was processed but not completed, either because WMI detected an error and set up the IRP with an appropriate error code, or processed an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request. The driver must complete the IRP by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest).

#### IrpNotWmi

The IRP is not a WMI request (that is, WMI does not recognize the IRP's minor code). If the driver handles [IRP_MJ_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-system-control) requests with this **IRP_MN_*XXX***, it should handle the IRP; otherwise, the driver should forward the IRP to the next lower driver. If the driver is the lowest-level driver, then it must complete the IRP.

#### IrpForward

The IRP is targeted to another device object (that is, the device object pointer at **Parameters.WMI.ProviderId** in the IRP does not match the pointer passed by the driver in its call to [IoWMIRegistrationControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiregistrationcontrol)). The driver must forward the IRP to the next lower driver. If the driver is the lowest-level driver, then it must complete the IRP.

## Return value

**WmiSystemControl** returns STATUS_SUCCESS or one of the following error codes:

## Remarks

When a driver receives an **IRP_MJ_SYSTEM_CONTROL** request with a WMI IRP minor code, it calls **WmiSystemControl** with a pointer to the driver's **WMILIB_CONTEXT** structure, a pointer to its device object, and a pointer to the IRP. The **WMILIB_CONTEXT** structure contains registration information for the driver's data blocks and event blocks and defines entry points for its WMI library callback routines.

**WmiSystemControl** confirms that the IRP is a WMI request and determines whether the block specified by the request is valid for the driver. If so, it processes the IRP by calling the appropriate *DpWmi*Xxx entry point in the driver's **WMILIB_CONTEXT** structure. WMI is running at IRQL PASSIVE_LEVEL when it calls the driver's *DpWmi*Xxx routine.

A driver must be running at IRQL PASSIVE_LEVEL when it forwards an **IRP_MJ_SYSTEM_CONTROL** request to the next-lower driver.

## See also

[DpWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_execute_method_callback)

[DpWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_function_control_callback)

[DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_datablock_callback)

[DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback)

[DpWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_datablock_callback)

[DpWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_set_dataitem_callback)

[IRP_MJ_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-system-control)

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)
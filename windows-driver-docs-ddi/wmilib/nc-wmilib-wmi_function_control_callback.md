# WMI_FUNCTION_CONTROL_CALLBACK callback function

## Description

The *DpWmiFunctionControl* routine enables or disables notification of events, and enables or disables data collection for data blocks that the driver registered as expensive to collect. This routine is optional.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Irp` [in]

Pointer to the IRP.

### `GuidIndex` [in]

Specifies the data block by supplying a zero-based index into the list of GUIDs that the driver provided in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passed to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol).

### `Function` [in]

Specifies what to enable or disable. **WmiEventControl** indicates an event, and **WmiDataBlockControl** indicates data collection for a block that was registered as expensive to collect (that is, a block for which the driver set WMIREG_FLAG_EXPENSIVE in **Flags** of the [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure used to register the block).

### `Enable` [in]

Specifies **TRUE** to enable the event or data collection, or **FALSE** to disable it.

## Return value

*DpWmiFunctionControl* returns STATUS_SUCCESS or an appropriate error status such as:

## Remarks

WMI calls a driver's *DpWmiFunctionControl* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to one of the following requests:

[IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection)

[IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection)

[IRP_MN_ENABLE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-events)

[IRP_MN_DISABLE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-events)

If a driver implements a *DpWmiFunctionControl* routine, the driver must place the routine's address in the **WmiFunctionControl** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol). If a driver does not implement a *DpWmiFunctionControl* routine, it must set **WmiFunctionControl** to **NULL**. In the latter case, WMI returns STATUS_SUCCESS to the caller.

The driver is responsible for validating all input arguments. Specifically, the driver must do the following:

* Verify that the *GuidIndex* value is between zero and GuidCount-1, based on the **GuidCount** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure.
* Verify that the driver has not flagged the specified data block for removal. If the driver recently specified the WMIREG_FLAG_REMOVE_GUID flag in a [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure that is contained in a **WMILIB_CONTEXT** structure, it is possible for an additional request to arrive before the removal occurs.

It is unnecessary for the driver to check whether events or data collection are already enabled for a block, because WMI sends a single enable request when the first data consumer enables the block, and it sends a single disable request when the last data consumer disables the block. WMI will not call *DpWmiFunctionControl* to enable a block without an intervening call to disable it.

After enabling or disabling the event or data collection for the block, the driver calls [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) to complete the request.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection)

[IRP_MN_DISABLE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-events)

[IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection)

[IRP_MN_ENABLE_EVENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-events)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
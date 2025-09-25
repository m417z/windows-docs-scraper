# WMI_SET_DATAITEM_CALLBACK callback function

## Description

The *DpWmiSetDataItem* routine changes a single data item in an instance of a data block. This routine is optional.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Irp` [in]

Pointer to the IRP.

### `GuidIndex` [in]

Specifies the data block by supplying a zero-based index into the list of GUIDs that the driver provided in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passed to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol).

### `InstanceIndex` [in]

If the block specified by *GuidIndex* has multiple instances, *InstanceIndex* is a zero-based value that specifies the instance.

### `DataItemId` [in]

Specifies the ID of the data item to set.

### `BufferSize` [in]

Specifies the size in bytes of the buffer at *Buffer*.

### `Buffer` [in]

Pointer to a buffer that contains the new value for the data item.

## Return value

*DpWmiSetDataItem* returns STATUS_SUCCESS or an appropriate error code such as the following:

## Remarks

WMI calls a driver's *DpWmiSetDataItem* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to an [IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item) request.

Do not implement *DpWmiSetDataItem* unless you are sure that a system-supplied user-mode component requires this capability. If you implement a *DpWmiSetDataItem* routine, the driver must place the routine's address in the **SetWmiDataItem** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol). If you do not implement a *DpWmiSetDataItem* routine, the driver must set **SetWmiDataItem** to **NULL**. In the latter case, WMI returns STATUS_READ_ONLY to the caller.

The driver is responsible for validating all input arguments. Specifically, the driver must do the following:

* Verify that the *GuidIndex* value is between zero and GuidCount-1, based on the **GuidCount** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure.
* Verify that the driver has not flagged the specified data block for removal. If the driver recently specified the WMIREG_FLAG_REMOVE_GUID flag in a [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure that is contained in a **WMILIB_CONTEXT** structure, it is possible for a set request to arrive before the removal occurs.
* Verify that the *InstanceIndex* value is within the range of instance indexes that are supported by the driver for the data block.
* Verify that the *DataItemId* value is within the range of data item identifiers that are supported by the driver for the data block.
* Verify that *Buffer* and *BufferSize* describe a valid-sized data item, and that the contents of the buffer are valid for the data item.
* Verify that the specified data item is one for which the driver allows caller-initiated modifications. In other words, the driver should not allow modifications to data items that you intended to be read-only.

Do not assume the thread context is that of the initiating user-mode application—a higher-level driver might have changed it.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
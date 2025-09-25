# WMI_SET_DATABLOCK_CALLBACK callback function

## Description

The *DpWmiSetDataBlock* routine changes all data items in a single instance of a data block. This routine is optional.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Irp` [in]

Pointer to the IRP.

### `GuidIndex` [in]

Specifies the data block by its zero-based index into the list of GUIDs provided by the driver in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passed to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol).

### `InstanceIndex` [in]

If the block specified by *GuidIndex* has multiple instances, *InstanceIndex* specifies the instance.

### `BufferSize` [in]

Specifies the size in bytes of the buffer at *Buffer*.

### `Buffer` [in]

Pointer to a buffer that contains new values for the instance.

## Return value

*DpWmiSetDataBlock* returns STATUS_SUCCESS or an appropriate error status such as the following:

If the driver cannot complete the request immediately, it can return STATUS_PENDING.

## Remarks

WMI calls a driver's *DpWmiSetDataBlock* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to an [IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance) request.

The driver is responsible for validating all input arguments. Specifically, the driver must do the following:

* Verify that the *GuidIndex* value is between zero and GuidCount-1, based on the **GuidCount** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure.
* Verify that the driver has not flagged the specified data block for removal. If the driver recently specified the WMIREG_FLAG_REMOVE_GUID flag in a [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure that is contained in a **WMILIB_CONTEXT** structure, it is possible for a set request to arrive before the removal occurs.
* Verify that the *InstanceIndex* value is within the range of instance indexes that are supported by the driver for the data block.
* Verify that *Buffer* and *BufferSize* describe a valid-sized data block, including any padding that exists between data items, and that the contents of the buffer are valid for the data block.
* Verify that the specified data block is one for which the driver allows caller-initiated modifications. In other words, the driver should not allow modifications to data blocks that you intended to be read-only.

Do not assume the thread context is that of the initiating user-mode application—a higher-level driver might have changed it.

If a driver implements a *DpWmiSetDataBlock* routine, the driver must place the routine's address in the **SetWmiDataBlock** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol). If a driver does not implement a *DpWmiSetDataBlock* routine, it must set **SetWmiDataBlock** to **NULL**. In the latter case, WMI returns STATUS_READ_ONLY to the caller.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
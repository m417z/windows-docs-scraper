# WMI_QUERY_DATABLOCK_CALLBACK callback function

## Description

The *DpWmiQueryDataBlock* routine returns either a single instance or all instances of a data block. This routine is required.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Irp` [in]

Pointer to the IRP.

### `GuidIndex` [in]

Specifies the data block by supplying a zero-based index into the list of GUIDs that the driver provided in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passed to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol).

### `InstanceIndex` [in]

If *DpWmiQueryDataBlock* is called in response to an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) request, *InstanceIndex* specifies a zero-based index that indicates the instance of the specified data block to be queried. If *DpWmiQueryDataBlock* is called in response to an [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request, *InstanceIndex* is zero.

### `InstanceCount` [in]

If *DpWmiQueryDataBlock* is called in response to an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) request, *InstanceCount* is 1. If *DpWmiQueryDataBlock* is called in response to an [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request, *InstanceCount* is the number of instances to be returned.

### `InstanceLengthArray` [in, out]

Pointer to a caller-supplied, *InstanceCount*-sized array of ULONG elements. The driver fills in each array element to indicate the length of each instance that was returned. If *BufferAvail* is zero, *InstanceLengthArray* is **NULL**.

### `BufferAvail` [in]

Specifies the maximum number of bytes that are available to receive data in the buffer at *Buffer*. If this value is zero, the caller is requesting that the driver specify the required buffer size in its call to [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest). See the Remarks section for more information.

### `Buffer` [out]

Pointer to the buffer to receive instance data. If the buffer is large enough to receive all of the data, the driver writes the instance data to the buffer with each instance aligned on an 8-byte boundary. If the buffer is too small to receive all of the data, the driver calls [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) with *BufferUsed* set to the size required.

## Return value

*DpWmiQueryDataBlock* returns STATUS_SUCCESS or an error status such as the following:

If the driver cannot complete the request immediately, it can return STATUS_PENDING.

## Remarks

WMI calls a driver's *DpWmiQueryDataBlock* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) or [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request. The driver must place the address of its *DpWmiQueryDataBlock* routine in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to **WmiSystemControl**.

The driver is responsible for validating all input arguments. Specifically, the driver must do the following:

* Verify that the *GuidIndex* value is between zero and GuidCount-1, based on the **GuidCount** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure.
* Verify that the driver has not flagged the specified data block for removal. If the driver recently specified the WMIREG_FLAG_REMOVE_GUID flag in a [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure that is contained in a **WMILIB_CONTEXT** structure, it is possible for a query to arrive before the removal occurs.
* Verify that the *InstanceIndex* and *InstanceCount* values, together, specify a number of data block instances that is within the range supported by the driver for the data block. If *InstanceIndex* is nonzero, *InstanceCount* must be 1. If *InstanceIndex* is 0, *InstanceCount* must not be greater than the number of instances supported.
* Verify that the buffer described by *Buffer* and *BufferAvail* is large enough to hold all requested instances of the data block. Each instance must begin on an 8-byte boundary, and additional padding might exist between data items within each instance.

After writing instance data to the buffer, the driver calls [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) to complete the request. If the buffer described by *Buffer* and *BufferAvail* is zero, or is too small to receive all the requested data, the call to **WmiCompleteRequest** must specify STATUS_BUFFER_TOO_SMALL for the *Status* parameter and the required buffer size for the *BufferUsed* parameter.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data)

[IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
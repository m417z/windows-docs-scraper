# WMI_EXECUTE_METHOD_CALLBACK callback function

## Description

The *DpWmiExecuteMethod* routine executes a method associated with a data block. This routine is optional.

## Parameters

### `DeviceObject` [in]

Pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `Irp` [in]

Pointer to the IRP.

### `GuidIndex` [in]

Specifies the data block by supplying a zero-based index into the list of GUIDs that the driver provided in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passed to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol).

### `InstanceIndex` [in]

If the block specified by *GuidIndex* has multiple instances, *InstanceIndex* specifies a zero-based index value that identifies the instance.

### `MethodId` [in]

Specifies the ID of the method to execute. The driver defines the method ID as an item in a data block.

### `InBufferSize` [in]

Indicates the size in bytes of the input data. If there is no input data, *InBufferSize* is zero.

### `OutBufferSize` [in]

Indicates the number of bytes available in the buffer for output data.

### `Buffer` [in, out]

Pointer to a buffer that holds input data, if any, and receives output data, if any, for the method. If the buffer is too small to receive all of the output data, the driver returns STATUS_BUFFER_TOO_SMALL and calls [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) with the size required.

## Return value

*DpWmiExecuteMethod* returns STATUS_SUCCESS or an appropriate error code such as the following:

## Remarks

WMI calls a driver's *DpWmiExecuteMethod* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to an [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request.

If a driver implements a *DpWmiExecuteMethod* routine, the driver must place the routine's address in the **ExecuteWmiMethod** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol). If a driver does not implement a *DpWmiExecuteMethod* routine, it must set **ExecuteWmiMethod** to **NULL**. In the latter case, WMI returns STATUS_INVALID_DEVICE_REQUEST to the caller in response to any **IRP_MN_EXECUTE_METHOD** request.

The driver is responsible for validating all input arguments. Specifically, the driver must do the following:

* Verify that the *GuidIndex* value is between zero and GuidCount-1, based on the **GuidCount** member of the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure.
* Verify that the driver has not flagged the specified data block for removal. If the driver recently specified the WMIREG_FLAG_REMOVE_GUID flag in a [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure that is contained in a **WMILIB_CONTEXT** structure, it is possible for an additional request to arrive before the removal occurs.
* Verify that the *InstanceIndex* value is within the range of instance indexes that are supported by the driver for the data block.
* Verify that the method identifier supplied by *MethodId* is a valid identifier for the specified data block, and that the caller is allowed to execute the method.
* Verify that *Buffer* and *InBufferSize* describe a buffer that is large enough to contain the specified method's input parameters, including padding if necessary, and verify that the input parameters are valid.
* Verify that *Buffer* and *OutBufferSize* describe a buffer that is large enough to receive the specified method's output data, including padding if necessary.

Do not assume the thread context is that of the initiating user-mode application—a higher-level driver might have changed it.

If the specified method performs an operation that causes data loss, such as fetching and resetting the contents of a set of counters, the driver should validate the output buffer size before performing the operation. That way, the driver can return STATUS_BUFFER_TOO_SMALL and allow the caller to resubmit the request with a larger buffer, without prematurely resetting the counters.

After executing the method and writing any output data to the buffer, the driver calls [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) to complete the request.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)
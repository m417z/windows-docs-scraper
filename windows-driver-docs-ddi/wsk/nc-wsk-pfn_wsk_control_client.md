# PFN_WSK_CONTROL_CLIENT callback function

## Description

The **WskControlClient** function performs control operations on a WSK client object.

## Parameters

### `Client` [in]

A pointer to a [WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through the *WskProviderNpi* parameter of the  [WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `ControlCode` [in]

The control operation that is being performed. A WSK application can specify one of the following control codes:

#### WSK_TRANSPORT_LIST_QUERY

Retrieve a list of available network transports.

#### WSK_TRANSPORT_LIST_CHANGE

Receive notification of a change to the list of available network transports.

#### WSK_CACHE_SD

Obtain a cached copy of a security descriptor.

#### WSK_RELEASE_SD

Release a cached copy of a security descriptor.

#### WSK_SET_STATIC_EVENT_CALLBACKS

Enable specified event callback functions automatically on all sockets.

#### WSK_TDI_DEVICENAME_MAPPING

Map combinations of address family, socket type, and protocol to device names of [TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transports.

#### WSK_TDI_BEHAVIOR

Control whether the WSK subsystem will divert network I/O to [TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transports.

### `InputSize` [in]

The number of bytes of data in the buffer that is pointed to by the *InputBuffer* parameter.

### `InputBuffer` [in, optional]

A caller-allocated buffer that supplies any input data that is required to perform the specified control operation. If no input data is required for the specified control operation, the WSK application should set this parameter to **NULL** and set the *InputSize* parameter to zero.

### `OutputSize` [in]

The size, in bytes, of the buffer that is pointed to by the *OutputBuffer* parameter.

### `OutputBuffer` [out, optional]

A caller-allocated buffer that receives any output data that is returned by the specified control operation. If no output data is returned by the specified control operation, the WSK application should set this parameter to **NULL** and set the *OutputSize* parameter to zero.

### `OutputSizeReturned` [out, optional]

A pointer to a ULONG-typed variable that receives the number of bytes of data that is returned in the buffer that is pointed to by the *OutputBuffer* parameter. A WSK application should set this pointer to **NULL** except when all of the following are true:

* The *Irp* parameter is **NULL**.
* The operation that is being performed returns output data in the buffer that is pointed to by the *OutputBuffer* parameter.
* The number of bytes of output data that is returned by the operation that is being performed is unknown.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the control operation asynchronously. For more information about using IRPs with WSK functions, see [Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

This parameter is required, is optional, or must be **NULL**, depending on the particular client control operation that is being performed. For more information about the requirements for this parameter for each of the supported client control operations, see [WSK Client Control Operations](https://learn.microsoft.com/windows-hardware/drivers/network/performing-control-operations-on-a-client-object).

## Return value

**WskControlClient** returns one of the following NTSTATUS codes:

|Return code|Description|
|--- |--- |
|**STATUS_SUCCESS**|The control operation completed successfully. If the WSK application specified a pointer to an IRP in the _Irp_ parameter, the IRP will be completed with success status.|
|**STATUS_PENDING**|The WSK subsystem could not complete the control operation immediately. The WSK subsystem will complete the IRP after it has completed the control operation. The status of the control operation will be returned in the **IoStatus.Status** field of the IRP.|
|**STATUS_BUFFER_OVERFLOW**|The output buffer is not large enough to contain the returned data. The variable that is pointed to by the _OutputSizeReturned_ parameter contains the required buffer size.|
|**Other status codes**|An error occurred. The IRP will be completed with failure status.|

## Remarks

For more information about how the input and output buffers are used for each client control operation, see [WSK Client Control Operations](https://learn.microsoft.com/windows-hardware/drivers/network/performing-control-operations-on-a-client-object).

If the **WskControlClient** function returns STATUS_PENDING, any buffers that are pointed to by the *InputBuffer* parameter or the *OutputBuffer* parameter must remain valid until the IRP is completed. If the WSK application allocated the buffers with one of the **ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding **ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the buffers on the stack, it cannot return from the function that calls the **WskControlClient** function until after the IRP is completed.

**Note** TDI will not be supported in Microsoft Windows versions after Windows Vista. Use [Windows Filtering Platform](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) or [Winsock Kernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) instead.

## See also

[WSK Client Control Operations](https://learn.microsoft.com/windows-hardware/drivers/network/performing-control-operations-on-a-client-object)

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch)

[WSK_PROVIDER_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_npi)

[WSK_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_transport)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)
# FN_VMB_SERVER_CHANNEL_INIT_SET_VMBUS_HANDLE callback function

## Description

The **VmbServerChannelInitSetVmbusHandle** function associates an instance of VMBus with this channel.

## Parameters

### `Channel`

A handle for a channel.

### `VmbusHandle`

A kernel mode handle to the VMBus vdev of the partition.

## Return value

Returns STATUS_SUCCESS if the operation is successful. Otherwise, returns an appropriate NTSTATUS error code.

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_VMBUS_HANDLE FnVmbServerChannelInitSetVmbusHandle;

// Definition

NTSTATUS FnVmbServerChannelInitSetVmbusHandle
(
	VMBCHANNEL Channel
	HANDLE VmbusHandle
)
{...}

```

## Remarks

The VMBus instance was previously initialized for the specific guest virtual machine. Therefore, invoking this function identifies the child virtual machine to which this channel is offered.

Obtain a value for the *VmbusHandle* parameter by using the [VmbConvertVmbusHandleToKernelHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbconvertvmbushandletokernelhandle) function.

This function can be called while running in any thread context.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbConvertVmbusHandleToKernelHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbconvertvmbushandletokernelhandle)
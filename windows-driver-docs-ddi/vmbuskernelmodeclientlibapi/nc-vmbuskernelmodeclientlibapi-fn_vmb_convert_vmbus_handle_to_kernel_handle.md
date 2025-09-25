# FN_VMB_CONVERT_VMBUS_HANDLE_TO_KERNEL_HANDLE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbConvertVmbusHandleToKernelHandle** function converts the user mode VMBus handle to kernel mode handle.

## Parameters

### `VmbusHandle`

The user-mode handle to convert. This must have been was opened in the virtual machine worker process.

### `KernelHandle`

The kernel handle that references the same object as the *VmbusHandle* value.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CONVERT_VMBUS_HANDLE_TO_KERNEL_HANDLE FnVmbConvertVmbusHandleToKernelHandle;

// Definition

NTSTATUS FnVmbConvertVmbusHandleToKernelHandle
(
	HANDLE VmbusHandle
	PHANDLE KernelHandle
)
{...}

```

## Remarks

The
caller is responsible for closing the kernel handle.

Because the *VmbusHandle* parameter is a user-mode
handle, this function must be called in the context of the user-mode process which
opened the VMBus handle.

 Calling this function is often immediately followed by calling
the [VmbServerChannelInitSetVmbusHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetvmbushandle) function.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbServerChannelInitSetVmbusHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetvmbushandle)
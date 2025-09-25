# FN_VMB_CHANNEL_SET_POINTER callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelSetPointer** function saves an arbitrary pointer in a channel
context.

## Parameters

### `Channel`

A handle for a channel.

### `Pointer`

Arbitrary pointer to save in the channel's context.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SET_POINTER FnVmbChannelSetPointer;

// Definition

VOID FnVmbChannelSetPointer
(
	VMBCHANNEL Channel
	__drv_aliasesMem PVOID Pointer
)
{...}

```

## Remarks

 This is intended to be a more efficient way for a client driver to retrieve client driver's context. For more information, see the [VmbChannelGetPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelgetpointer) function.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelGetPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelgetpointer)
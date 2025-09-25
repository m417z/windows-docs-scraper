# FN_VMB_CHANNEL_GET_MMIO_SPACE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelGetMmioSpace** function retrieves the kernel virtual address of the MMIO space allocated to a channel. This MMIO space is reserved via [**VmbServerChannelInitSetMmioMegabytes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_mmio_megabytes). This function is only valid after the open channel callback has been received.

## Parameters

### `Channel`

A handle for the channel. Allocated by [**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate).

### `MmioAddress`

A pointer to a **PVOID** to fill with the MMIO physical address.

### `MmioSize`

A pointer to the returned size of the MMIO space.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_GET_MMIO_SPACE FnVmbChannelGetMmioSpace;

// Definition

VOID FnVmbChannelGetMmioSpace
(
	VMBCHANNEL Channel
	UINT64 *MmioAddress
	UINT64 *MmioSize
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[**VmbServerChannelInitSetMmioMegabytes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_server_channel_init_set_mmio_megabytes)

[**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate)
# FN_VMB_SERVER_CHANNEL_INIT_SET_MMIO_MEGABYTES callback function

## Description

The **VmbServerChannelInitSetMmioMegabytes** function specifies the amount, megabytes, of guest memory-mapped I/O (MMIO) space to reserve for the device.

## Parameters

### `Channel`

A handle for a channel.

### `MmioMegabytes`

The amount of MMIO space, in megabytes, to reserve.

### `MmioMegabytesOptional`

The amount of extra optional MMIO space, in megabytes, to reserve.

## Return value

**VmbServerChannelInitSetMmioMegabytes** returns the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER** | Both *MmioMegabytes* and *MmioMegabytesOptional* have a value of zero (0). One of these parameters must be greater than zero |

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_MMIO_MEGABYTES FnVmbServerChannelInitSetMmioMegabytes;

// Definition

NTSTATUS FnVmbServerChannelInitSetMmioMegabytes
(
	VMBCHANNEL Channel
	UINT16 MmioMegabytes
	UINT16 MmioMegabytesOptional
)
{...}

```

## Remarks

This function exists as a convenience for driver creators. Everything it does could be done by interacting the with the guest plug-and-play manager and requesting memory-mapped I/O space directly. It is a common requirement that the Windows and Linux VMBus drivers have the capacity to reserve MMIO space on behalf of the client. This function allows the server endpoint to suggest the right amount of MMIO space to reserve.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also
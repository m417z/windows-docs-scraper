# FN_VMB_CHANNEL_PACKET_GET_EXTERNAL_DATA callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelPacketGetExternalData** function gets any external
Memory Descriptor Lists (MDLs) associated with a packet during packet processing.

## Parameters

### `PacketCompletionContext`

A handle that identifies the incoming packet and is used to refer to the packet
once processing is finished.

### `Flags`

Flags that control how the MDL is mapped. The possible flag values are:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_PACKET_EXTERNAL_DATA_FLAG_READ_ONLY** | Map MDL as read-only. |

### `Mdl`

 A pointer to the mapped MDL.

## Return value

**VmbChannelPacketGetExternalData** returns a status code. If this function returns STATUS_PENDING,
the caller must return from the packet processing callback, which will be
called again, possibly at a different IRQL, when the external data is ready.
At this point, a call to this function will succeed and return the external
data.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_PACKET_GET_EXTERNAL_DATA FnVmbChannelPacketGetExternalData;

// Definition

NTSTATUS FnVmbChannelPacketGetExternalData
(
	VMBPACKETCOMPLETION PacketCompletionContext
	UINT32 Flags
	PMDL *Mdl
)
{...}

```

## Remarks

Creating an MDL which represents the memory described by this
transaction causes these regions of the virtual machine to be pinned in memory for the remainder of the transaction lifetime. This is what may cause the function to return STATUS_PENDING, because the regions of the
virtual machine may need to be paged in.

 The MDL returned by this function describes memory that is already
locked in place. Therefore, there is no need to call the
[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) function. The MDL will, however, have neither a user-mode virtual
address nor a kernel-mode virtual address. If the driver that calls this function requires a virtual address to manipulate the memory within the virtual machine, that driver must call [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache), or [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe),
and the corresponding unlock function later, like [MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages).
An alternative to using a virtual address would be to just pass the MDL on down to a driver which uses it for direct memory access.

 The driver calling this function is not required to release the MDL. It becomes invalid upon calling the [VmbChannelPacketComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketcomplete) function. The Kernel Mode Client Library (KMCL) later releases it.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)

[VmbChannelPacketComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketcomplete)
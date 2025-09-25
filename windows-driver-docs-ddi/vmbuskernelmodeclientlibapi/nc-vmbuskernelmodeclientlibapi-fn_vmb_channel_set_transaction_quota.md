# FN_VMB_CHANNEL_SET_TRANSACTION_QUOTA callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelSetTransactionQuota** function sets the incoming packet quota.

## Parameters

### `Channel`

A handle for a channel.

### `Quota:`

 The maximum outstanding packet quota. This value must be greater than 0.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SET_TRANSACTION_QUOTA FnVmbChannelSetTransactionQuota;

// Definition

VOID FnVmbChannelSetTransactionQuota
(
	VMBCHANNEL Channel
	UINT32 Quota
)
{...}

```

## Remarks

The incoming packet quota can be set to be lower than the current
outstanding packet count. In that case, no new packets are removed from
the queue until sufficient packets have been completed.

 If the queue is currently blocked due to quota, this operation does not restart it. The queue only restarts once a packet is completed.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also
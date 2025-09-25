# _IRB_RECEIVE_PHY_PACKETS structure

## Description

This structure contains the fields necessary to carry out a ReceivePhyPackets request.

## Members

### `Flags`

Specifies whether a callback should be registered or deactivated. Use REGISTER_PHY_PACKET_NOTIFICATION to register PhyPacketRoutine as the callback. Use DEREGISTER_PHY_PACKET_NOTIFICATION to deactivate any previously registered callbacks.

### `PhyPacketRoutine`

Points to the notification routine for received PHY packets. The following prototype illustrates the notification routine:

```
void PhyPacketRoutine(
    __in PVOID           Context,
    __in ULONG           GenerationCount,
    __in ULARGE_INTEGER  PhyPacket
);
```

| Term | Description |
| --- | --- |
| **Context** | The argument that is specified in the **u.ReceivePhyPackets.PhyPacketContext** parameter when the [REQUEST_RECEIVE_PHY_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) request is sent. |
| **GenerationCount** | The generation count of the bus for this PHY packet. |
| **PhyPacket** | The 64-bit PHY packet that is received from the 1394 bus. |

### `PhyPacketContext`

Specifies the Context argument to be passed to the PhyPacketRoutine.
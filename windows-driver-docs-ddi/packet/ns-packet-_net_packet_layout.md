# _NET_PACKET_LAYOUT structure

## Description

A **NET_PACKET_LAYOUT** structure describes the start of each protocol header in a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Members

### `Layer2HeaderLength`

The length in bytes of the Layer 2 header, or zero if the Layer 2 length is unknown.

### `Layer3HeaderLength`

The length in bytes of the Layer 3 header, or zero if the Layer 3 length is unknown.

### `Layer4HeaderLength`

The length of the Layer 4 header, or zero if the Layer 4 length is unknown.

### `Layer2Type`

An enumeration that specifies a flag from **NET_PACKET_LAYER2_TYPE**.

```c++
typedef enum _NET_PACKET_LAYER2_TYPE
{
    NetPacketLayer2TypeUnspecified,
    NetPacketLayer2TypeNull,
    NetPacketLayer2TypeEthernet,
} NET_PACKET_LAYER2_TYPE;
```

### `Layer3Type`

An enumeration that specifies a flag from **NET_PACKET_LAYER3_TYPE**.

```c++
typedef enum _NET_PACKET_LAYER3_TYPE
{
    NetPacketLayer3TypeUnspecified,
    NetPacketLayer3TypeIPv4UnspecifiedOptions,
    NetPacketLayer3TypeIPv4WithOptions,
    NetPacketLayer3TypeIPv4NoOptions,
    NetPacketLayer3TypeIPv6UnspecifiedExtensions,
    NetPacketLayer3TypeIPv6WithExtensions,
    NetPacketLayer3TypeIPv6NoExtensions,
} NET_PACKET_LAYER3_TYPE;
```

### `Layer4Type`

An enumeration that specifies a flag from NET_PACKET_LAYER4_TYPE.

```c++
typedef enum _NET_PACKET_LAYER4_TYPE
{
    NetPacketLayer4TypeUnspecified,
    NetPacketLayer4TypeTcp,
    NetPacketLayer4TypeUdp,
    NetPacketLayer4TypeIPFragment,
    NetPacketLayer4TypeIPNotFragment,
} NET_PACKET_LAYER4_TYPE;
```

### `Reserved0`

Reserved for system use.

## Remarks

For more info about using this structure, see the **Layout** member of [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## See also
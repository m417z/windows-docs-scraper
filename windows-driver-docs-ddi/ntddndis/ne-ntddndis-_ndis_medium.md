# _NDIS_MEDIUM enumeration

## Description

The **NDIS_MEDIUM** enumeration type identifies the medium types that NDIS drivers support.

## Constants

### `NdisMedium802_3`

Specifies an Ethernet (802.3) network.

### `NdisMedium802_5`

Specifies a Token Ring (802.5) network.

**Note** Not supported in Windows 8 or later.

### `NdisMediumFddi`

Specifies a Fiber Distributed Data Interface (FDDI) network.

**Note** Not supported in Windows Vista/Windows Server 2008 or later.

### `NdisMediumWan`

Specifies a wide area network. This type covers various forms of point-to-point and WAN NICs, as
well as variant address/header formats that must be negotiated between the protocol driver and the
underlying driver after the binding is established.

### `NdisMediumLocalTalk`

Specifies a LocalTalk network.

### `NdisMediumDix`

Specifies an Ethernet network for which the drivers use the DIX Ethernet header format.

### `NdisMediumArcnetRaw`

Specifies an ARCNET network.

**Note** Not supported in Windows Vista/Windows Server 2008 or later.

### `NdisMediumArcnet878_2`

Specifies an ARCNET (878.2) network.

**Note** Not supported in Windows Vista/Windows Server 2008 or later.

### `NdisMediumAtm`

Specifies an ATM network. Connection-oriented client protocol drivers can bind themselves to an
underlying miniport driver that returns this value. Otherwise, legacy protocol drivers bind themselves
to the system-supplied LanE intermediate driver, which reports its medium type as either of
**NdisMedium802_3** or
**NdisMedium802_5**, depending on how the LanE driver is configured by the network
administrator.

### `NdisMediumWirelessWan`

Specifies a wireless network. NDIS 5.X miniport drivers that support wireless LAN (WLAN) or
wireless WAN (WWAN) packets declare their medium as
**NdisMedium802_3** and emulate Ethernet to higher-level NDIS drivers.

**Note** Starting with Windows 7, this media type is supported and can
be used for Mobile Broadband.

### `NdisMediumIrda`

Specifies an infrared (IrDA) network.

### `NdisMediumBpc`

Specifies a broadcast PC network.

### `NdisMediumCoWan`

Specifies a wide area network in a connection-oriented environment.

### `NdisMedium1394`

Specifies an IEEE 1394 (fire wire) network.

**Note** Not supported in Windows Vista/Windows Server 2008 or later.

### `NdisMediumInfiniBand`

Specifies an InfiniBand network.

### `NdisMediumTunnel`

Specifies a tunnel network.

### `NdisMediumNative802_11`

Specifies a native IEEE 802.11 network.

### `NdisMediumLoopback`

Specifies an NDIS loopback network.

### `NdisMediumWiMAX`

Specifies an IEEE 802.16 WiMAX network.

### `NdisMediumIP`

Specifies a generic medium that is capable of sending and receiving raw IP packets.

### `NdisMediumMax`

A maximum value for testing purposes.
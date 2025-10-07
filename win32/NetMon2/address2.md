# ADDRESS2 structure

The **ADDRESS** structure contains a single address of any type of supported addresses.

## Members

**Type**

Address type. Values can be one of the following:

ADDRESS_TYPE_ETHERNET

ADDRESS_TYPE_IP

ADDRESS_TYPE_IP6

ADDRESS_TYPE_IPX

ADDRESS_TYPE_TOKENRING

ADDRESS_TYPE_FDDI

ADDRESS_TYPE_XNS

ADDRESS_TYPE_ANY

ADDRESS_TYPE_ANY_GROUP

ADDRESS_TYPE_FIND_HIGHEST

ADDRESS_TYPE_VINES_IP

ADDRESS_TYPE_LOCAL_ONLY

ADDRESS_TYPE_ATM

ADDRESS_TYPE_1394

**MACAddress**

View of the data expressed as a raw MAC address.

**IPAddress**

View of the data expressed as a raw IP address.

**IP6Address**

View of the data expressed as a raw IP version 6 address.

**IPXRawAddress**

View of the data expressed as a raw IPX address.

**IPXAddress**

View of the data expressed as a decoded IPX address value.

**VinesIPRawAddress**

View of the data expressed as a raw Vines IP address.

**VinesIPAddress**

View of the data expressed as a decoded Vines IP address.

**EthernetSrcAddress**

View of the data expressed as an Ethernet source address.

**EthernetDstAddress**

View of the data expressed as an Ethernet destination address.

**TokenringSrcAddress**

A view of the data as a token ring source address.

**TokenringDstAddress**

A view of the data as a token ring destination address.

**FddiSrcAddress**

View of the data expressed as an FDDI source address.

**FddiDstAddress**

View of the data expressed as an FDDI destination address.

**Flags**

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |


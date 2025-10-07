# MACFRAME union

The **MACFRAME** structure is a union of the most common initial protocols.

## Members

**MacHeader**

Generic pointer to a frame.

**Ethernet**

Ethernet pointer to a frame.

**Tokenring**

Token ring pointer to a frame.

**Fddi**

FDDI pointer to a frame.

## Remarks

This structure is most frequently used as an overlay. To make the properties of the first protocol accessible, cast the frame as the same type as the protocol.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |


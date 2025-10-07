# NETWORKINFO structure

The NETWORKINFO structure describes a NIC.

## Members

**PermanentAddr**

Permanent MAC address.

**CurrentAddr**

Current MAC address.

**OtherAddress**

Other address that support this (for example IP, IPX).

**LinkSpeed**

Link speed, in Mbps.

**MacType**

Media type.

**MaxFrameSize**

Maximum frame size allowed.

**Flags**

This parameter can be one of the following informational flags:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**NETWORKINFO\_FLAGS\_PMODE\_NOT\_SUPPORTED**

| The network card does not support promiscuous mode, meaning that it will only capture traffic which is broadcast in nature or only involves the local machine.<br> |
|

**NETWORKINFO\_FLAGS\_RAS**

| This is a virtual network card that is a RAS (Remote Access Server) connection through a modem or another network card.<br> |
|

**NETWORKINFO\_FLAGS\_REMOTE\_CARD**

| The network card is not on the local computer, but is capturing on a remote machine at the bequest of the local computer.<br> |
|

**NETWORKINFO\_FLAGS\_REMOTE\_NAL**

| Obsolete; do not use.<br> |
|

**NETWORKINFO\_FLAGS\_REMOTE\_NAL\_CONNECTED**

| Obsolete; do not use.<br> |

**TimestampScaleFactor**

For example, a value of 1 indicates 1/1 ms, 10 indicates 1/10 ms, 100 indicates 1/100 ms, and so on.

**NodeName**

Name of remote workstation.

**PModeSupported**

NIC P-mode support indicator.

**Comment**

Adapter comment field.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |


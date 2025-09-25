# DRT_SECURITY_MODE enumeration

## Description

The **DRT_SECURITY_MODE** enumeration defines possible security modes for the DRT. The security mode is specified by a field of the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

## Constants

### `DRT_SECURE_RESOLVE:0`

Nodes must authenticate the keys they publish. Nodes are not required to authenticate themselves when performing searches.

### `DRT_SECURE_MEMBERSHIP:1`

Nodes must authenticate the keys they publish. Nodes must also authenticate themselves when performing searches. Unauthorized nodes cannot search for keys and cannot retrieve the data associated with published keys.

### `DRT_SECURE_CONFIDENTIALPAYLOAD:2`

Nodes must authenticate the keys they publish. Nodes must also authenticate themselves when performing searches. Encryption is required for all data associated with published keys prior to transmission between DRT nodes. Unauthorized nodes cannot search for keys, cannot retrieve the data associated with published keys, and cannot retrieve data by observing network traffic between other DRT nodes.

## Remarks

The more secure a DRT security mode, the more of a computational load exists for nodes participating in the DRT. More bandwidth is also consumed.
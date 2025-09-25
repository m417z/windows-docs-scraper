# IPX_ADDRESS_DATA structure

## Description

The
**IPX_ADDRESS_DATA** structure provides information about a specific adapter to which IPX is bound. Used in conjunction with
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function calls that specify IPX_ADDRESS in the *optname* parameter.

## Members

### `adapternum`

0-based adapter number.

### `netnum`

IPX network number for the associated adapter.

### `nodenum`

IPX node address for the associated adapter.

### `wan`

Specifies whether the adapter is on a wide area network (WAN) link. When **TRUE**, the adapter is on a WAN link.

### `status`

Specifies whether the WAN link is up. **FALSE** indicates that the WAN link is up or the adapter is not on a WAN. Compare with the **wan** member to determine the meaning.

### `maxpkt`

Maximum allowable packet size, excluding the IPX header.

### `linkspeed`

Link speed, returned in 100 byte-per-second increments. For example, a 9600 byte-per-second link would return a value of 96.

## Remarks

Adapter numbers are base zero, so if there are eight adapters on a given computer, they are numbered 0-7. To determine the number of adapters present on the computer, call the
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function with IPX_MAX_ADAPTER_NUM.

## See also

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)
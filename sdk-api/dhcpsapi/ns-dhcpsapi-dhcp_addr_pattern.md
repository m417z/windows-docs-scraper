## Description

The **DHCP_ADDR_PATTERN** structure contains the information regarding the link-layer address/pattern.

## Members

### `MatchHWType`

If **TRUE**, the hardware type member (**HWType**) will be matched; if **FALSE**, the hardware type member is ignored.

### `HWType`

8-bit integer value that specifies the hardware type of the address, specified in the pattern. Currently, only hardware type 1 (Ethernet 10 megabit) is supported as the filtering criterion.

### `IsWildcard`

If **TRUE**, **Pattern** contains a wildcard pattern; if **FALSE**, **Pattern** contains a hardware address.

### `Length`

8-bit integer value that contains the length of the pattern, in bytes.

### `Pattern`

Array of BYTE values that contain the pattern or hardware address.
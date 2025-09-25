# MIB_BOUNDARYROW structure

## Description

The **MIB_BOUNDARYROW** structure contains the IPv4 group address value and mask for a multicast boundary.

## Members

### `dwGroupAddress`

The 32-bit integer representation of the IPv4 group address which, when combined with the corresponding value in **dwGroupMask**, identifies the group range for which the scoped boundary exists.

**Note** Scoped addresses must come from the range 239.*.*.* as specified in [RFC 2365](https://www.ietf.org/rfc/rfc2365.txt).

### `dwGroupMask`

The 32-bit integer representation of the IPv4 group address mask which, when combined with the corresponding value in **dwGroupAddress**, identifies the group range for which the scoped boundary exists.

## Remarks

Note that the *Iprtrmib.h* header file is automatically included in the *Iphlpapi.h* header file. The *Iprtrmib.h* header file should never be used directly.
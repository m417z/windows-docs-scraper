# MIB_IPMCAST_SCOPE structure

## Description

The **MIB_IPMCAST_SCOPE** structure contains a multicast scope name and the associated IPv4 multicast group address and mask that define the scope.

## Members

### `dwGroupAddress`

Type: **DWORD**

A 32-bit integer representation of the IPv4 group address which, when combined with the corresponding value in **dwGroupMask**, identifies the group range for which the multicast scope exists.

**Note** Scoped addresses must come from the range 239.*.*.* as specified in [RFC 2365](https://www.ietf.org/rfc/rfc2365.txt).

### `dwGroupMask`

Type: **DWORD**

A 32-bit integer representation of the IPv4 group address mask which, when combined with the corresponding value in **dwGroupAddress**, identifies the group range for which the multicast scope exists.

### `snNameBuffer`

Type: **WCHAR[256]**

A Unicode character array that contains the text name associated with the multicast scope. The name should be suitable for display to multicast application users.

If no name is specified, the default name is the string representation of the scoped address in **dwGroupAddress** with the address and mask length appended and separated by a slash "/" character, of the form "239.*.*.*.x/y", where **x** is the address length and **y** is the mask length.

### `dwStatus`

Type: **DWORD**

A status value that describes the current status of this row in a MFE scope table.

| Value | Meaning |
| --- | --- |
| 1 | Row has **active** status. |
| 2 | Row has **notInService** status. |
| 3 | Row has **notReady** status. |
| 4 | Row has **createAndGo** status. |
| 5 | Row has **createAndWait** status. |
| 6 | Row has **destroy** status. |

## Remarks

Note that the *Iprtrmib.h* header file is automatically included in the *Iphlpapi.h* header file. The *Iprtrmib.h* header files should never be used directly.
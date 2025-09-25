# RILNETWORKCODE structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILNETWORKCODE.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILNETWORKCODEPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilnetworkcodeparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwExecutor`

This field is unused.

### `dwMCC`

Mobile Country Code, if applicable. For RIL_SYSTEMTYPE_1XRTT and RIL_SYSTEMTYPE_EVDO it is network-dependent whether this value is available; further, the MCC provided by some 3GPP2 networks may not be accurate.

### `dwMNC`

Mobile Network Code. For RIL_SYSTEMTYPE_1XRTT and RIL_SYSTEMTYPE_EVDO it is network-dependent whether this value is available; further, the MCC provided by some 3GPP2 networks may not be accurate.

### `dwSID`

System ID, if applicable. This is available only for RIL_SYSTEMTYPE_1XRTT.

### `dwNID`

Network ID, if applicable. This is available only for RIL_SYSTEMTYPE_1XRTT.

### `dwRI`

Roaming indicator, if applicable. This is available only for RIL_SYSTEMTYPE_1XRTT and RIL_SYSTEMTYPE_EVDO.

## Syntax

```cpp
struct RILNETWORKCODE {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwExecutor;
  DWORD dwMCC;
  DWORD dwMNC;
  DWORD dwSID;
  DWORD dwNID;
  DWORD dwRI;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
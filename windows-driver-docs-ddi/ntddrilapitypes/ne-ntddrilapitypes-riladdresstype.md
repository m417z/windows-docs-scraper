# RILADDRESSTYPE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILADDRESSTYPE.

## Constants

### `RIL_ADDRTYPE_UNKNOWN`

### `RIL_ADDRTYPE_INTERNATIONAL`

### `RIL_ADDRTYPE_NATIONAL`

### `RIL_ADDRTYPE_NETWKSPECIFIC`

### `RIL_ADDRTYPE_SUBSCRIBER`

### `RIL_ADDRTYPE_ALPHANUM`

### `RIL_ADDRTYPE_ABBREV`

### `RIL_ADDRTYPE_IP`

### `RIL_ADDRTYPE_EMAIL`

### `RIL_ADDRTYPE_URI`

### `RIL_ADDRTYPE_MAX`

## Syntax

```cpp
enum RILADDRESSTYPE {
  RIL_ADDRTYPE_UNKNOWN        = 0x00000000,
  RIL_ADDRTYPE_INTERNATIONAL  = 0x00000001,
  RIL_ADDRTYPE_NATIONAL       = 0x00000002,
  RIL_ADDRTYPE_NETWKSPECIFIC  = 0x00000003,
  RIL_ADDRTYPE_SUBSCRIBER     = 0x00000004,
  RIL_ADDRTYPE_ALPHANUM       = 0x00000005,
  RIL_ADDRTYPE_ABBREV         = 0x00000006,
  RIL_ADDRTYPE_IP             = 0x00000007,
  RIL_ADDRTYPE_EMAIL          = 0x00000008

};
```

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))
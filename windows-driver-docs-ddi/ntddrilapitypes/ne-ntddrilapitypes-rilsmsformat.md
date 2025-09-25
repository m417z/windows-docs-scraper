# RILSMSFORMAT enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

The RILSMSFORMAT enumeration has the following values.

## Constants

### `RIL_SMSFORMAT_NONE`

### `RIL_SMSFORMAT_3GPP`

### `RIL_SMSFORMAT_3GPP2`

### `RIL_SMSFORMAT_MAX`

## Syntax

```cpp
enum RILSMSFORMAT  {
  RIL_SMSFORMAT_NONE   = 0,
  RIL_SMSFORMAT_3GPP   = 0x1,
  RIL_SMSFORMAT_3GPP2  = 0x2,
  RIL_SMSFORMAT_MAX    = RIL_SMSFORMAT_3GPP2

};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
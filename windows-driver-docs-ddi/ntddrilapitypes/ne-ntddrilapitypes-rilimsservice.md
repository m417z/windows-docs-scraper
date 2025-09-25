# RILIMSSERVICE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

The RILIMSSERVICE enumeration has the following values.

## Constants

### `RIL_IMS_SERVICE_SMS`

### `RIL_IMS_SERVICE_VOICE`

### `RIL_IMS_SERVICE_VIDEO`

### `RIL_IMS_SERVICE_CUSTOM`

### `RIL_IMS_SERVICE_SUPSVC`

### `RIL_IMS_SERVICE_RCS`

### `RIL_IMS_SERVICE_USSD`

### `RIL_IMS_SERVICE_E_VOICE`

### `RIL_IMS_SERVICE_ALL`

## Syntax

```cpp
enum RILIMSSERVICE  {
  RIL_IMS_SERVICE_SMS     = 0x00000001,
  RIL_IMS_SERVICE_VOICE   = 0x00000002,
  RIL_IMS_SERVICE_VIDEO   = 0x00000004,
  RIL_IMS_SERVICE_CUSTOM  = 0x00000008,
  RIL_IMS_SERVICE_ALL     = 0x0000000F

};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
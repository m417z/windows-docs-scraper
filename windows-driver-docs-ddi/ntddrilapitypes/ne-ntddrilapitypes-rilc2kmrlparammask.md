# RILC2KMRLPARAMMASK enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILC2KMRLPARAMMASK.

## Constants

### `RIL_PARAM_C2KMRL_SERVING`

### `RIL_PARAM_C2KMRL_NID`

### `RIL_PARAM_C2KMRL_SID`

### `RIL_PARAM_C2KMRL_BSID`

### `RIL_PARAM_C2KMRL_BASELAT`

### `RIL_PARAM_C2KMRL_BASELONG`

### `RIL_PARAM_C2KMRL_REFPN`

### `RIL_PARAM_C2KMRL_GPSSECONDS`

### `RIL_PARAM_C2KMRL_PILOTSTRENGTH`

### `RIL_PARAM_C2KRML_ALL`

## Syntax

```cpp
enum RILC2KMRLPARAMMASK {
  RIL_PARAM_C2KMRL_SERVING        = 0x00000001,
  RIL_PARAM_C2KMRL_NID            = 0x00000002,
  RIL_PARAM_C2KMRL_SID            = 0x00000004,
  RIL_PARAM_C2KMRL_BSID           = 0x00000008,
  RIL_PARAM_C2KMRL_BASELAT        = 0x00000010 ,
  RIL_PARAM_C2KMRL_BASELONG       = 0x00000020 ,
  RIL_PARAM_C2KMRL_REFPN          = 0x00000040 ,
  RIL_PARAM_C2KMRL_GPSSECONDS     = 0x00000080 ,
  RIL_PARAM_C2KMRL_PILOTSTRENGTH  = 0x000000100,
  RIL_PARAM_C2KRML_ALL            = 0x000001ff

};
```

## Remarks

Networks will vary, but the following table summarizes which items are returned for typical CDMA networks.

**Serving and neighbor networks** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| Serving | Yes | 0 through 1 | 1 = serving; 0 = non-serving |
| NID | Yes | 0 through 32,767 | 15 bits |
| SID | Yes | 0 through 65,535 | 16 bits |
| BaseStationID | Yes | 0 through 65,535 | 16 bits |
| BaseLat | Yes | 0 through 4,194,303 | Base station latitude in units of 0.25 sec, expressed as a two's-complement signed number with positive numbers signifying north latitudes; 22 bits |
| BaseLong | Yes | 0 through 8,388,607 | Base station longitude in units of 0.25 sec, expressed as a two's-complement signed number with positive numbers signifying east longitude; 23 bits |
| RefPN | Yes | 0 through 511 | 9 bits |
| GPSSeconds | Yes |  | CDMA system time from the "sync channel" when this set was acquired |
| PilotStrength | Yes | 0 through 63 |  |

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
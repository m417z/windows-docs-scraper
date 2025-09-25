# RILUICCAPPTYPE enumeration (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This enumeration describes the RILUICCAPPTYPE.

## Constants

### `RIL_UICCAPPTYPE_UNKNOWN`

### `RIL_UICCAPPTYPE_MF`

### `RIL_UICCAPPTYPE_MF_SIM`

### `RIL_UICCAPPTYPE_MF_RUIM`

### `RIL_UICCAPPTYPE_USIM`

### `RIL_UICCAPPTYPE_CSIM`

### `RIL_UICCAPPTYPE_ISIM`

### `RIL_UICCAPPTYPE_MAX`

## Syntax

```cpp
enum RILUICCAPPTYPE {
  RIL_UICCAPPTYPE_UNKNOWN  = 0x00000001,
  RIL_UICCAPPTYPE_MF       = 0x00000002,
  RIL_UICCAPPTYPE_MF_SIM   = 0x00000003,
  RIL_UICCAPPTYPE_MF_RUIM  = 0x00000004,
  RIL_UICCAPPTYPE_USIM     = 0x00000005,
  RIL_UICCAPPTYPE_CSIM     = 0x00000006,
  RIL_UICCAPPTYPE_ISIM     = 0x00000007

};
```

## Remarks

Networks will vary, but the following table summarizes which items are returned for typical TD-SCDMA networks.

**Serving network**

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | Yes | 0 through 999 |  |
| MobileNetworkCode | Yes | 0 through 999 |  |
| LocationAreaCode | Yes | 0 to 65535 |  |
| CellID | Yes | 0 through 268,435,455 | May not always be available; 28 bits |
| UARFCN | Yes | 0 through 16,383 | Channel number |
| CellParameterID | Yes | 0 through 127 |  |
| TimingAdvance | Yes | 0 through 8,191 | By standards, the maximum range is 96 chips (0 to 96x8) |
| RSCP | Yes | −25 through −128 | Received signal code power of serving cell in dBm |
| PathLoss | No | 46 through 158 | Path loss of serving cell in dBs |

**TD-SCDMA neighbors** (subject to availability from network)

| Entry | Typically returned? | Range | Comment |
| --- | --- | --- | --- |
| MobileCountryCode | No |  |  |
| MobileNetworkCode | No |  |  |
| LocationAreaCode | No |  |  |
| CellID | No |  |  |
| UARFCN | Yes | 0 through 16,383 | Channel number |
| CellParameterID | Yes | 0 through 127 |  |
| TimingAdvance | No |  |  |
| RSCP | Yes | −25 through −128 | Received signal code power of serving cell in dBm |
| PathLoss | No |  |  |

## See also

[Cellular COM enumerations](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946509(v=vs.85))
# RILIMSI structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILIMSI.

`const int MAXLENGTH_IMSI = 16`

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILIMSIPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilimsiparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `wszImsi`

The IMSI as a null-terminated Unicode string.

### `dwMcc`

The mobile country code from the IMSI.

### `dwMnc`

The mobile network code from the IMSI.

## Syntax

```cpp
struct RILIMSI {
  DWORD cbSize;
  DWORD dwParams;
  WCHAR wszImsi[MAXLENGTH_IMSI];
  DWORD dwMcc;
  DWORD dwMnc;
};
```

## Remarks

The RIL driver is responsible for determining whether the MNC comprises two or three digits and extracting it accordingly. (For 3GPP, the number of digits in the MNC is specified by the fourth byte of EFAD as specified in 3GPP TS 31.102 section 4.2.18.)

For 3GPP2, the IMSI_T is returned if it is programmed; otherwise, the IMSI_M is returned. For the IMSI_T, dwMcc contains the MCC_Tp and dwMnc contains IMSI_T_11_12p. For the IMSI_M, dwMcc contains the MCC_Mp and dwMnc is not defined (that is, the RIL_PARAM_IMSI_MNC bit in dwParams is 0).

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
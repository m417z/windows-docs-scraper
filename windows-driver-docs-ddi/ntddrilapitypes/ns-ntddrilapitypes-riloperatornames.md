# RILOPERATORNAMES structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents the RILOPERATORNAMES.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILOPERATORNAMESPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riloperatornamesparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwSystemType`

Must specify one and only one system type.

### `wszLongName`

### `wszShortName`

### `wszNumName`

### `wszCountryCode`

Mobile country code

## Syntax

```cpp
struct RILOPERATORNAMES {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwSystemType;
  WCHAR wszLongName[MAXLENGTH_OPERATOR_LONG];
  WCHAR wszShortName[MAXLENGTH_OPERATOR_SHORT];
  WCHAR wszNumName[MAXLENGTH_OPERATOR_NUMERIC];
  WCHAR wszCountryCode[MAXLENGTH_OPERATOR_COUNTRY_CODE];
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
# RILOPERATORNAMES structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `dwSystemType`

### `wszLongName`

### `wszShortName`

### `wszNumName`

### `wszCountryCode`

## Syntax

```cpp
typedef struct _RILOPERATORNAMES {
  DWORD                                   cbSize;
  DWORD                                   dwParams;
  DWORD                                   dwSystemType;
  WCHAR [MAXLENGTH_OPERATOR_LONG]         wszLongName;
  WCHAR [MAXLENGTH_OPERATOR_SHORT]        wszShortName;
  WCHAR [MAXLENGTH_OPERATOR_NUMERIC]      wszNumName;
  WCHAR [MAXLENGTH_OPERATOR_COUNTRY_CODE] wszCountryCode;
} RILOPERATORNAMES, RILOPERATORNAMES;
```
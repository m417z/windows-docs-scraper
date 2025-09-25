# RILSUBSCRIBERINFO structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `raAddress`

### `wszDescription`

### `dwService`

## Syntax

```cpp
typedef struct _RILSUBSCRIBERINFO {
  DWORD                         cbSize;
  DWORD                         dwParams;
  RILADDRESS                    raAddress;
  WCHAR [MAXLENGTH_DESCRIPTION] wszDescription;
  RILSUBSCRIBERINFOSERVICE      dwService;
} RILSUBSCRIBERINFO, RILSUBSCRIBERINFO;
```
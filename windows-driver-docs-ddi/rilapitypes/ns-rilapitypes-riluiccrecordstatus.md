# RILUICCRECORDSTATUS structure (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Members

### `cbSize`

### `dwParams`

### `dwRecordType`

### `dwItemCount`

### `dwSize`

### `fileLockStatus`

## Syntax

```cpp
typedef struct _RILUICCRECORDSTATUS {
  DWORD                                        cbSize;
  DWORD                                        dwParams;
  RILUICCRECORDTYPE                            dwRecordType;
  DWORD                                        dwItemCount;
  DWORD                                        dwSize;
  RILUICCFILELOCKSTATUS [MAXNUM_EFACCESSTYPES] fileLockStatus;
} RILUICCRECORDSTATUS, RILUICCRECORDSTATUS;
```
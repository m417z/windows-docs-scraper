# RILUICCRECORDSTATUS structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILUICCRECORDSTATUS.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILUICCRECORDSTATUSPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluiccrecordstatusparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwRecordType`

Specifies the UICC file type, one of [RILUICCRECORDTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluiccrecordtype).

### `dwItemCount`

Specifies the number of items in the UICC file.

### `dwSize`

Specifies the size of each item in bytes.

### `fileLockStatus`

An array of type [RILUICCFILELOCKSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-riluiccfilelockstatus) that describes the access condition and a list of key references for each operation (READ, UPDATE, ACTIVATE, and DEACTIVATE in that order) on that file.

## Syntax

```cpp
struct RILUICCRECORDSTATUS {
  DWORD                 cbSize;
  DWORD                 dwParams;
  RILUICCRECORDTYPE     dwRecordType;
  DWORD                 dwItemCount;
  DWORD                 dwSize;
  RILUICCFILELOCKSTATUS fileLockStatus[MAXNUM_EFACCESSTYPES];
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))
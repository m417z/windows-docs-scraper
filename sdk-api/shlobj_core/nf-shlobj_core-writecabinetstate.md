# WriteCabinetState function

## Description

[**WriteCabinetState** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Writes the information contained in a [CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate) structure into the registry.

## Parameters

### `pcs` [in]

Type: **[CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate)***

A pointer to a [CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate) structure that holds the values to be set.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**.
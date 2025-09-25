# ReadCabinetState function

## Description

[**ReadCabinetState** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Fills a [CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate) structure with information from the registry.

## Parameters

### `pcs` [out]

Type: **[CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate)***

When this function returns, contains a pointer to a [CABINETSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-cabinetstate) structure that contains either information pulled from the registry or default information.

### `cLength` [in]

Type: **int**

The size of the structure pointed to by *pcs*, in bytes.

## Return value

Type: **BOOL**

Returns **TRUE** if the returned structure contains information from the registry. Returns **FALSE** if the structure contains default information.
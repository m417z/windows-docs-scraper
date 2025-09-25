# FILEMUIINFO_GET_MAIN_TYPEIDS macro

## Syntax

```cpp
DWORD* FILEMUIINFO_GET_MAIN_TYPEIDS(
    PFILEMUIINFO pInfo
);
```

## Return value

Type: **DWORD***

Returns a pointer to the main module types array. The macro returns **NULL** if the array is not initialized.

## Description

Gets the main module types array associated with the type identifier offset information in the **dwTypeIDMainOffset** member of a [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## Parameters

### `pInfo`

Pointer to the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## See also

[FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Macros](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-macros)
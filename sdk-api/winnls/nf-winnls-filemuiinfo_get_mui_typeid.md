# FILEMUIINFO_GET_MUI_TYPEID macro

## Syntax

```cpp
DWORD FILEMUIINFO_GET_MUI_TYPEID(
    PFILEMUIINFO pInfo,
    DWORD iType
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the MUI module types array element. The macro returns **NULL** if the array is not initialized or if the supplied index is out of bounds.

## Description

Gets the MUI module types array element associated with the type identifier size and offset information in a [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure. The information is provided in the **dwTypeIDMUISize** and **dwTypeIDMUIOffset** members of the structure.

## Parameters

### `pInfo`

Pointer to the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

### `iType`

Index of the array element.

## See also

[FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Macros](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-macros)
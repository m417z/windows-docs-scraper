# FILEMUIINFO_GET_MAIN_TYPENAMES macro

## Syntax

```cpp
LPWSTR FILEMUIINFO_GET_MAIN_TYPENAMES(
    PFILEMUIINFO pInfo
);
```

## Return value

Type: **LPWSTR**

Returns a pointer to the main module names multistring array. The macro returns **NULL** if the array is not initialized.

## Description

Gets the main module names multistring array associated with the type name offset information in the **dwTypeNameMainOffset** member of a [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## Parameters

### `pInfo`

Pointer to the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## See also

[FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Macros](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-macros)
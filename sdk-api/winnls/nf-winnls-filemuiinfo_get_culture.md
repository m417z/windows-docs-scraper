# FILEMUIINFO_GET_CULTURE macro

## Syntax

```cpp
LPWSTR FILEMUIINFO_GET_CULTURE(
    PFILEMUIINFO pInfo
);
```

## Return value

Type: **LPWSTR**

Returns a pointer to the locale name. The macro returns **NULL** if the language name offset in the structure is not initialized.

## Description

Gets the locale name associated with the language name offset information in the **dwLanguageNameOffset** member of a [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## Parameters

### `pInfo`

Pointer to the [FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo) structure.

## See also

[FILEMUIINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-filemuiinfo)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Macros](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-macros)
# SHCreatePropSheetExtArray function

## Description

[**SHCreatePropSheetExtArray** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Loads all the Shell [property sheet extension handlers](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc144106(v=vs.85)) located under a specified registry key.

## Parameters

### `hKey` [in]

Type: **HKEY**

The registry root key that contains the subkey with the property sheet extension handlers. For instance, **HKEY_LOCAL_MACHINE**.

### `pszSubKey` [in, optional]

Type: **PCWSTR**

A pointer to a null-terminated string specifying the name of the subkey that contains **shellex**\**PropertySheetHandlers**.

For example, if *hkey* specifies HKEY_LOCAL_MACHINE and *pszSubkey* specifies "Software\Microsoft\Windows\CurrentVersion\Controls Folder\Display", this function returns property sheet extension handlers using the following subkey:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows
            CurrentVersion
               Controls Folder
                  Display
                     shellex
                        PropertySheetHandlers
```

### `max_iface`

Type: **UINT**

The maximum number of property sheet handlers to be returned.

## Return value

Type: **HPSXA**

Returns a handle to an array of property sheet handlers. Pass this value to [SHAddFromPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddfrompropsheetextarray). You do not access this value directly.

## Remarks

When you are finished with the returned HPSXA handle, destroy it by calling [SHDestroyPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shdestroypropsheetextarray).

This function loads up to *max_iface* property sheet extensions into an array that is then passed to [SHAddFromPropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddfrompropsheetextarray).
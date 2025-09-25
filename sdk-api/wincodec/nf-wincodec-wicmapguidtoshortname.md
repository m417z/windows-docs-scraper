# WICMapGuidToShortName function

## Description

Obtains the short name associated with a given GUID.

## Parameters

### `guid` [in]

Type: **REFGUID**

The GUID to retrieve the short name for.

### `cchName` [in]

Type: **UINT**

The size of the *wzName* buffer.

### `wzName` [in, out]

Type: **WCHAR***

A pointer that receives the short name associated with the GUID.

### `pcchActual` [out]

Type: **UINT***

The actual size needed to retrieve the entire short name associated with the GUID.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Windows Imaging Component (WIC) short name mappings can be found within the following registry key:

```
HKEY_CLASSES_ROOT
   CLSID
      {FAE3D380-FEA4-4623-8C75-C6B61110B681}
         Namespace
            ...
```
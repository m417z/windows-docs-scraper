# WICMapShortNameToGuid function

## Description

Obtains the GUID associated with the given short name.

## Parameters

### `wzName` [in]

Type: **const WCHAR***

A pointer to the short name.

### `pguid` [out]

Type: **GUID***

A pointer that receives the GUID associated with the given short name.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can extend the short name mapping by adding to the following registry key:

```
HKEY_CLASSES_ROOT
   CLSID
      {FAE3D380-FEA4-4623-8C75-C6B61110B681}
         Namespace
            ...
```

For more information, see [How to Write a WIC-Enabled Codec](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec).
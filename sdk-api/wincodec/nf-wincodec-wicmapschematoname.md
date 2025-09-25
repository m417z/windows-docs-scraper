# WICMapSchemaToName function

## Description

Obtains the name associated with a given schema.

## Parameters

### `guidMetadataFormat` [in]

Type: **[REFGUID](https://learn.microsoft.com/windows/desktop/wic/-wic-guids-clsids)**

The metadata format GUID.

### `pwzSchema` [in]

Type: **LPWSTR**

The URI string of the schema for which the name is to be retrieved.

### `cchName` [in]

Type: **UINT**

The size of the *wzName* buffer.

### `wzName` [in, out]

Type: **WCHAR***

A pointer to a buffer that receives the schema's name.

To obtain the required buffer size, call **WICMapSchemaToName** with *cchName* set to 0 and *wzName* set to **NULL**.

### `pcchActual` [out]

Type: **UINT**

The actual buffer size needed to retrieve the entire schema name.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can extend the schema name mapping by adding to the following registry key:

```
HKEY_CLASSES_ROOT
   CLSID
      {FAE3D380-FEA4-4623-8C75-C6B61110B681}
         Schemas
            BB5ACC38-F216-4CEC-A6C5-5F6E739763A9
               ...
```

For more information, see [How to Write a WIC-Enabled Codec](https://learn.microsoft.com/windows/desktop/wic/-wic-howtowriteacodec).
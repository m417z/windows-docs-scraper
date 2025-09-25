# IMetaDataImport2::GetVersionString

## Description

Gets the version number of the runtime that was used to build the assembly.

## Parameters

### `pwzBuf` [out]

An array to store the string that specifies the version.

### `ccBufSize` [in]

The size, in wide characters, of the *pwzBuf* array.

### `pccBufSize` [out]

The number of wide characters, including a null terminator, returned in the *pwzBuf* array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **GetVersionString** method gets the built-for version of the current metadata scope. If the scope has never been saved, it will not have a built-for version, and an empty string will be returned.

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)
# IMetaDataImport::GetScopeProps

## Description

Gets the name and optionally the version identifier of the assembly or module in the current metadata scope.

## Parameters

### `szName` [out]

A buffer for the assembly or module name.

### `cchName` [in]

The size in wide characters of *szName*.

### `pchName` [out]

The number of wide characters returned in *szName*.

### `pmvid` [out]

A pointer to a GUID that uniquely identifies the version of the assembly or module.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)
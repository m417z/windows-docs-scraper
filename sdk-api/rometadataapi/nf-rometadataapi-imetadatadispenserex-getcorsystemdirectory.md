# IMetaDataDispenserEx::GetCORSystemDirectory

## Description

Gets the directory that holds the current common language runtime (CLR). This method is supported only for use by out-of-process debuggers. If called from another component, it will return E_NOTIMPL.

## Parameters

### `szBuffer` [out]

The buffer to receive the directory name.

### `cchBuffer` [in]

The size, in bytes, of *szBuffer*.

### `pchBuffer` [out]

The number of bytes actually returned in *szBuffer*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)
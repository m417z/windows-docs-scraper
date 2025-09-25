# ISchemaProvider::SaveBinary

## Description

Saves the loaded schema as a schema binary at a specified path.

## Parameters

### `pszSchemaBinaryPath` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string that contains the fully qualified path at which to save the schema binary.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any existing file at the location specified by *pszSchemaBinaryPath* is overwritten.
# QueryPathOfRegTypeLib function

## Description

Retrieves the path of a registered type library.

## Parameters

### `guid`

The GUID of the library.

### `wMaj`

The major version number of the library.

### `wMin`

The minor version number of the library.

### `lcid`

The national language code for the library.

### `lpbstrPathName` [out]

The type library name.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returns the fully qualified file name that is specified for the type library in the registry. The caller allocates the BSTR that is passed in, and must free it after use.
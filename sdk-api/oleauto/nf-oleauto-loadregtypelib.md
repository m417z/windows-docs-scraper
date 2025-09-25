# LoadRegTypeLib function

## Description

Uses registry information to load a type library.

## Parameters

### `rguid`

The GUID of the library.

### `wVerMajor`

The major version of the library.

### `wVerMinor`

The minor version of the library.

### `lcid`

The national language code of the library.

### `pptlib`

The loaded type library.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function could not write to the file. |
| **TYPE_E_INVALIDSTATE** | The type library could not be opened. |
| **TYPE_E_INVDATAREAD** | The function could not read from the file. |
| **TYPE_E_UNSUPFORMAT** | The type library has an older format. |
| **TYPE_E_UNKNOWNLCID** | The LCID could not be found in the OLE-supported DLLs. |
| **TYPE_E_CANTLOADLIBRARY** | The type library or DLL could not be loaded. |

## Remarks

The function **LoadRegTypeLib** defers to [LoadTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-loadtypelib) to load the file.

**LoadRegTypeLib** compares the requested version numbers against those found in the system registry, and takes one of the following actions:

* If one of the registered libraries exactly matches both the requested major and minor version numbers, then that type library is loaded.
* If one or more registered type libraries exactly match the requested major version number, and has a greater minor version number than that requested, the one with the greatest minor version number is loaded.
* If none of the registered type libraries exactly match the requested major version number (or if none of those that do exactly match the major version number also have a minor version number greater than or equal to the requested minor version number), then **LoadRegTypeLib** returns an error.
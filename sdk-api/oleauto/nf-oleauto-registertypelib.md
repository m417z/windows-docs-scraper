# RegisterTypeLib function

## Description

Adds information about a type library to the system registry.

## Parameters

### `ptlib`

The type library.

### `szFullPath` [in]

The fully qualified path specification for the type library.

### `szHelpDir` [in, optional]

The directory in which the Help file for the library being registered can be found. This parameter can be null.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function could not write to the file. |
| **TYPE_E_REGISTRYACCESS** | The system registration database could not be opened. |
| **TYPE_E_INVALIDSTATE** | The type library could not be opened. |

## Remarks

This function can be used during application initialization to register the application's type library correctly. When **RegisterTypeLib** is called to register a type library, both the minor and major version numbers are registered in hexadecimal.

In addition to filling in a complete registry entry under the type library key, **RegisterTypeLib** adds entries for each of the dispinterfaces and Automation-compatible interfaces, including dual interfaces. This information is required to create instances of these interfaces. Coclasses are not registered (that is, **RegisterTypeLib** does not write any values to the CLSID key of the coclass).
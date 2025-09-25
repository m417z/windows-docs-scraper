# UnRegisterTypeLib function

## Description

Removes type library information from the system registry. Use this API to allow applications to properly uninstall themselves.

## Parameters

### `libID`

The GUID of the type library.

### `wVerMajor`

The major version of the type library.

### `wVerMinor`

The minor version of the type library.

### `lcid`

The locale identifier.

### `syskind`

The target operating system.

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

In-process objects typically call this API from **DllUnregisterServer**.
# UnRegisterTypeLibForUser function

## Description

Removes type library information that was registered by using [RegisterTypeLibForUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelibforuser).

## Parameters

### `libID`

The GUID of the library.

### `wMajorVerNum`

The major version of the type library.

### `wMinorVerNum`

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

Use **UnRegisterTypeLibForUser** to remove type library information for type libraries that were registered using the [RegisterTypeLibForUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelibforuser) function.
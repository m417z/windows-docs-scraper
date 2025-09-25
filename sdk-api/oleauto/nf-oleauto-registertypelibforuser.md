# RegisterTypeLibForUser function

## Description

Registers a type library for use by the calling user.

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

**RegisterTypeLibForUser** has functionality identical to [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib) except that type library is registered for use only by the calling user identity.
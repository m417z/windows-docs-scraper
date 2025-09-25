# LoadTypeLibEx function

## Description

Loads a type library and (optionally) registers it in the system registry.

## Parameters

### `szFile`

The type library file.

### `regkind`

Identifies the kind of registration to perform for the type library based on the following flags: DEFAULT, REGISTER and NONE. REGKIND_DEFAULT simply calls LoadTypeLib and registration occurs based on the [LoadTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-loadtypelib) registration rules. REGKIND_NONE calls **LoadTypeLib** without the registration process enabled. REGKIND_REGISTER calls **LoadTypeLib** followed by [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib), which registers the type library. To unregister the type library, use [UnRegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-unregistertypelib).

### `pptlib`

The type library.

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
| **TYPE_E_CANTLOADLIBRARY** | The type library or DLL could not be loaded. |

## Remarks

Enables programmers to specify whether or not the type library should be loaded.
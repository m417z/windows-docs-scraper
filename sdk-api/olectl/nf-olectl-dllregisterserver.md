# DllRegisterServer function

## Description

Instructs an in-process server to create its registry entries for all classes supported in this server module.

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The registry entries were created successfully. |
| **SELFREG_E_TYPELIB** | The server was unable to complete the registration of all the type libraries used by its classes. |
| **SELFREG_E_CLASS** | The server was unable to complete the registration of all the object classes. |

## Remarks

E_NOTIMPL is not a valid return code.

If this function fails, the state of the registry for all its classes is undefined.

## See also

[DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver)
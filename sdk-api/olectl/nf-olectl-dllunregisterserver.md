# DllUnregisterServer function

## Description

Instructs an in-process server to remove only those entries created through [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver).

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The registry entries were deleted successfully. |
| **S_FALSE** | Unregistration of this server's known entries was successful, but other entries still exist for this server's classes. |
| **SELFREG_E_TYPELIB** | The server was unable to remove the entries of all the type libraries used by its classes. |
| **SELFREG_E_CLASS** | The server was unable to remove the entries of all the object classes. |

## Remarks

The server must not disturb any entries that it did not create which currently exist for its object classes. For example, between registration and unregistration, the user may have specified a Treat As relationship between this class and another. In that case, unregistration can remove all entries except the **TreatAs** key and any others that were not explicitly created in [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver). The [registry functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions) specifically disallow the deletion of an entire populated tree in the registry. The server can attempt, as the last step, to remove the CLSID key, but if other entries still exist, the key will remain.

## See also

[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver)
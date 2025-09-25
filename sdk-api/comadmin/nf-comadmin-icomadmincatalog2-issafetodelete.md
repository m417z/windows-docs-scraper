# ICOMAdminCatalog2::IsSafeToDelete

## Description

Determines whether the specified DLL is in use by the COM+ catalog or the registry.

## Parameters

### `bstrDllName` [in]

The full path to the DLL to be tested.

### `pCOMAdminInUse` [out, retval]

Indicates the DLL usage. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **COMAdminNotInUse**<br><br>0 | The DLL is not in use and may safely be deleted. |
| **COMAdminInUseByCatalog**<br><br>0x1 | The DLL is in use by the COM+ catalog. |
| **COMAdminInUseByRegistryUnknown**<br><br>0x2 | The DLL is in use by an unknown registry component. |
| **COMAdminInUseByRegistryProxyStub**<br><br>0x3 | The DLL is in use by the proxy registry component. |
| **COMAdminInUseByRegistryTypeLib**<br><br>0x4 | The DLL is in use by the TypeLib registry component. |
| **COMAdminInUseByRegistryClsid**<br><br>0x5 | The DLL is in use by the CLSID registry component. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)
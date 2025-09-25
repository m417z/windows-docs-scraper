# ICOMAdminCatalog::InstallComponent

## Description

Installs all components (COM classes) from a DLL file into a COM+ application and registers the components in the COM+ class registration database.

## Parameters

### `bstrApplIDOrName` [in]

The GUID or name of the application.

### `bstrDLL` [in]

The name of the DLL file containing the component to be installed.

### `bstrTLB` [in]

The name of the external type library file. If the type library file is embedded in the DLL, pass in an empty string for this parameter.

### `bstrPSDLL` [in]

The name of the proxy-stub DLL file. If there is no proxy-stub DLL associated with the component, pass in an empty string for this parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

**InstallComponent** provides full registration of components in the COM+ class registration database (RegDB) as configured components, including interface, method, type library, and proxy-stub information necessary for marshaling.

**InstallComponent** is the recommended way to install all components into COM+ applications instead of [ICOMAdminCatalog::ImportComponent](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog-importcomponent).

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
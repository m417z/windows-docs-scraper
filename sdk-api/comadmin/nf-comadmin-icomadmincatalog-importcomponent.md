# ICOMAdminCatalog::ImportComponent

## Description

Imports a component already registered as an in-process server into a COM+ application.

## Parameters

### `bstrApplIDOrName` [in]

The GUID or name of the application.

### `bstrCLSIDOrProgID` [in]

The CLSID or ProgID for the component to import.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Generally, this method should not be used unless you want to restrict a component to local use only. Otherwise, use the [InstallComponent](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog-installcomponent) method instead of **ImportComponent**. **InstallComponent** fully registers the component in the COM+ class registration database (RegDB), whereas **ImportComponent** does not, resulting in an application with limited functionality.

**ImportComponent** does not bring any interface, method, or type library information for the component into the COM+ class registration database. This behavior restricts how the component can be configured. When you attempt to export a COM+ application that has an imported component to an application proxy, the proxy contains no interface or type library information for the component and marshaling for that component fails.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
# IAccessibleHostingElementProviders::GetEmbeddedFragmentRoots

## Description

Retrieves the Microsoft Active Accessibility providers of all windowless Microsoft ActiveX controls that have a Microsoft UI Automation provider implementation, and are hosted in a Microsoft Active Accessibility object that implements the [IAccessibleHostingElementProviders](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessiblehostingelementproviders) interface.

## Parameters

### `pRetVal` [out, retval]

Type: **SAFEARRAY****

Receives the [IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot) interface pointers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The container of windowless ActiveX controls implements this method on the same object that implements the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface. When called, this method queries each of the contained windowless ActiveX controls for an [IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot) pointer, and then adds the pointer to the safe array.

This method should not include any providers that do not implement **IRawElementProviderFragmentRoot**.

## See also

[IAccessibleHostingElementProviders](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessiblehostingelementproviders)
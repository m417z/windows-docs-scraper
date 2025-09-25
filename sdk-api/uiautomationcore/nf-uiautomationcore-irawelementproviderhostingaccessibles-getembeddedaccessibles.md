# IRawElementProviderHostingAccessibles::GetEmbeddedAccessibles

## Description

Retrieves the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointers of the windowless Microsoft ActiveX controls that are hosted by this provider.

## Parameters

### `pRetVal` [out, retval]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

Receives the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) pointers of the hosted windowless ActiveX controls.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An ActiveX control container with an existing [IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot) interface implements this method on the same object that implements **IRawElementProviderFragmentRoot**. When called, this method should query each contained windowless control for an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) pointer and then add the pointer to the safe array.

This method should ignore providers that do not implement [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible).

## See also

[IRawElementProviderHostingAccessibles](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderhostingaccessibles)
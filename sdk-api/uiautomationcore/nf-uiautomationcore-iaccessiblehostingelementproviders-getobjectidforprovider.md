# IAccessibleHostingElementProviders::GetObjectIdForProvider

## Description

Retrieves the object ID associated with a contained windowless Microsoft ActiveX control that implements Microsoft UI Automation.

## Parameters

### `pProvider` [in, optional]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider for the windowless ActiveX control.

### `pidObject` [out]

Type: **long***

The object ID of the contained windowless ActiveX control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAccessibleHostingElementProviders](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessiblehostingelementproviders)
# UiaProviderFromIAccessible function

## Description

Creates a Microsoft UI Automation provider based on the specified Microsoft Active Accessibility object.

## Parameters

### `pAccessible` [in]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)***

A pointer to the Microsoft Active Accessibility object.

### `idChild` [in]

Type: **long**

The child ID of the Microsoft Active Accessibility object.

### `dwFlags` [in]

Type: **DWORD**

One of the following values:

#### UIA_PFIA_DEFAULT

#### UIA_PFIA_UNWRAP_BRIDGE

### `ppProvider` [out]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

The new UI Automation provider.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

UI Automation provides backward compatibility for Microsoft Active Accessibility providers by supplying a proxy for them, called the Microsoft Active Accessibility to UI Automation proxy. This proxy is created automatically when a window responds to a [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message by returning a Microsoft Active Accessibility provider. Use **UiaProviderFromIAccessible** when you need to create a Microsoft Active Accessibility to UI Automation proxy manually; for example, when implementing the [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) interface.

Some properties, such as LabeledBy, must be expressed as a UI Automation provider. An [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) provider can use **UiaProviderFromIAccessible** to wrap an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object to return it as the value of the LabeledBy property.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)

[UiaIAccessibleFromProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaiaccessiblefromprovider)
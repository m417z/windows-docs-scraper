# UiaIAccessibleFromProvider function

## Description

Retrieves an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) implementation that provides Microsoft Active Accessibility data on behalf of a Microsoft UI Automation provider.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

A pointer to the UI Automation object.

### `dwFlags` [in]

Type: **DWORD**

One of the following values:

#### UIA_IAFP_DEFAULT

#### UIA_IAFP_UNWRAP_BRIDGE

### `ppAccessible` [out]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

Receives the pointer to the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) implementation for the provider.

### `pvarChild` [out]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

Receives the child identifier of the accessible element in the **lVal** member.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In most cases, this function retrieves a wrapper object, provided by Windows, that implements [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) on behalf of the [IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple) object. If the provided **IRawElementProviderSimple** pointer is itself a wrapper object, this function retrieves the wrapped **IAccessible** pointer and returns that instead, to prevent the creation of multiple layers of wrappers.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)

[UiaProviderFromIAccessible](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaproviderfromiaccessible)
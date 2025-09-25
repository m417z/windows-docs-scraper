# IRawElementProviderSimple::get_HostRawElementProvider

## Description

Specifies the host provider for this element.

This property is read-only.

## Parameters

## Remarks

This property is generally the Microsoft UI Automation provider for the window of a custom control.
UI Automation uses this provider in combination with the custom provider. For example, the runtime identifier
of the element is usually obtained from the host provider.

A host provider must be returned in the following cases: when the element is a fragment root,
when the element is a simple element (such as a push button), and when the provider is a repositioning placeholder (for more information, see [Provider Repositioning](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-serversideprovider)).
In other cases, the property should be **NULL**.

#### Examples

The following example returns the host provider for the window that hosts the control served by
this provider.

```cpp
HRESULT STDMETHODCALLTYPE Provider::get_HostRawElementProvider(IRawElementProviderSimple** pRetVal)
{
    return UiaHostProviderFromHwnd(controlHWnd, pRetVal);
}

```

## See also

[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)

[UiaHostProviderFromHwnd](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiahostproviderfromhwnd)
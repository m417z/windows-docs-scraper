# UiaHostProviderFromHwnd function

## Description

Gets the host provider for a window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The window containing the element served by the provider.

### `ppProvider` [out]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

The host provider for the window.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The object retrieved by this function is useful only for responding to calls to the [IRawElementProviderSimple::get_HostRawElementProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementprovidersimple-get_hostrawelementprovider) method. You cannot use the object to raise events, provide properties, and so on. If you need to raise events or provide properties, you must create a provider object that fully implements the [IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple) interface.

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

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)
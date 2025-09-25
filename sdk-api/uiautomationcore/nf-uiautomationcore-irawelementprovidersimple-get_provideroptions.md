# IRawElementProviderSimple::get_ProviderOptions

## Description

Specifies the type of Microsoft UI Automation provider; for example, whether it is a client-side (proxy) or server-side provider.

This property is read-only.

## Parameters

## Remarks

The method must return either [ProviderOptions_ServerSideProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-provideroptions) or [ProviderOptions_ClientSideProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-provideroptions).

UI Automation handles the various types of providers differently.
For example, events from a server-side provider are broadcast to all listening clients,
but events from client-side (proxy) providers remain in the client.

#### Examples

The following example implements this method for a server-side UI Automation provider.

```cpp
HRESULT STDMETHODCALLTYPE Provider::get_ProviderOptions( ProviderOptions* pRetVal )
{
    *pRetVal = ProviderOptions_ServerSideProvider;
    return S_OK;
}
```

## See also

[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)
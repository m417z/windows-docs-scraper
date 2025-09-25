# IWbemContext::BeginEnumeration

## Description

The
**IWbemContext::BeginEnumeration** method resets the enumeration of all the context values in the object. This method must be called before the first call to
[IWbemContext::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-next) to enumerate all of the context values in the object. The order in which context values are enumerated is guaranteed to be invariant for a given instance of
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext).

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-endenumeration)

[IWbemContext::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-next)
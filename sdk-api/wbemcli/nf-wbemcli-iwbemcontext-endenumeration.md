# IWbemContext::EndEnumeration

## Description

The
**IWbemContext::EndEnumeration** method ends an enumeration sequence that begins with
[IWbemContext::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration). This call is not required, but it releases as early as possible any system resources associated with the enumeration.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration)

[IWbemContext::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-next)
# IWbemQualifierSet::EndEnumeration

## Description

Call the
**IWbemQualifierSet::EndEnumeration** method when you plan to terminate enumerations initiated with
[IWbemQualifierSet::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-beginenumeration) and
[IWbemQualifierSet::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-next). This call is recommended, but not required. It immediately releases resources associated with the enumeration.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)

[IWbemQualifierSet::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-beginenumeration)

[IWbemQualifierSet::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-next)
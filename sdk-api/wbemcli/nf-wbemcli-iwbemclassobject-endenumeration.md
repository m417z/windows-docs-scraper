# IWbemClassObject::EndEnumeration

## Description

The
**IWbemClassObject::EndEnumeration** method terminates an enumeration sequence started with
[IWbemClassObject::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginenumeration). This call is not required, but it is recommended to developers because it releases resources associated with the enumeration. However, the resources are deallocated automatically when the next enumeration is started or the object is released.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginenumeration)

[IWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-next)
# IWbemClassObject::GetPropertyOrigin

## Description

The
**IWbemClassObject::GetPropertyOrigin** method retrieves the name of the class in which a particular property was introduced. For classes with deep inheritance hierarchies, it is often desirable to know which properties were declared in which classes. If the object does not inherit from a parent class, as in the case of a base class, for example, then the current class name is returned.

## Parameters

### `wszName` [in]

Property name for which the owning class name is desired. This must point to a valid **LPCWSTR**, which is treated as read-only.

### `pstrClassName` [out]

Pointer to the address of a new **BSTR** that receives the parent class name. To prevent memory leaks in the client process, the caller must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the name is no longer required. This parameter must not point to a valid string before the method is called because this is an output parameter, and this pointer is not deallocated after the call is complete.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::InheritsFrom](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-inheritsfrom)
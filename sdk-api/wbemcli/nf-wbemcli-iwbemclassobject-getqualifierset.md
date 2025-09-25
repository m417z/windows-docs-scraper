# IWbemClassObject::GetQualifierSet

## Description

The
**IWbemClassObject::GetQualifierSet** method returns an interface pointer that allows read and write operations on the set of qualifiers for the entire class object, whether the object is an instance or a class definition. Any qualifiers added, deleted, or edited using the returned pointer apply to the entire instance or class definition.

## Parameters

### `ppQualSet` [out]

Receives the interface pointer that allows access to the qualifiers for the class object. The returned object has a positive reference count upon return from the call. The caller must call **IWbemQualifierSet::Release** when the object is no longer needed. This parameter cannot be **NULL**. On error, a new object is not returned and the pointer is left unmodified.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::GetPropertyQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-getpropertyqualifierset)

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)
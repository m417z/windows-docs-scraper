# IWbemClassObject::GetPropertyQualifierSet

## Description

The
**IWbemClassObject::GetPropertyQualifierSet** method gets the qualifier set for a particular property in the class object. You can use this method with properties that are a member of an instance or a class definition.

## Parameters

### `wszProperty` [in]

Property for which the qualifier set is requested. This cannot be **NULL** and must point to a valid **LPCWSTR**. The property can be local or propagated from the parent class. Note that system properties have no qualifiers so this method returns the error code **WBEM_E_SYSTEM_PROPERTY** if you attempt to obtain the
[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset) pointer for a system property.

### `ppQualSet` [out]

Receives an interface pointer that allows access to the qualifiers for the named property. The caller must call **IWbemQualifierSet::Release** on the pointer when access to the object is no longer required. The property is set to point to **NULL** when there are error conditions. A new object is not returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)
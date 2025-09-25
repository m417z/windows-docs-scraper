# IWbemClassObject::GetMethodQualifierSet

## Description

The
**IWbemClassObject::GetMethodQualifierSet** is used to retrieve the qualifier set for a particular method.

This call is supported only if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers, which point to CIM instances.

## Parameters

### `wszMethod` [in]

Must point to a valid **LPCWSTR** containing the method name.

### `ppQualSet` [out]

Receives the interface pointer that allows access to the qualifiers for the method. The returned object has a positive reference count upon return from the call. The caller must call **IWbemQualifierSet::Release** when the object is no longer needed. This parameter cannot be **NULL**. On error, a new object is not returned, and the pointer is set to point to **NULL**.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Because each method may have its own qualifiers, use this call to retrieve the
[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset) pointer, which allows the caller to add, edit, or delete such qualifiers.
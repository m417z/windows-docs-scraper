# IWbemClassObject::InheritsFrom

## Description

The
**IWbemClassObject::InheritsFrom** method determines if the current class or instance derives from a specified parent class.

## Parameters

### `strAncestor` [in]

Cannot be **NULL**. It contains the class name that is being tested. If the current object has this class for one of its ancestor classes, **WBEM_S_NO_ERROR** returns. This must point to a valid **LPCWSTR**, which is treated as read-only.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[GetPropertyOrigin](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-getpropertyorigin)

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)
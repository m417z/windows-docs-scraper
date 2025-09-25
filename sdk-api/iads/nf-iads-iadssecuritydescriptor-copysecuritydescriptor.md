# IADsSecurityDescriptor::CopySecurityDescriptor

## Description

The **IADsSecurityDescriptor::CopySecurityDescriptor** method copies an ADSI security descriptor object that holds security data about an object.

## Parameters

### `ppSecurityDescriptor` [out]

Pointer to a pointer to a security descriptor object.

## Return value

This method returns the standard return values, including **E_INVALIDARG**, **E_OUTOFMEMORY**, **E_UNEXPECTED**, and **E_FAIL**, as well as **S_OK**. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsAccessControlList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrollist)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)
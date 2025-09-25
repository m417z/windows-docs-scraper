# IDirectoryObject::DeleteDSObject

## Description

The **IDirectoryObject::DeleteDSObject** method deletes a leaf object in a directory tree.

## Parameters

### `pszRDNName`

The relative distinguished name (relative path) of the object to be deleted.

## Return value

This method returns the standard return values, including S_OK for a successful operation. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

To delete a container object and its children, use the [IADsDeleteOps::DeleteObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsdeleteops-deleteobject) method.

#### Examples

The following C/C++ code example shows how to delete a user object.

```cpp
HRESULT hr;
IDirectoryObject *pDirObject=NULL;
hr = ADsGetObject(L"LDAP://OU=Sales,DC=Fabrikam,DC=com",
    IID_IDirectoryObject, (void**) &pDirObject );

if ( SUCCEEDED(hr) )
{
    hr = pDirObject->DeleteDSObject( L"CN=Jeff Smith" );

    pDirObject->Release();
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsDeleteOps::DeleteObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsdeleteops-deleteobject)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)
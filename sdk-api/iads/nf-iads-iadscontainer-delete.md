# IADsContainer::Delete

## Description

The **IADsContainer::Delete** method deletes a specified directory object from this container.

## Parameters

### `bstrClassName` [in]

The schema class object to delete. The name is that returned from the [IADs::get_Class](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) method. Also, **NULL** is a valid option for this parameter. Providing **NULL** for this parameter is the only way to deal with defunct schema classes. If an instance was created before the class became defunct, the only way to delete the instance of the defunct class is to call **IADsContainer::Delete** and provide **NULL** for this parameter.

### `bstrRelativeName` [in]

Name of the object as it is known in the underlying directory and identical to the name retrieved with the [IADs::get_Name](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) method.

## Return value

This method supports the standard return values, including S_OK for a successful operation. For more information about error codes, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The object to be deleted must be a leaf object or a childless subcontainer. To delete a container and its children, that is, a subtree, use [IADsDeleteOps::DeleteObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsdeleteops-deleteobject).

The specified object is immediately removed after calling **IADsContainer::Delete** and calling [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) on the container object is unnecessary.

When using the **IADsContainer::Delete** method to delete an object in C/C++ applications, release the interface pointers to that object as well. This is because the method removes the object from the underlying directory immediately, but leave intact any interface pointers held, in memory, by the application, for the deleted object. If not released, confusion can occur in that you may call [IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get) and [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) on the deleted object without error, but will receive an error when you call [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) or [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo) on the deleted object.

#### Examples

The following code example deletes a user object from the container in Active Directory.

```vb
Dim cont as IADsContainer
On Error GoTo Cleanup

Set cont = GetObject("LDAP://OU=Sales,DC=Fabrikam,DC=com")
cont.Delete "user", "CN=JeffSmith"

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set cont = Nothing

```

The following code example deletes a user object from the container under WinNT provider.

```vb
Dim cont as IADsContainer
On Error GoTo Cleanup

Set cont = GetObject("WinNT://Fabrikam")
cont.Delete "user", "jeffsmith"

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set cont = Nothing
```

The following code example deletes a user using **IADsContainer::Delete**.

```cpp
HRESULT hr = S_OK;
IADsContainer *pCont=NULL;

CoInitialize(NULL);

hr = ADsGetObject(L"WinNT://myMachine",
                  IID_IADsContainer,
                  (void**) &pCont);
if ( !SUCCEEDED(hr) )
{
     return hr;
}

hr = pCont->Delete(CComBSTR("user"), CComBSTR("JeffSmith"));
pCont->Release();
```

## See also

[ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo)

[IADs::get_Class](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

**IADs::get_Name**

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IADsContainer::Create](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscontainer-create)

[IADsDeleteOps::DeleteObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsdeleteops-deleteobject)
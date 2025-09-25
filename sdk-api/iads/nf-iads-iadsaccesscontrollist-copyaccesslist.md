# IADsAccessControlList::CopyAccessList

## Description

The **IADsAccessControlList::CopyAccessList** method copies every access control entry (ACE) in the access-control list (ACL) to the caller's process space.

## Parameters

### `ppAccessControlList` [out]

Address of an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to an ACL as the copy of the original access list. If this parameter is **NULL** on return, no copies of the ACL could be made.

## Return value

This method returns the standard return values.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The caller must call **Release** on the copy of ACEs through their [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) pointers.

#### Examples

The following code example shows how to copy an ACL from one ADSI object to another.

```vb
Dim x As IADs
Dim sd As IADsSecurityDescriptor
Dim Dacl As IADsAccessControlList
Dim CopyDacl As IADsAccessControlList

' Get the ACL from one object.
Set x = GetObject("LDAP://OU=Sales, DC=activeD,DC=mydomain,DC=fabrikam,DC=com")
Set sd = x.Get("ntSecurityDescriptor")
Set Dacl = sd.DiscretionaryAcl
Set CopyDacl = Dacl.CopyAccessList()

' Copy the ACL to another object in the Directory.
Set x = GetObject("LDAP://OU=Sales, DC=Fabrikam,DC=com")
Set sd = x.Get("ntSecurityDescriptor")
sd.DiscretionaryAcl = CopyDacl
x.Put "ntSecurityDescriptor", Array(sd)
x.SetInfo

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set x = Nothing
    Set sd = Nothing
    Set Dacl = Nothing
    Set CopyDacl = Nothing

```

The following code example copies the ACL from the source object to the target object.

```cpp
HRESULT CopyACL(IADs *pSource, IADs *pTarget)
{
    IADsSecurityDescriptor *pSourceSD = NULL;
    IADsSecurityDescriptor *pTargetSD = NULL;
    IDispatch *pDisp = NULL;

    HRESULT hr = S_OK;
    VARIANT varSource, varTarget;

    VariantInit(&varSource);
    VariantInit(&varTarget);

    if((pSource==NULL) || (pTarget==NULL))
    {
        return E_FAIL;
    }

    hr = pSource->Get(CComBSTR("ntSecurityDescriptor"), &varSource);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pTarget->Get(CComBSTR("ntSecurityDescriptor"), &varTarget);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = V_DISPATCH(&varSource)->QueryInterface(IID_IADsSecurityDescriptor,
                    (void**)&pSourceSD);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = V_DISPATCH(&varTarget)->QueryInterface(IID_IADsSecurityDescriptor,
                    (void**)&pTargetSD);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pSourceSD->get_DiscretionaryAcl(&pDisp);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pTargetSD->put_DiscretionaryAcl(pDisp);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pTarget->SetInfo();

Cleanup:
    VariantClear(&varSource);
    VariantClear(&varTarget);
    if(pSourceSD)
    {
        pSourceSD->Release();
    }
    if(pTargetSD)
    {
        pTargetSD->Release();
    }
    if(pDisp)
    {
        pDisp->Release();
    }
    return hr;
}

```

## See also

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsAccessControlList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrollist)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)
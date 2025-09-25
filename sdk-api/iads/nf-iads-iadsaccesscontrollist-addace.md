# IADsAccessControlList::AddAce

## Description

 The **IADsAccessControlList::AddAce** method adds an [IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry) object to the [IADsAccessControlList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrollist) object.

## Parameters

### `pAccessControlEntry` [in]

Pointer to the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface of the [IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry) object to be added. This parameter cannot be **NULL**.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

Access control entries must appear in the following order in a security descriptor's access control list:

* Access-denied ACEs that apply to the object itself
* Access-denied ACEs that apply to a child of the object, such as a property set or property
* Access-allowed ACEs that apply to the object itself
* Access-allowed ACEs that apply to a child of the object, such as a property set or property
* All inherited ACEs

This method adds the ACE to the front of the ACL, which does not necessarily result in correct ordering.

#### Examples

The following Visual Basic code example shows how to use the **IADsAccessControlList::AddAce** method to add two ACEs to an ACL.

```vb
Const ACL_REVISION_DS = &H4

Dim x as IADs
Dim sd as IADsSecurityDescriptor
Dim Ace1 As new IADsAccessControlEntry
Dim Ace2 As new IADsAccessControlEntry
Dim Dacl As new IADsAccessControlList
On Error GoTo Cleanup

Set x = GetObject("LDAP://OU=Sales,DC=Fabrikam,DC=com")
Set sd = x.Get("ntSecurityDescriptor")

' Add the ACEs to the Discretionary ACL.

Dacl.AclRevision = ACL_REVISION_DS 'DS ACL Revision
' Set up the first ACE.
Ace1.AccessMask = -1 'Full Permission (Allowed)
Ace1.AceType = ADS_ACETYPE_ACCESS_ALLOWED
Ace1.AceFlags = ADS_ACEFLAG_INHERIT_ACE
Ace1.Trustee = "myMachine\Administrator"

' Set up the 2nd ACE.
Ace2.AccessMask = -1 'Full Permission (Denied)
Ace2.AceType = ADS_ACETYPE_ACCESS_DENIED
Ace2.AceFlags = ADS_ACEFLAG_INHERIT_ACE
Ace2.Trustee = "aDomain\aUser"

' Add the ACEs to the Discretionary ACL.
Dacl.AddAce Ace1
Dacl.AddAce Ace2

'Commit the changes.
sd.DiscretionaryAcl = Dacl
x.Put "ntSecurityDescriptor", Array(sd)
x.SetInfo

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set Ace1 = Nothing
    Set Ace2 = Nothing
    Set Dacl = Nothing
    Set x = Nothing
    Set sd = Nothing

```

The following C++ code example adds an ACE to an ACL using the **IADsAccessControlList::AddAce** method. The added ACE has allowed access rights with the full permission.

```cpp
HRESULT addAceTo(IADsAccessControlList *pAcl)
{
    if(!pAcl)
    {
        return E_FAIL;
    }

    HRESULT hr = pAcl->put_AclRevision(ACL_REVISION_DS);
    if(FAILED(hr))
    {
        return hr;
    }

    IADsAccessControlEntry *pAce = NULL;
    pAce = createAce(-1,                    // Full permissions.
                     ADS_ACETYPE_ACCESS_ALLOWED,
                     ADS_ACEFLAG_INHERIT_ACE,
                     CComBSTR("aDomain\\aUser"));

    if(!pAce)
    {
        return E_FAIL;
    }

    IDispatch *pDisp;
    hr = pAce->QueryInterface(IID_IDispatch,(void**)&pDisp);
    if(FAILED(hr))
    {
        pAce->Release();
        return hr;
    }

    hr = pAcl->AddAce(pDisp);
    pDisp->Release();
    if(pAce) pAce->Release();
    if(FAILED(hr))
    {
        return hr;
    }

    printf("Ace has been added to ACL.\n");

    return hr;
}

////////////////////////////////////
// function to create an allowed ACE
////////////////////////////////////
IADsAccessControlEntry *createAce(
                   long mask,
                   long type,
                   long flag,
                   BSTR trustee)
{
    HRESULT hr;
    IADsAccessControlEntry *pAce;
    hr = CoCreateInstance(CLSID_AccessControlEntry,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IADsAccessControlEntry,
                          (void**)&pAce);
    if(FAILED(hr))
    {
        if(pAce)
        {
            pAce->Release();
        }

        return NULL;
    }

    hr = pAce->put_AccessMask(mask);
    hr = pAce->put_AceType(type);
    hr = pAce->put_AceFlags(flag);
    hr = pAce->put_Trustee(trustee);

    return pAce;
}
```

## See also

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsAccessControlList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrollist)
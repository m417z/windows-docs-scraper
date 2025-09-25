# IADsGroup::Add

## Description

The **IADsGroup::Add** method adds an ADSI object to an existing group.

## Parameters

### `bstrNewItem` [in]

Contains a **BSTR** that specifies the ADsPath of the object to add to the group. For more information, see Remarks.

## Return value

The following are the most common return values. For more information about return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

If the LDAP provider is used to bind to the [IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup) object, the same form of ADsPath must be specified in the *bstrNewItem* parameter. For example, if the ADsPath used to bind to the **IADsGroup** object includes a server, the ADsPath in the *bstrNewItem* parameter must contain the same server prefix. Likewise, if a serverless path is used to bind to the **IADsGroup** object, the *bstrNewItem* parameter must also contain a serverless path. When using server prefix, delays may occur if the group and the new member are from different domains, as requests may be sent to the wrong domain controller and referred to a domain controller of the correct domain and retried there. An exception occurs when adding or removing a member using a GUID or security identifier (SID) ADsPath. In this case, a serverless path should always be used in *bstrNewItem*.

The LDAP provider for Active Directory enables a member to be added to a group using the string form of the member SID. The *bstrNewItem* parameter can contain a SID string in the following form.

```cpp
LDAP://SID=<010500000000000515000000c6bb507afbda8b7f43170a325b040000>
```

For more information about SID strings in Active Directory, see [Binding to an Object Using a SID](https://learn.microsoft.com/windows/desktop/AD/binding-to-an-object-using-a-sid).

The WinNT provider for Active Directory also enables a member to be added to a group using the string form of the member's SID. The *bstrNewItem* parameter can contain a SID string in the following form.

```cpp
WinNT://S-1-5-21-35135249072896"
```

#### Examples

The following code example shows how to add a user object ("jeff") to the group ("Administrators") on the "Fabrikam" domain, using the WinNT provider.

```vb
Dim grp As IADsGroup
Set grp = GetObject("WinNT://Fabrikam/Administrators")
grp.Add ("WinNT://Fabrikam/jeff")
```

The following code example shows how to add a user object to a group using the LDAP provider.

```vb
Dim grp As IADsGroup
On Error GoTo Cleanup

Set grp = GetObject("LDAP://CN=Administrators, CN=Users, DC=Fabrikam, DC=com")
grp.Add("LDAP://CN=Jeff Smith, OU=Sales,DC=Fabrikam,DC=com")

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set grp = Nothing
```

The following code example adds an existing user account to the Administrators group.

```cpp
IADsGroup *pGroup = NULL;
HRESULT hr = S_OK;
LPWSTR adsPath = L"WinNT://Fabrikam/Administrators";
hr = ADsGetObject(adsPath,IID_IADsGroup,(void**)&pGroup);
if(FAILED(hr)) {goto Cleanup;}

// This assumes that the "WinNT://Fabrikam/jeff" user account exists
// and does not already belong to the Administrators group.

hr = pGroup->Add(_bstr_t("WinNT://Fabrikam/jeff"));
if(FAILED(hr)){goto Cleanup;}

Cleanup:
    if(pGroup)
        pGroup->Release();

    return hr;
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[Binding to an Object Using a SID](https://learn.microsoft.com/windows/desktop/AD/binding-to-an-object-using-a-sid)

[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup)

[IADsGroup Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsgroup-property-methods)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)
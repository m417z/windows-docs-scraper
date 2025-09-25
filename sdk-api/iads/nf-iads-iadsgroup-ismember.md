# IADsGroup::IsMember

## Description

The **IADsGroup::IsMember** method determines if a directory service object is an immediate member of the group. This method does not verify membership in any nested groups.

## Parameters

### `bstrMember`

Contains the ADsPath of the directory service object to verify membership. This ADsPath must use the same ADSI provider used to bind to the group. For example, if the group was bound to using the LDAP provider, this ADsPath must also use the LDAP provider.

### `bMember` [out]

Pointer to a **VARIANT_BOOL** value that receives **VARIANT_TRUE** if the object is an immediate member of the group or **VARIANT_FALSE** otherwise.

## Return value

This method supports the standard return values, including **S_OK**. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Although you can add or remove a security principal to or from a group using the member SID through the WinNT provider, the **IADsGroup.IsMember** method does not support using a SID ADsPath for verification if a member belongs to a group through the WinNT provider.

The **IADsGroup::IsMember** method will only work correctly if the group and the object are in the same domain. If the object is in a different domain than the group, **IADsGroup::IsMember** will always return **VARIANT_FALSE**.

#### Examples

The following code example adds the "jeffsmith" user to the "Administrators" group on the "Fabrikam" domain and then reports that the user is now a member of the group.

```vb
Dim grp As IADsGroup
On Error GoTo Cleanup

Set grp = GetObject("WinNT://Microsoft/Administrators")
grp.Add ("WinNT://Fabrikam/jeffsmith")
Debug.Print grp.IsMember("WinNT://Fabrikam/jeffsmith ") ' Should be TRUE.

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set grp = Nothing
```

The following code example verifies that a user belongs to a group before adding it to the group.

```cpp
IADsGroup *pGroup = NULL;
HRESULT hr = S_OK;
LPWSTR adsPath = L"WinNT://Fabrikam/Administrators";
BSTR bstr = NULL;

hr = ADsGetObject(adsPath, IID_IADsGroup, (void**)&pGroup);

if(FAILED(hr))
{
    goto Cleanup;
}

hr = pGroup->get_Description(&bstr);
if(FAILED(hr))
{
    goto Cleanup;
}

printf("Description: %S\n",bstr);
SysFreeString(bstr);

VARIANT_BOOL inG=false;
hr = pGroup->IsMember(CComBSTR("WinNT://Microsoft/SecUser"), &inG);

if (inG )
{
    printf("already in the group.\n");
}
else
{
    hr = pGroup->Add(CComBSTR("WinNT://Microsoft/SecUser"));
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    printf("user added.\n");
}

Cleanup:
if(pGroup)
{
    pGroup->Release();
}
if(bstr)
{
    SysFreeString(bstr);
}

return hr;
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup)

[IADsGroup Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsgroup-property-methods)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)
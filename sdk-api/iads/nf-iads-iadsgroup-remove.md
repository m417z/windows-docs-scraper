# IADsGroup::Remove

## Description

The **IADsGroup::Remove** method removes the specified user object from this group. The operation does not remove the group object itself even when there is no member remaining in the group.

## Parameters

### `bstrItemToBeRemoved` [in]

Contains a **BSTR** that specifies the ADsPath of the object to remove from the group. For more information about this parameter, see the Remarks section.

## Return value

The following are the most common return values. For more information about return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

If the LDAP provider is used to bind to the [IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup) object, the same form of ADsPath must be specified in the *bstrItemToBeRemoved* parameter. For example, if the ADsPath used to bind to the **IADsGroup** object includes a server, the ADsPath in the *bstrItemToBeRemoved* parameter must contain the same server prefix. Likewise, if a serverless path is used to bind to the **IADsGroup** object, the *bstrItemToBeRemoved* parameter must also contain a serverless path. The exception is when adding or removing a member using a GUID or SID ADsPath. In this case, a serverless path should always be used in *bstrItemToBeRemoved*.

You can use a SID in the ADsPath to remove a security principal from the group through the WinNT provider. For example, suppose the SID of a user, "Fabrikam\jeffsmith", is S-1-5-21-35135249072896, the following statement:

```vb
Dim group As IADsGroup
group.Remove("WinNT://S-1-5-21-35135249072896")
```

is equivalent to

```vb
Dim group As IADsGroup
group.Remove("WinNT://Fabrikam/jeffsmith")
```

Removing a member using its SID through the WinNT provider is a new feature in Windows 2000 and the DSCLIENT package.

#### Examples

The following code example removes a user account from a group.

```vb
Dim grp As IADsGroup
On Error GoTo Cleanup

Set grp = GetObject("WinNT://Fabrikam/Administrators")
grp.Remove ("WinNT://Fabrikam/jeffsmith")

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set grp = Nothing
```

The following code example removes a user from a group.

```cpp
IADsGroup *pGroup = NULL;
HRESULT hr = S_OK;
LPWSTR usrPath = L"WinNT://Fabrikam/jeffsmith";
LPWSTR grpPath = L"WinNT://Fabrikam/Administrators";

hr = ADsGetObject(grpPath, IID_IADsGroup, (void**)&pGroup);
if(FAILED(hr)){goto Cleanup;}

hr = pGroup->Remove(CComBSTR(usrPath));
if(FAILED(hr)){goto Cleanup;}

Cleanup:
    if(pGroup)
        pGroup->Release();
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup)

[IADsGroup Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsgroup-property-methods)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)
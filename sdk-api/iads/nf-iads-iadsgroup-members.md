# IADsGroup::Members

## Description

The **IADsGroup::Members** method retrieves a collection of the immediate members of the group. The collection does not include the members of other groups that are nested within the group.

The default implementation of this method uses [LsaLookupSids](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupsids) to query name information for the group members. LsaLookupSids has a maximum limitation of 20480 SIDs it can convert, therefore that limitation also applies to this method.

## Parameters

### `ppMembers` [out]

Pointer to an [IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers) interface pointer that receives the collection of group members. The caller must release this interface when it is no longer required.

## Return value

This method supports the standard return values, including **S_OK**. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The [IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)**Members** method will use the same provider.

#### Examples

The following code example enumerates all members of a group.

```vb
Dim grp As IADsGroup
Dim memberList As IADsMembers
Dim member As IADs

On Error GoTo Cleanup

Set grp = GetObject("WinNT://Microsoft/Administrators")
Set memberList = grp.Members
For Each m In memberList
    Set member = m
    Debug.Print member.Name & "(" & member.Class & ")"
Next

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set grp = Nothing
    Set member = Nothing
    Set memberList = Nothing
```

The following code example enumerates all members of a group.

```cpp
HRESULT EnumerateGroupMembers(IADsGroup *pGroup)
{
    IADsMembers *pMembers;
    HRESULT hr = S_OK;
    hr = pGroup->Members(&pMembers);
    if(FAILED(hr)){goto Cleanup;}

    hr = EnumMembers(pMembers);  // For more information and a code
                                    example, see IADsMembers::get__NewEnum.
    if(FAILED(hr)){goto Cleanup;}

Cleanup:
    if(pMembers)
        pMembers->Release();

    return hr;
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup)

[IADsGroup Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsgroup-property-methods)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)
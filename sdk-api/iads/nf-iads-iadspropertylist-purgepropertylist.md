# IADsPropertyList::PurgePropertyList

## Description

The **IADsPropertyList::PurgePropertyList** method deletes all items from the property list.

## Return value

This method supports the standard HRESULT return values, including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When the **PurgePropertyList** method is called, all the items are removed from the cache. Thus, calling [GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-getpropertyitem) after that will generate an error. Be aware that **PurgePropertyList** only affects the contents of the cache and does not affect the properties on the actual object in the directory; that is, calling [SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) after calling **PurgePropertyList** does not delete the properties on the directory object.

#### Examples

The following code example shows how to implement **IADsPropertyList::PurgePropertyList**.

```vb
Dim propList As IADsPropertyList

On Error GoTo Cleanup

Set propList = GetObject("LDAP://dc03/DC=Fabrikam,DC=com")
propList.GetInfo

propList.PurgePropertyList

'- None of GetPropertyItem should work, because the list is purged.
'- The following line should generate error.
Set propEntry = propList.GetPropertyItem("adminDescription", ADSTYPE_CASE_IGNORE_STRING)

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If

    Set propList = Nothing

```

The following code example shows the effect produced by a call to **IADsPropertyList::PurgePropertyList**. For more information about the **GetPropertyCache** function and a code example, see [IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist).

```cpp
IADsPropertyList *GetPropertyCache(LPWSTR);

void TestPurgePropertyList()
{
    IADsPropertyList *pList;
    pList=GetPropertyCache(L"WinNT://myComputer,computer");

    long count;

    if(pList)
    {
        pList->get_PropertyCount(&count);
        printf("Number of properties before purging: %d\n",count);

        count = -1;
        pList->PurgePropertyList();
        pList->get_PropertyCount(&count);
        printf("Number of properties after purging: %d\n",count);
    }
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist)

[IADsPropertyList Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertylist-property-methods)

[IADsPropertyList::GetPropertyItem](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-getpropertyitem)
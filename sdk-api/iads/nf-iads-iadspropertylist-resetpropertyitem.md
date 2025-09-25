# IADsPropertyList::ResetPropertyItem

## Description

The **IADsPropertyList::ResetPropertyItem** method removes the specified item from the list; that is, from the cache. You can specify the item to be removed by name (as a string) or by index (as an integer).

## Parameters

### `varEntry` [in]

Entry to be reset.

## Return value

This method supports the standard **HRESULT** return values, including **S_OK**. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

**ResetPropertyItem** only affects the contents of the cache and does not affect the properties on the actual object in the directory; that is calling [SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) after calling **ResetPropertyItem** does not delete the properties on the directory object.

#### Examples

The following code example shows how to implement **ResetPropertyItem**.

```vb
Dim propList As IADsPropertyList

On Error GoTo Cleanup

Set propList = GetObject("LDAP://DC=Fabrikam,DC=com")

'--- Now modify the cache using PutPropertyItem
Set propVal = New PropertyValue
'--- Property Value-----
propVal.CaseIgnoreString = "Fabrikam"
propVal.ADsType = ADSTYPE_CASE_IGNORE_STRING

'--- Property Entry ----
Set propEntry = New PropertyEntry
propEntry.Name = "adminDescription"
propEntry.Values = Array(propVal)
propEntry.ControlCode = ADS_PROPERTY_UPDATE
propEntry.ADsType = ADS_CASE_IGNORE_STRING

' --- Property List----
propList.PutPropertyItem (propEntry)

' Commit to the directory. Without this, the changes take place only in the cache.
propList.SetInfo

propList.GetInfo
Debug.Print " Number of Properties = " & propList.PropertyCount
propList.ResetPropertyItem "adminDescription"

' the property count should have been reduced by one.
Debug.Print "Number of properties = " & propList.PropertyCount

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set propList = Nothing
    Set propVal = Nothing
    Set propEntry = Nothing

```

The following code example shows the effect produced by a call to **IADsPropertyList::ResetPropertyItem**. For more information and the listing of the **GetPropertyCache** function, see [IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist). For more information and the listing of the **GetNextEntry** and **PropertyItem** functions, see [IADsPropertyList::Next](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-next) and [IADsPropertyList::Item](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-item) respectively.

```cpp
IADsPropertyList *GetPropertyCache(LPWSTR);
IADsPropertyEntry *GetNextEntry(IADsPropertyList *);
IADsPropertyEntry *PropertyItem(IADsPropertyList *,LPWSTR);

void ResetItem(IADsPropertyList *pList, LPWSTR item)
{
    VARIANT var;
    VariantInit(&var);

    if(!pList)
    {
        item = NULL;
        return;
    }

    V_BSTR(&var)=SysAllocString(item);
    V_VT(&var)=VT_BSTR;

    pList->ResetPropertyItem(var);
    VariantClear(&var);
}

void TestResetItem()
{
    IADsPropertyEntry *pEntry = NULL;
    IADsPropertyList *pList = NULL;
    long count;
    BSTR bstr;
    HRESULT hr;

    pList = GetPropertyCache(L"WinNT://myComputer,computer");

    hr = pList->get_PropertyCount(&count);
    if(SUCCEEDED(hr))
    {
        printf(" Count before item reset : %d\n",count);
    }

    printf("Walking up the property list before item reset: \n");
    for (int i=0; i<count; i++)
    {
        pEntry = GetNextEntry(pList);
        hr = pEntry->get_Name(&bstr);
        if(SUCCEEDED(hr))
        {
            printf("   Name : %S\n",bstr);
            SysFreeString(bstr);
        }
    }

    pList->Reset();   // Move the cursor to the beginning of the list.

    ResetItem(pList, L"Owner");

    hr = pList->get_PropertyCount(&count);
    if(SUCCEEDED(hr))
    {
        printf(" Count after item reset : %d\n",count);
    }

    printf("Walking up the property list after item reset: \n");

    for (i=0; i<count; i++)
    {
        pEntry = GetNextEntry(pList);
        hr = pEntry->get_Name(&bstr);
        if(SUCCEEDED(hr))
        {
            printf("   Name : %S\n",bstr);
            SysFreeString(bstr);
        }
    }

    pEntry->Release();
    pList->Release();
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist)

[IADsPropertyList Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertylist-property-methods)

[IADsPropertyList::Item](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-item)

[IADsPropertyList::Next](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-next)
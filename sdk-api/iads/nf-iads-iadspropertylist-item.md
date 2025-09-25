# IADsPropertyList::Item

## Description

The **IADsPropertyList::Item** method retrieves the specified property item from the list.

## Parameters

### `varIndex` [in]

The **VARIANT** that contains the index or name of the property to be retrieved.

### `pVariant` [in, out]

Address of a caller-allocated **VARIANT** variable. On return, the **VARIANT** contains the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) pointer to the object which implements the [IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry) interface for the attribute retrieved.

## Return value

This method supports the standard HRESULT return values, including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

You must clear *pVariant* using **VariantClear** when the value returned by the **Item** method is no longer required.

#### Examples

The following code example shows how to enumerate all the entries with the **Item** method.

```vb
Dim propList As IADsPropertyList
Dim propEntry As IADsPropertyEntry
Dim count As Long

On Error GoTo Cleanup

Set propList = GetObject("LDAP://dc02/DC=Fabrikam,DC=com")

propList.GetInfo
count = propList.PropertyCount
Debug.Print "No of Property Found: " & count

'==== Getting the property list item with Name ==================
Set propEntry = propList.Item("uSNCreated")
Debug.Print propEntry.Name
Debug.Print propEntry.ADsType

' to examine property entries by name and type
For i = 0 To count - 1
    '==== Getting the property list item with Number =============
    Set propEntry = propList.Item(i)
    Debug.Print propEntry.Name
    Debug.Print propEntry.ADsType
Next

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If

    Set propList = Nothing
    Set propEntry = Nothing

```

The following code example shows how to retrieve the **Owner** property of a computer using the **IADsPropertyList::Item** method. For more information about the **GetPropertyCache** function and a code example, see [IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist).

```cpp
////////////////////////////////////////
// function:    PropertyItem
//    input:    PropertyList,
//              name of the item
//   output:    Property entry
//     uses:    IADsPropertyList::Item
////////////////////////////////////////
IADsPropertyEntry *PropertyItem(
         IADsPropertyList *pList,
         LPWSTR item)
{
    IADsPropertyEntry *pEntry;
    VARIANT varEntry, varItem;

    if(!pList || !item)
    {
        _tprintf(TEXT("Invalid parameter..."));
        return NULL;
    }

    VariantInit(&varItem);
    VariantInit(&varEntry);

    // get a property entry
    V_BSTR(&varItem)= SysAllocString(item);
    V_VT(&varItem)=VT_BSTR;
    HRESULT hr = pList->Item(varItem ,&varEntry);
    hr = V_DISPATCH(&var)->QueryInterface(
                        IID_IADsPropertyEntry,
                        (void**)&pEntry);
    VariantClear(&varItem);
    VariantClear(&varEntry);
    return pEntry;
}

///////////////////////////////////////
// examine a property entry
///////////////////////////////////////
IADsPropertyList *pList; pList=GetPropertyCache(L"WinNT://myComputer,computer");

IADsPropertyEntry *pEntry;
pEntry = PropertyItem(pList, L"Owner");

if(pEntry)
{
    HRESULT hr;
    BSTR bstr;
    long ln;

    hr = pEntry->get_Name(&bstr);
    if(SUCCEEDED(hr))
    {
        SysFreeString(bstr);
    }
    printf(" Name : %S\n", bstr);

    pEntry->get_ADsType(&ln);
    if(SUCCEEDED(hr))
    {
        printf(" Type : %d\n", ln);
    }

    pEntry->get_ControlCode(&ln);
    if(SUCCEEDED(hr))
    {
        printf(" Code %d\n",ln);
    }
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry)

[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist)

[IADsPropertyList Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertylist-property-methods)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)
# IADsPropertyList::Next

## Description

The **IADsPropertyList::Next** method gets the next item in the property list. The returned item is a Property Entry object.

## Parameters

### `pVariant` [out]

Address of a caller-allocated variable that contains the value of the next item in the property list. The return value of **VT_DISPATCH** refers to an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer to an object implementing the [IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry) interface.

## Return value

This method supports the standard **HRESULT** values, including **S_OK** if the item is obtained. When the last item in the list is returned, the return value that is returned will differ depending on which provider is used. The following codes are used to indicate that the last item in the list was obtained:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

You must clear *pVariant* using **VariantClear** when the value returned by the **Next** method is no longer required.

#### Examples

The following code example shows how to walk through a property list using the **Next** method.

```vb
Dim propList As IADsPropertyList
Dim v as Variant
Dim propVal As IADsPropertyValue

On Error Resume Next

Set propList = GetObject("LDAP://dc01/DC=Fabrikam,DC=com")

propList.GetInfo
Set v = propList.Next()
While (Not (IsNull(v)) And Err.Number = 0)
    Set propEnty = v
    Debug.Print v.Name
    Debug.Print v.AdsType

    Set v = propList.Next
Wend
```

The following C++ code example shows how to work the **IADsPropertyList::Next** method.

```cpp
////////////////////////////////////
// Function used to retrieve an entry using the
// IADsPropertyList::Next method.

//     name: GetNextEntry
//    input: IADsPropertyList*
//   return: IADsPropertyEntry
//     uses: IADsPropertyList::Next
/////////////////////////////////////////////////////////
IADsPropertyEntry* GetNextEntry(IADsPropertyList* pList)
{
    VARIANT var;
    VariantInit(&var);
    IADsPropertyEntry *pEntry;

    if(!pList)
    {
        _tprintf("An error has occurred.");
        return NULL;
    }

    HRESULT hr = pList->Next(&var);
    hr = V_DISPATCH(&var)->QueryInterface(IID_IADsPropertyEntry,
                                         (void**)&pEntry);
    VariantClear(&var);
    return pEntry;
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry)

[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist)

[IADsPropertyList Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertylist-property-methods)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)
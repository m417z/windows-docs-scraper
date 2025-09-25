# IADsPropertyValue::Clear

## Description

The **IADsPropertyValue::Clear** method clears the current values of the property value object.

## Return value

This method supports the standard HRESULT return values, including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

None

#### Examples

The following code example shows how to use **IADsPropertyValue::Clear** to clear the value of the "description" property from a property list.

```vb
Dim propList As IADsPropertyList
Dim propEntry As IADsPropertyEntry
Dim propVal As IADsPropertyValue

On Error GoTo Cleanup

' Get the property list.
Set propList = GetObject("LDAP://dc01/DC=Fabrikam,DC=com")
propList.GetInfo

' Get a property entry. If you know the exact type of the property,
' replace ADSTYPE_UNKNOWN with that type.
Set propEntry = propList.GetPropertyItem("description", ADSTYPE_UNKNOWN)

' Clear all the values of the property entry.
For Each v In propEntry.Values
    Set propVal = v
    propVal.Clear
Next

propList.SetInfo

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If

    Set propList = Nothing
    Set propEntry = Nothing
    Set propVal = Nothing
```

The following code example shows how to use **IADsPropertyValue::Clear** to clear the value of the "description" property from a property list.

```cpp
#include <activeds.h>
#include <stdio.h>

IADsPropertyList *pList = NULL;
IADsPropertyEntry *pEntry = NULL;
IADsPropertyValue *pVal = NULL;
IADs *pObj = NULL;
VARIANT var, varItem;
BSTR valStr;
IEnumVARIANT *pEnum = NULL;
LONG lstart, lend;

VariantInit(&var);
VariantInit(&varItem);

// Bind to the directory object.
HRESULT hr = ADsGetObject(L"LDAP://dc01/DC=Fabrikam,DC=com",
                          IID_IADsPropertyList,
                          (void**)&pList);
if(FAILED(hr)){goto Cleanup;}

// Initialize the property cache.
hr = pList->QueryInterface(IID_IADs,(void**)&pObj);
if(FAILED(hr)){goto Cleanup;}

pObj->GetInfo();
pObj->Release();

// Get a property entry.
hr = pList->GetPropertyItem(CComBSTR("description"), ADSTYPE_UNKNOWN, &var);
if(FAILED(hr)){goto Cleanup;}

pList->Release();
hr = V_DISPATCH(&var)->QueryInterface(IID_IADsPropertyEntry,
                                      (void**)&pEntry);
if(FAILED(hr)){goto Cleanup;}
VariantClear(&var);

// Get the value array of the property entry.
hr = pEntry->get_Values(&var);
if(FAILED(hr)){goto Cleanup;}
SAFEARRAY *sa = V_ARRAY( &var );

// Get the lower and upper bound, iterate, and print the values.
hr = SafeArrayGetLBound( sa, 1, &lstart );
hr = SafeArrayGetUBound( sa, 1, &lend );
printf(" Property value(s) = ");
for ( long idx=lstart; idx < lend+1; idx++ )    {
    hr = SafeArrayGetElement( sa, &idx, &varItem );
    hr = V_DISPATCH(&varItem)->QueryInterface(IID_IADsPropertyValue,
                                              (void**)&pVal);
    VariantClear(&varItem);
    hr = pVal->Clear();
    if(FAILED(hr)){goto Cleanup;}
}

pList->SetInfo();

Cleanup:
    if(pList)
        pList->Release();

    if(pEntry)
        pEntry->Release();

    if(pVal)
        pVal->Release();

    if(pObj)
        pObj->Release();

    if(pEnum)
        pEnum->Release();

    if(valStr)
        SysFreeString(valStr);

    VariantClear(&var);
    VariantClear(&varItem);

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsPropertyValue](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue)

[IADsPropertyValue Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods)
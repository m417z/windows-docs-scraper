# IADsPropertyList::GetPropertyItem

## Description

The **IADsPropertyList::GetPropertyItem** method retrieves the item that matches the name from the list.

## Parameters

### `bstrName` [in]

Contains the name of the requested property.

### `lnADsType` [in]

Contains one of the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) enumeration values that determines the data type to be used in interpreting the requested property. If the type is unknown, this parameter can be set to **ADSTYPE_UNKNOWN**. For schemaless servers, the user must specify the type.

### `pVariant` [in, out]

Address of a caller-allocated **VARIANT** variable. On return, the **VARIANT** contains the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer of the object which implements the [IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry) interface for the retrieved attribute.

Any memory allocated for this parameter must be released with the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function when the data is no longer required.

## Return value

This method supports the standard **HRESULT** return values, including **S_OK**. If the requested property item is not found, the method returns **ADS_PROPERTY_NOT_FOUND**. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The property of the [IADsPropertyValue](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue) object returned by this method that can be used will depend on the type specified in *lnADsType*. The following table maps the data type to the appropriate [IADsPropertyEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyentry) property.

| *lnADsType* value | [IADsPropertyValue](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertyvalue) property to use |
| --- | --- |
| **ADSTYPE_INVALID** | Not available. |
| **ADSTYPE_DN_STRING** | [DNString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_CASE_EXACT_STRING** | [CaseExactString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_CASE_IGNORE_STRING** | [CaseIgnoreString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_PRINTABLE_STRING** | [PrintableString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_NUMERIC_STRING** | [NumericString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_BOOLEAN** | [Boolean](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_INTEGER** | [Integer](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_OCTET_STRING** | [OctetString](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_UTC_TIME** | [UTCTime](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_LARGE_INTEGER** | [LargeInteger](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_PROV_SPECIFIC** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (VT_ARRAY \| VT_UI1). |
| **ADSTYPE_OBJECT_CLASS** | Not available. |
| **ADSTYPE_CASEIGNORE_LIST** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsCaseIgnoreList). |
| **ADSTYPE_OCTET_LIST** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsOctetList). |
| **ADSTYPE_PATH** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsPath). |
| **ADSTYPE_POSTALADDRESS** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsPostalAddress). |
| **ADSTYPE_TIMESTAMP** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsTimestamp). |
| **ADSTYPE_BACKLINK** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsBackLink). |
| **ADSTYPE_TYPEDNAME** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsTypedName). |
| **ADSTYPE_HOLD** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsHold). |
| **ADSTYPE_NETADDRESS** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsNetAddress). |
| **ADSTYPE_REPLICAPOINTER** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsReplicaPointer). |
| **ADSTYPE_FAXNUMBER** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsFaxNumber). |
| **ADSTYPE_EMAIL** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsEmail). |
| **ADSTYPE_NT_SECURITY_DESCRIPTOR** | [SecurityDescriptor](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertyvalue-property-methods) |
| **ADSTYPE_UNKNOWN** | Not available. |
| **ADSTYPE_DN_WITH_BINARY** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsDNWithBinary). |
| **ADSTYPE_DN_WITH_STRING** | Use [IADsPropertyValue2::GetObjectProperty](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertyvalue2-getobjectproperty) (IADsDNWithString). |

#### Examples

The following code example shows how to retrieve a property entry using the **GetPropertyItem** method.

```vb
Const ADSTYPE_CASE_IGNORE_STRING = 3
Dim propList As IADsPropertyList
Dim propEntry As IADsPropertyEntry
Dim propVal As IADsPropertyValue

Set propList = GetObject("LDAP://dc01/DC=Fabrikam,DC=com")
propList.GetInfo

Set propEntry = propList.GetPropertyItem("dc", ADSTYPE_CASE_IGNORE_STRING)

For Each v In propEntry.Values
    Set propVal = v

    ' Use the CaseIgnoreString property because the ADSTYPE_CASE_IGNORE_STRING
    ' type was requested in GetPropertyItem.
    Debug.Print propVal.CaseIgnoreString
Next

Set propList = Nothing
Set propEntry = Nothing
Set propVal = Nothing

```

The following code example shows how to retrieve a property entry using the **GetPropertyItem** method. It assumes that the [IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist) interface has been properly retrieved. For more information about how to load the property cache, see the [GetPropertyCache](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist) example function in **IADsPropertyList**.

```cpp
#include <activeds.h>
#include <stdio.h>

/////////////////////////////////////////////////////////
// Function to retrieve a specified property entry
// using the IADsPropertyList::GetPropertyItem method.
/////////////////////////////////////////////////////////
IADsPropertyEntry *GetPropertyItem(
      IADsPropertyList *pList,
      BSTR entryName,
      long entryType)
{
   IADsPropertyEntry *pEntry;
   VARIANT var;
   VariantInit(&var);

   if(!pList || !entryName)
   {
      _tprintf("Invalid argument...");
      return NULL;
   }

   // Get a property entry.
   hr = pList->GetPropertyItem(entryName, entryType, &var);
   hr = V_DISPATCH(&var)->QueryInterface(IID_IADsPropertyEntry,
                                         (void**)&pEntry);
   VariantClear(&var);

   return pEntry;
}

///////////////////////////////////////////////////////
// Examine a property entry.
///////////////////////////////////////////////////////
IADsPropertyList *pList = NULL;
IADsPropertyEntry *pEntry = NULL;

pList = GetPropertyCache(L"LDAP://dc01/DC=Fabrikam,DC=COM");

if(pList)
{
    pEntry = GetPropertyItem(pList, L"dc", ADSTYPE_CASE_IGNORE_STRING);
}

if(pEntry)
{
    BSTR nm;
    HRESULT hr = pEntry->get_Name(&nm);
    if(SUCCEEDED(hr))
    {
        printf("Property name = %S\n",nm);
        SysFreeString(nm);
    }
}

if(pList)
    pList->Release();
if(pEntry)
    pEntry->Release();
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist)

[IADsPropertyList Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadspropertylist-property-methods)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear)
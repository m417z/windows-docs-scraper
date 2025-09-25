# IDirectoryObject::SetObjectAttributes

## Description

The **IDirectoryObject::SetObjectAttributes** method modifies data in one or more specified object attributes defined in the [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structure.

## Parameters

### `pAttributeEntries` [in]

Provides an array of attributes to be modified. Each attribute contains the name of the attribute, the operation to perform, and the attribute value, if applicable. For more information, see the [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structure.

### `dwNumAttributes` [in]

Provides the number of attributes to be modified. This value should correspond to the size of the *pAttributeEntries* array.

### `pdwNumAttributesModified` [out]

Provides a pointer to a **DWORD** variable that contains the number of attributes modified by the **SetObjectAttributes** method.

## Return value

This method returns the standard return values, including S_OK when the attributes are set successfully.

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

In Active Directory (LDAP provider), the **IDirectoryObject::SetObjectAttributes** method is a transacted call. The attributes are either all committed or discarded. Other directory providers may not transact the call.

Active Directory does not allow duplicate values on a multi-valued attribute. However, if you call **SetObjectAttributes** to append a duplicate value to a multi-valued attribute of an Active Directory object, the **SetObjectAttributes** call succeeds but the duplicate value is ignored.

Similarly, if you use **SetObjectAttributes** to delete one or more values from a multi-valued property of an Active Directory object, the operation succeeds even if any or all of the specified values are not set for the property

#### Examples

The following C++ code example sets the **sn** attribute of a user object to the value of **Price** as a case-insensitive string.

```cpp
HRESULT hr;
IDirectoryObject *pDirObject=NULL;
DWORD  dwReturn;
ADSVALUE  snValue;
ADS_ATTR_INFO attrInfo[] = { {L"sn",ADS_ATTR_UPDATE, ADSTYPE_CASE_IGNORE_STRING, &snValue, 1} };
DWORD dwAttrs = sizeof(attrInfo)/sizeof(ADS_ATTR_INFO);

snValue.dwType=ADSTYPE_CASE_IGNORE_STRING;
snValue.CaseIgnoreString = L"Price";

hr = ADsGetObject(L"LDAP://CN=Jeff Smith,OU=Sales,DC=Fabrikam,DC=com",
        IID_IDirectoryObject,
        (void**) &pDirObject );

if ( SUCCEEDED(hr) )
{
    hr = pDirObject->SetObjectAttributes(attrInfo, dwAttrs, &dwReturn);

    pDirObject->Release();
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)
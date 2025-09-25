# IDirectoryObject::GetObjectAttributes

## Description

The **IDirectoryObject::GetObjectAttributes** method retrieves one or more specified attributes of the directory service object.

## Parameters

### `pAttributeNames` [in]

Specifies an array of names of the requested attributes.

To request all of the object's attributes, set *pAttributeNames* to **NULL** and set the *dwNumberAttributes* parameter to (DWORD)-1.

### `dwNumberAttributes` [in]

Specifies the size of the *pAttributeNames* array. If -1, all of the object's attributes are requested.

### `ppAttributeEntries` [out]

Pointer to a variable that receives a pointer to an array of [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structures that contain the requested attribute values. If no attributes could be obtained from the directory service object, the returned pointer is **NULL**.

### `pdwNumAttributesReturned` [out]

Pointer to a **DWORD** variable that receives the number of attributes retrieved in the *ppAttributeEntries* array.

## Return value

This method returns the standard values, as well as the following:

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

ADSI allocates the memory for the array of [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structures returned in the *ppAttributeEntries* parameter. The caller must call [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) to free the array.

The order of attributes returned in *ppAttributeEntries* is not necessarily the same as requested in *pAttributeNames*.

The **IDirectoryObject::GetObjectAttributes** method attempts to read the schema definition of the requested attributes so it can return the attribute values in the appropriate format in the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures contained in the [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structures. However, **GetObjectAttributes** can succeed even when the schema definition is not available, in which case the **dwADsType** member of the **ADS_ATTR_INFO** structure returns ADSTYPE_PROV_SPECIFIC and the value is returned in an [ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific) structure. When you process the results of a **GetObjectAttributes** call, verify **dwADsType** to ensure that the data was returned in the expected format.

#### Examples

The following code example shows how the **IDirectoryObject::GetObjectAttributes** method can be used.

```cpp
HRESULT hr;
IDirectoryObject *pDirObject = NULL;

hr = ADsGetObject(L"LDAP://CN=Jeff Smith,OU=Sales,DC=Fabrikam,DC=com",
                     IID_IDirectoryObject,
                     (void**) &pDirObject );

if ( SUCCEEDED(hr) )
{
    ADS_ATTR_INFO *pAttrInfo=NULL;
    DWORD dwReturn;
    LPWSTR pAttrNames[]={L"givenName",L"sn", L"otherTelephone" };
    DWORD dwNumAttr=sizeof(pAttrNames)/sizeof(LPWSTR);

    //////////////////////////////////////////////////////
    // Get attribute values requested.
    // Be aware that the order is not necessarily the
    // same as requested using pAttrNames.
    //////////////////////////////////////////////////////
    hr = pDirObject->GetObjectAttributes( pAttrNames,
                                        dwNumAttr,
                                        &pAttrInfo,
                                        &dwReturn );

    if ( SUCCEEDED(hr) )
    {
        for(DWORD idx = 0; idx < dwReturn; idx++ )
        {
            if ( _wcsicmp(pAttrInfo[idx].pszAttrName,L"givenName") == 0 )
            {
                switch (pAttrInfo[idx].dwADsType)
                {
                    case ADSTYPE_CASE_IGNORE_STRING:
                        printf("First Name: %S\n", pAttrInfo[idx].pADsValues->CaseIgnoreString);
                        break;

                    case ADSTYPE_PROV_SPECIFIC:
                        printf("First Name: %S\n", pAttrInfo[idx].pADsValues->ProviderSpecific.lpValue);
                        break;

                    default:
                        printf("Invalid ADsType: %d\n", pAttrInfo[idx].dwADsType);
                        break;
                }
            }
            else if ( _wcsicmp(pAttrInfo[idx].pszAttrName, L"sn") == 0 )
            {
                switch (pAttrInfo[idx].dwADsType)
                {
                    case ADSTYPE_CASE_IGNORE_STRING:
                        printf("Last Name: %S\n", pAttrInfo[idx].pADsValues->CaseIgnoreString);
                        break;

                    case ADSTYPE_PROV_SPECIFIC:
                        printf("Last Name: %S\n", pAttrInfo[idx].pADsValues->ProviderSpecific.lpValue);
                        break;

                    default:
                        printf("Invalid ADsType: %d\n", pAttrInfo[idx].dwADsType);
                        break;
                }
            }
            else if ( _wcsicmp(pAttrInfo[idx].pszAttrName, L"otherTelephone") == 0  )
            {   // Print the multi-valued property, "Other Telephones".
                switch (pAttrInfo[idx].dwADsType)
                {
                    case ADSTYPE_CASE_IGNORE_STRING:
                        printf("Other Telephones:");
                        for (DWORD val=0; val < pAttrInfo[idx].dwNumValues; val++)
                        printf("  %S\n", pAttrInfo[idx].pADsValues[val].CaseIgnoreString);
                        break;

                    case ADSTYPE_PROV_SPECIFIC:
                        printf("Other Telephones:");
                        for (DWORD val=0; val < pAttrInfo[idx].dwNumValues; val++)
                        printf("  %S\n", pAttrInfo[idx].pADsValues[val].CaseIgnoreString);
                        break;

                    default:
                        printf("Other Telephones:");
                        for (DWORD val=0; val < pAttrInfo[idx].dwNumValues; val++)
                        printf("  %S\n", pAttrInfo[idx].pADsValues[val].CaseIgnoreString);
                        break;
                }
            }
        }

        /////////////////////////////////////////////////////////////
        // Use FreeADsMem for all memory obtained from the ADSI call.
        /////////////////////////////////////////////////////////////
        FreeADsMem( pAttrInfo );

    }

    pDirObject->Release();
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)
# IDirectoryObject::CreateDSObject

## Description

The **IDirectoryObject::CreateDSObject** method creates a child of the current directory service object.

## Parameters

### `pszRDNName` [in]

Provides the relative distinguished name (relative path) of the object to be created.

### `pAttributeEntries` [in]

An array of [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structures that contain attribute definitions to be set when the object is created.

### `dwNumAttributes` [in]

Provides a number of attributes set when the object is created.

### `ppObject` [out]

Provides a pointer to the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface on the created object.

## Return value

This method returns the standard return values, including S_OK for a successful operation. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Specify all attributes to be initialized on creation in the *pAttributeEntries* array. You may also specify optional attributes. When creating a directory object with this method, attributes with any of the string data types cannot be empty or zero-length.

#### Examples

The following C/C++ code example shows how to create a user object using the **IDirectoryObject::CreateDSObject** method.

```cpp
HRESULT    hr;
IDirectoryObject *pDirObject=NULL;
ADSVALUE   sAMValue;
ADSVALUE   uPNValue;
ADSVALUE   classValue;
LPDISPATCH pDisp;

ADS_ATTR_INFO  attrInfo[] =
{
   { L"objectClass", ADS_ATTR_UPDATE,
                       ADSTYPE_CASE_IGNORE_STRING, &classValue, 1 },
   {L"sAMAccountName", ADS_ATTR_UPDATE,
                       ADSTYPE_CASE_IGNORE_STRING, &sAMValue, 1},
   {L"userPrincipalName", ADS_ATTR_UPDATE,
                      ADSTYPE_CASE_IGNORE_STRING, &uPNValue, 1},
};
DWORD dwAttrs = sizeof(attrInfo)/sizeof(ADS_ATTR_INFO);

classValue.dwType = ADSTYPE_CASE_IGNORE_STRING;
classValue.CaseIgnoreString = L"user";

sAMValue.dwType=ADSTYPE_CASE_IGNORE_STRING;
sAMValue.CaseIgnoreString = L"jeffsmith";

uPNValue.dwType=ADSTYPE_CASE_IGNORE_STRING;
uPNValue.CaseIgnoreString = L"jeffsmith@Fabrikam.com";

hr = ADsGetObject(L"LDAP://OU=Sales,DC=Fabrikam,DC=com",
          IID_IDirectoryObject, (void**) &pDirObject );

if ( SUCCEEDED(hr) )
{
    hr = pDirObject->CreateDSObject( L"CN=Jeff Smith",  attrInfo,
                                    dwAttrs, &pDisp );

    if ( SUCCEEDED(hr) )
    {
         // Use the DS object.

         pDisp->Release();
    }

    pDirObject->Release();
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)
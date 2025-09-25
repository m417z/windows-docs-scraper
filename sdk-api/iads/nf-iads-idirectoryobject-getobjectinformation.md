# IDirectoryObject::GetObjectInformation

## Description

The **IDirectoryObject::GetObjectInformation** method retrieves a pointer to an [ADS_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_object_info) structure that contains data regarding the identity and location of a directory service object.

## Parameters

### `ppObjInfo` [out]

Provides the address of a pointer to an [ADS_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_object_info) structure that contains data regarding the requested directory service object. If *ppObjInfo* is **NULL** on return, **GetObjectInformation** cannot obtain the requested data.

## Return value

This method returns the standard return values, including **S_OK** when the data is obtained successfully. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The caller should call
the [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) helper function to release the [ADS_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_object_info) structure created by the **GetObjectInformation** function.

Automation clients must call [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo).

#### Examples

The following C++ code example shows how to retrieve the object data ([ADS_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_object_info)) using the **GetObjectInformation** method of an object (m_pDirObject) that implements the [IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject) interface.

```cpp
ADS_OBJECT_INFO *pInfo;
HRESULT hr;

hr = m_pDirObject->GetObjectInformation(&pInfo);
if (!SUCCEEDED(hr) )
{
   return;
}

//////////////////////////
// Show the attributes
/////////////////////////

printf("RDN: %S\n", pInfo->pszRDN);
printf("ObjectDN: %S\n", pInfo->pszObjectDN);
printf("Parent DN: %S\n", pInfo->pszParentDN);
printf("Class Name: %S\n", pInfo->pszClassName);
printf("Schema DN: %S\n", pInfo->pszSchemaDN);

///////////////////////////////////////////////////////////
// Remember to clean up the memory using FreeADsMem.
//////////////////////////////////////////////////////////
FreeADsMem( pInfo );
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_OBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_object_info)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)
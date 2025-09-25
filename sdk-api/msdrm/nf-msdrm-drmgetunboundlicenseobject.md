# DRMGetUnboundLicenseObject function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUnboundLicenseObject** function retrieves an object of a specified type in an unbound license.

## Parameters

### `hQueryRoot` [in]

A handle to a license or object in the license, created using **DRMGetUnboundLicenseObject** or [DRMParseUnboundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmparseunboundlicense).

### `wszSubObjectType` [in]

Name of the object to find.

### `iIndex` [in]

Zero-based index indicating which instance to retrieve, if more than one exists.

### `phSubQuery` [out]

The retrieved object. Call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) to close the handle.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Each object can have several instances within a license. A license may contain many rights objects, for example. In this case, it may be necessary to iterate through all the objects in this class by first calling [DRMGetUnboundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobjectcount) to get a count of existing objects, and then looping through all instances, starting at zero and incrementing the *iWhich* value by one. If a specific object is sought, each retrieved object can be queried for its attributes, such as its name.

This query will search only at the level immediately below the passed in object. So, for example, if the root license handle is passed in and the attribute to find is g_wszQUERY_OWNER, the query will find nothing because the OWNER object appears at the second level or deeper (counting the license root as level 0).

The *wszSubObjectType* parameter identifies an XrML node value as shown in the following example. Using g_wszQUERY_OBJECTTYPE in a query would return "Group Identity Licensor." The only object you can query for in an issuance license is g_wszQUERY_DISTRIBUTIONPOINT.

```cpp
<PRINCIPAL internal-id="1">
  <OBJECT type="Group Identity Licensor">
  <ID type="Group Identity">someone@example.com</ID>
  <NAME>Pavel's Group Identity</NAME>
  </OBJECT>
```

Call [DRMCloseQueryHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosequeryhandle) to close the object handle created by calling this function.

## See also

[DRMGetUnboundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattribute)

[DRMGetUnboundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattributecount)

[DRMGetUnboundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobjectcount)

[Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses)
# DRMGetUnboundLicenseObjectCount function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUnboundLicenseObjectCount** function counts the instances of an object within a specified branch of the license.

## Parameters

### `hQueryRoot` [in]

A handle to a license or object in the license, created using [DRMGetUnboundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobject) or [DRMParseUnboundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmparseunboundlicense).

### `wszSubObjectType` [in]

The type of XrML object to find. For more information, see Remarks.

### `pcSubObjects` [out]

Count of object instances one level down within the specified branch.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Certain objects, such as rights, may have multiple instances in a license. This function allows an application to iterate through instances of an object type by providing an upper bound in a loop when calling [DRMGetUnboundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobject). The value returned by this function, however, is one-based; subtract one from it when using it as a loop boundary.

This query will search only at the level immediately below the passed in object. So, for example, if the root license handle is passed in and the attribute to find is g_wszQUERY_OWNER, the query will find nothing because the OWNER appears at the second level or deeper (counting the license root as level 0).

## See also

[DRMGetUnboundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattribute)

[DRMGetUnboundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattributecount)

[DRMGetUnboundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobject)

[Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses)
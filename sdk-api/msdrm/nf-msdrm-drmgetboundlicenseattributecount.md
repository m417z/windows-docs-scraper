# DRMGetBoundLicenseAttributeCount function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetBoundLicenseAttributeCount** function retrieves the number of occurrences of an attribute in a license.

## Parameters

### `hQueryRoot` [in]

A handle to a license or license object, from [DRMGetBoundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobject) or [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

### `wszAttribute` [in]

Name of the attribute to count.

### `pcAttributes` [out]

Count of attribute occurrences.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Certain attributes, such as maximum use count, may appear in more than one branch of a license. This method returns a count of these occurrences, so that an application can iterate through them to access a particular one by using [DRMGetBoundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattribute).

The Active Directory Rights Management system exposes an object-oriented interface to the underlying license XrML. This function, along with other **DRMGetBoundLicense_xxx** functions, allows an application to navigate this structure. For more information, see [Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetBoundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattribute)

[DRMGetBoundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobject)

[DRMGetBoundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobjectcount)
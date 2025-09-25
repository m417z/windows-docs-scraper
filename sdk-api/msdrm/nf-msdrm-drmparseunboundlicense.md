# DRMParseUnboundLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMParseUnboundLicense** function creates a handle to an unbound license, to allow an application to navigate its objects and attributes. For more information, see Remarks.

## Parameters

### `wszCertificate` [in]

The leaf certificate on the license to be examined, in plain text (not encoded).

### `phQueryRoot` [out]

Pointer to a handle to the root object of the license. Call [DRMCloseQueryHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosequeryhandle) to close the handle.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is for querying unbound end-user licenses, and also for obtaining license acquisition URLs from issuance licenses. The unbound end-user license retrieved by [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) is a certificate chain. To properly query the unbound license itself, first call [DRMDeconstructCertificateChain](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdeconstructcertificatechain) to obtain the first element of the chain (item zero), which is the actual license.

An application can navigate this interface using various **DRMGetUnboundLicense_xxx** functions (for unbound licenses). To examine bound licenses, use the **DRMGetBoundLicense_xxx** functions.

Both bound and unbound licenses can be examined. Whether you decide to use a bound or an unbound license depends on whether you need to exercise the rights or just examine the license. Bound licenses can exist only after a secure environment has been created using [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment). Unbound licenses, however, do not require a secure environment.

The output of this function can be passed into one of the **DRMGetUnboundLicense_xxx** functions. The only object you can query for in an issuance license is g_wszQUERY_DISTRIBUTIONPOINT. The only attributes you can query for are g_wszQUERY_IDTYPE, g_wszQUERY_IDVALUE, g_wszQUERY_NAME, g_wszQUERY_ADDRESSTYPE, and g_wszQUERY_ADDRESSVALUE.

Call [DRMCloseQueryHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosequeryhandle) to close the unbound license handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses)
# DRMDeleteLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMDeleteLicense** function deletes a license, client licensor certificate, revocation list, or issuance license template.

## Parameters

### `hSession` [in]

A handle to a license storage session or client session. You can use a storage session handle to delete end-user licenses and revocation lists. You can use a client session handle to delete end-user licenses, rights account certificates, client licensor certificates, and issuance license templates.

You can retrieve a handle to a license storage session by using the [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) function. You can retrieve a handle to a client session by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function.

### `wszLicenseId` [in]

A pointer to a null-terminated string that contains the ID of the license or template to be deleted. The license ID can be found inside the **ID** element of the license XrML, by querying using the license querying functions and the **g_wszQUERY_CONTENTIDVALUE** constant. The template ID is a GUID. You can enumerate the GUIDs by calling the [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) function.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The AD RMS system does not check to determine whether out of date licenses or revocation lists are stored in the license store, even when acquiring a new license or revocation list for content already owned. Therefore, it is important to occasionally delete licenses or certificates. This can be a time-consuming process, so it might be best to perform this action occasionally or during program idle time.

If you delete an [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly), this function will not automatically delete associated revocation lists.

If you delete a license by using the content ID, the *hSession* parameter must be the handle of a client session.

License and certificate IDs can be enumerated by using [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense). If you already have the license or certificate you want to delete from the license store, you can query it for its ID (by using the [DRMParseUnboundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmparseunboundlicense) and [DRMGetUnboundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattribute) functions with the **g_wszQUERY_IDVALUE** constant) and pass the value into this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense)

[DRMGetUnboundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattribute)

[DRMParseUnboundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmparseunboundlicense)
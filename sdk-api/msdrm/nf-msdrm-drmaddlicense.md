# DRMAddLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMAddLicense** function adds an end-user license to the temporary or permanent license store.

## Parameters

### `hLicenseStorage` [in]

A handle to a license storage session, created using [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession).

### `uFlags` [in]

Value that specifies whether the temporary or permanent license store is used. This parameter can be one of the following values.

#### DRM_ADD_LICENSE_NOPERSIST

The end-user license is added to the temporary license store.

#### DRM_ADD_LICENSE_PERSIST

The end-user license is added to the permanent license store.

### `wszLicense` [in]

A pointer to null-terminated string that contains the end-user license chain to add to the temporary or permanent license store.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

An application can manage its own end-user licenses instead of submitting them to the computer's permanent license store. To do so, the application calls [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense) with **DRM_AL_NOPERSIST** specified. The application then retrieves the license from the license store using [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense), deletes the license from the license store using [DRMDeleteLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdeletelicense), and saves the end-user license itself. The temporary license store is destroyed when the reader session ends. To use the license the next time, the application must add it to the temporary license store using this function. **DRMAddLicense** can be called multiple times to add multiple licenses to the temporary license store.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense)
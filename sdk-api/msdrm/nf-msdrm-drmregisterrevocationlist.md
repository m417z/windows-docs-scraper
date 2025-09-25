# DRMRegisterRevocationList function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMRegisterRevocationList** function registers a rights revocation list on the client.

## Parameters

### `hEnv` [in]

A handle to an environment, created by [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `wszRevocationList` [in]

Revocation list as a null-terminated string.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A revocation list holds all group identities, end-user licenses, or other principals that have been revoked. This function blocks the display of content from distributors or users whose license has been revoked. When an attempt to bind to a license fails with **E_DRM_BIND_REVOCATION_LIST_STALE** or **E_DRM_BIND_NO_APPLICABLE_REVOCATION_LIST**, this indicates that the license requires a revocation list. This list must either be found in the license store (using [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense)) or must be acquired fresh using [DRMAcquireAdvisories](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquireadvisories) and then retrieved from the license store. Registration is only for the lifetime of the environment passed in. Any time that a new environment object is created, the necessary revocation lists must be registered for that environment.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMAcquireAdvisories](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquireadvisories)

[Revoking a Certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/revoking-a-certificate)
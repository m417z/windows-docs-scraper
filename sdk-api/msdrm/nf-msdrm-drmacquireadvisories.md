# DRMAcquireAdvisories function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMAcquireAdvisories** function retrieves revocation lists required by a submitted license. Retrieved revocation lists are added to the user's permanent license store. A revocation list is a signed XrML document that specifies principals that have been revoked because they are no longer considered trustworthy or valid. These principals can include [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), [machine certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly), code-signing certificates, manifests, and server licensor certificates, among other things.

## Parameters

### `hLicenseStorage` [in]

A handle to a license storage session created by using the [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) function.

### `wszLicense` [in]

A pointer to a null-terminated Unicode string that contains the license that requires a revocation list. This can be any license or certificate (or certificate chain or concatenated licenses) that supports revocation lists, including [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly), [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), or [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly).

### `wszURL` [in, optional]

A pointer to a null-terminated Unicode string that contains an additional URL to query for advisories. This will be checked in addition to any URLs mentioned in the license passed in. This parameter can be set to **NULL**.

### `pvContext` [in]

A 32-bit, application-defined value that is sent in the *pvContext* parameter of the callback function. This value can be a pointer to data, a pointer to an event handle, or whatever else the custom callback function is designed to handle. For more information, see [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback).

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function retrieves advisory lists asynchronously. The URL where the revocation list is posted is stored in the license that is passed in, but it can be overridden by *wszURL*.

After an advisory list has been obtained, it must be registered by using [DRMRegisterRevocationList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmregisterrevocationlist). It is simplest to enumerate all licenses in the license store by using [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) and then register each, rather than attempting to locate the item you just acquired.

You should periodically delete duplicate or outdated revocation lists from the license store by enumerating revocation lists. To enumerate revocation lists, call [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) with the **DRM_EL_EXPIRED** flag, and then call [DRMDeleteLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdeletelicense). Because enumerating and examining licenses can be time-consuming, an application might perform this task only periodically.

An application will be informed that a new revocation list must be acquired if the call to the [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) function returns **E_DRM_BIND_REVOCATION_LIST_STALE** or **E_DRM_BIND_NO_APPLICABLE_REVOCATION_LIST**.

For more information about revocation lists and how to create them, see the Active Directory Rights Management Services deployment guide, which comes with [Rights Management Services](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/hh831364(v=ws.11)).

The application callback function specified in the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function will be called with the [DRM_MSG_ACQUIRE_ADVISORY](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-advisory) message to provide status feedback.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMRegisterRevocationList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmregisterrevocationlist)

[Revoking a Certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/revoking-a-certificate)
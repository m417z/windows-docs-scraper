# DRMInitEnvironment function

## Description

[The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll
is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2,
Windows 7, Windows Server 2012, and Windows 8. It may be altered or
unavailable in subsequent versions. Instead, use
[Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),
which leverages functionality exposed by the client in Msipc.dll.]

The **DRMInitEnvironment** function creates a
secure environment for all rights management calls.

## Parameters

### `eSecurityProviderType` [in]

Specifies the type of security provider to use.

### `eSpecification` [in]

Specifies which security provider to use.

### `wszSecurityProvider` [in]

The file name and ID of the security provider. A security provider can be a file on the computer (the
lockbox) or a hardware device that holds the secure machine key. The path to this key is obtained by calling
[DRMGetSecurityProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsecurityprovider).

### `wszManifestCredentials` [in]

A signed XrML structure that specifies conditions on the environment. For information about making a
manifest, see
[Creating an Application Manifest](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-application-manifest).

### `wszMachineCredentials` [in]

The machine certificate.

### `phEnv` [out]

A pointer to an environment handle. Close the handle by calling
[DRMCloseEnvironmentHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcloseenvironmenthandle).

### `phDefaultLibrary` [out]

A pointer to the handle of the library used to create the principal object. You must close this handle
before closing the environment handle. For more information, see the Remarks section. Close by calling
[DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error.
Possible values include, but are not limited to, those in the following list. For a list of common error codes,
see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function loads the lockbox, and makes sure that only legal DLLs are loaded, according to the manifest.

The order of certificates is from least trusted first to most trusted (closest to the root) last.

When closing the handles returned by this function, close the library handle before closing the environment
handle. Otherwise, you will receive an **E_DRM_ENV_NOT_LOADED** error. Close the library
handle by calling [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle). Close the environment
handle by calling
[DRMCloseEnvironmentHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcloseenvironmenthandle).

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)
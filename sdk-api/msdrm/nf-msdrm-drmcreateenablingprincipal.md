# DRMCreateEnablingPrincipal function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateEnablingPrincipal** function creates an enabling principal needed to bind to a license.

## Parameters

### `hEnv` [in]

A handle to an environment created by [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `hLibrary` [in]

A handle to a library. Currently, the only valid library that can be used is the one passed out by [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `wszObject` [in]

A pointer to a null-terminated Unicode string that specifies the enabling principal type. An application can use the object constants specified in Msdrmgetinfo.h.

### `pidPrincipal` [in]

A pointer to a [DRMID](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmid) structure that identifies the enabling principal. The **DRMID** members can be **NULL** to use the first principal in a license.

### `wszCredentials` [in]

A pointer to a null-terminated Unicode string that contains the [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) of the current user.

### `phEnablingPrincipal` [out]

A pointer to a **DRMHANDLE** value that receives the created principal. Call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) to close the handle.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The enabling principal this function creates is used in the [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams) structure passed into [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense). Call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) to close the enabling principal handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)
# DRMCreateBoundLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateBoundLicense** function allows an application to examine or exercise the rights on a locally stored license.

## Parameters

### `hEnv` [in]

A handle to an environment; the handle is created by using the [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment) function.

### `pParams` [in]

A pointer to a [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams) structure that specifies additional options; for more information, see the Remarks section. The principal specified here is the one the application will try to bind to. If you pass in **NULL** to identify the principal or rights group, the first principal or rights group in the license will be used.

### `wszLicenseChain` [in]

A pointer to a null-terminated Unicode string that contains the [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) (or license chain).

### `phBoundLicense` [out]

A pointer to a handle that receives the bound license. The **DRMHANDLE** passed back through *phBoundLicense* allows an application to navigate through all the license's objects (such as principals or rights) and attributes (such as maximum play count). A bound license consolidates duplicated rights information in the license and removes any rights information that is not available to the current user.

### `phErrorLog` [out]

This parameter must be **NULL**.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Calling this function binds a license to the right or rights specified in the [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams) structure passed to the *pParams* parameter. If any right requested cannot be exercised by the current user, the function will fail. Note also that you must call [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata) and specify a value for the *wszContentId* parameter before calling this function and that this value must be the same as the ID set in the **DRMBOUNDLICENSEPARAMS** structure or the function will fail.

If the function succeeds, it returns a handle to the bound license that can be examined, and also allows an application to exercise the bound right. This function does not decrement metered rights. Decrementing metered rights upon use is the responsibility of the application.

When license binding fails because of a missing or out of date revocation list, the return value does not indicate which license or certificate is causing the error. It could be the end-user license, the user's [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), a [client licensor certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly), or another license or certificate. You must call [DRMAcquireAdvisories](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquireadvisories) (and [DRMRegisterRevocationList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmregisterrevocationlist)) for each certificate until the error does not occur.

Principal authenticators required for a license must be loaded before calling this function. However, the authenticator can continue to function after the license is created.

When you have finished using the license handle, close it by calling the [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) function. **DRMCloseHandle** closes the handle to the library and deletes the license from memory.

The handle returned by this function can be passed into one of the following functions to navigate deeper into the license hierarchy:

* [DRMGetBoundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattribute)
* [DRMGetBoundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattributecount)
* [DRMGetBoundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobject)
* [DRMGetBoundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobjectcount)

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams)
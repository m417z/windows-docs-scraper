# DRMCreateClientSession function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateClientSession** function creates a client session, which hosts license storage sessions and is used in activation and other function calls.

## Parameters

### `pfnCallback` [in]

A pointer to an application-defined callback function that will receive asynchronous function status messages in response to other AD RMS functions, such as [DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate). The format of this callback function is defined in [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback). This parameter cannot be **NULL**.

### `uCallbackVersion` [in]

Specifies the version of the callback function. Currently, only version zero is supported.

### `wszGroupIDProviderType` [in]

A pointer to a null-terminated Unicode string that specifies the authentication type of the submitted [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) (RAC). This can be one of the following values.

#### DRM_DEFAULTGROUPIDTYPE_WINDOWSAUTH

Use Windows authentication. Specify this value also for an Active Directory Federation Services (ADFS) RAC.

#### DRM_DEFAULTGROUPIDTYPE_PASSPORT

Use Passport authentication.

### `wszGroupID` [in, optional]

A pointer to a null-terminated Unicode string that contains an email address for the user in the format *someone@example.com*. Typically, this value already exists in Active Directory (AD) and is the same ID as that supplied in the logon credentials. If it is not the same, later calls to [DRMIsActivated](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmisactivated) and [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) will fail. For more information, see Remarks.

Set this parameter to **NULL** if you intend only to use the client session handle created by this function to retrieve a service location by calling [DRMGetServiceLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetservicelocation).

### `phClient` [out]

A pointer to a **DRMHSESSION** value that receives the client session handle. When you have finished using the client session, close it by passing this handle to the [DRMCloseSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosesession) function.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If this function is successful, the AD RMS server returns a client session handle that is used by [DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate) to create a rights account certificate (RAC) in the license store for the new client session. The RAC is created by using the credentials of the logged–on user. If the email address specified in the *wszGroupID* parameter does not match that specified in the credentials, functions such as [DRMIsActivated](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmisactivated) and [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) that use information associated with the client session to search the license store for the RAC will fail.

For example, assume that the user logged on by using cat@example.com but the *wszGroupID* parameter is set to dog@example.com. The RAC is created for cat@example.com. The [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) function, however, searches the license store for a RAC that contains dog@example.com and fails.

All license storage sessions must be closed before closing the client session. When you have finished using the client session, close it by passing the handle provided by this function to the [DRMCloseSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosesession) function.

The **DRMCreateClientSession** function cannot be called concurrently by different processes running as different users on the same computer if one or more of these processes is a service process. A call by a second process, for example, can succeed only after the client session handle for the first process has been closed.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function)

[DRMCloseSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosesession)
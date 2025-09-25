# DRMAcquireIssuanceLicenseTemplate function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMAcquireIssuanceLicenseTemplate** function asynchronously retrieves issuance license templates from a server.

## Parameters

### `hClient` [in]

A handle to a client session. The handle is obtained by calling the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function. When you call **DRMCreateClientSession**, you must specify a callback function that AD RMS can use to return the result of an operation. A string that contains the templates is sent to the callback function in a [DRM_MSG_ACQUIRE_ISSUANCE_LICENSE_TEMPLATE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-issuance-license-template) message.

### `uFlags` [in]

Specifies options for the function call. This parameter can be a combination of one or more of the following flags.

#### DRM_AILT_NONSILENT ()

nonsilent template acquisition is supported. That is, an authentication prompt is displayed if an access control list (ACL) is applied to the template and default authentication fails.

#### DRM_AILT_OBTAIN_ALL ()

Retrieves all templates from the server and adds them to the local store:

* Templates in the local store that are not present on the server are deleted from the local store.
* Templates in the local store that have been updated on the server are replaced.
* Templates that are found on the server but not in the local store are added to the local store.

#### DRM_AILT_CANCEL ()

Cancels the previous request.

### `pvReserved` [in]

Reserved for future use. This parameter must be **NULL**.

### `cTemplates` [in]

Reserved for future use. This value must be zero.

### `pwszTemplateIds` [in, optional]

Reserved for future use. This parameter must be **NULL**.

### `wszUrl` [in]

A null-terminated Unicode string that contains the template acquisition URL. You can retrieve this value by calling [DRMGetServiceLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetservicelocation) and setting the *uServiceType* parameter to **DRM_SERVICE_TYPE_CLIENTLICENSOR**.

### `pvContext` [in]

A 32-bit, application-defined value that is returned in the *pvContext* parameter of the callback function. This value can be a pointer to data, a pointer to an event handle, or whatever else the custom callback function is designed to handle. For more information, see [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **DRMAcquireIssuanceLicenseTemplate** function is asynchronous. It returns immediately with a value of S_OK or an error code. To cancel a request in process,
call the function with **DRM_AILT_CANCEL** specified for the *uFlags* parameter. To determine the result of the template retrieval operation, you must examine the *hr* parameter in the [DRM_MSG_ACQUIRE_ISSUANCE_LICENSE_TEMPLATE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-issuance-license-template) message that AD RMS sends to your callback function.

The template collection is saved in the template store of the local AD RMS store. Each template is stored in a file with the format TMP-*HashValue*-*TemplateGUID* where the hash value is a base64-encoded SHA-1 hash of server public key. You can call the [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) function to enumerate the templates.

If properly configured, AD RMS clients can automatically obtain templates from the AD RMS server by using a WMI job in the task scheduler. Therefore, if WMI distribution is enabled, call [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) to enumerate the rights policy templates from the local template store. Applications should avoid calling **DRMAcquireIssuanceLicenseTemplate** because the WMI job automatically copies templates to the client computer. However, **DRMAcquireIssuanceLicenseTemplate** can be used to retrieve templates from multiple servers, functionality not supported by the WMI job. You can also use it to retrieve templates if your application relies on a server lockbox. The WMI job is only available to applications that use a client lockbox.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense)
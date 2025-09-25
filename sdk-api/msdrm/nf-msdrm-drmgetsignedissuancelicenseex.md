# DRMGetSignedIssuanceLicenseEx function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetSignedIssuanceLicenseEx** function acquires a signed issuance license offline. When you call the function, you can pass in the handle to a client licensor certificate (CLC) and the handle to a rights account certificate (RAC), therefore specifying the CLC and the RAC to use when acquiring the signed issuance license.

## Parameters

### `hEnv` [in]

A handle to a secure environment created by using the [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment) function. The handle is required for offline signing. Applications that do not use a lockbox should pass **NULL** for this parameter.

### `hIssuanceLicense` [in]

A handle to an issuance license to sign, created by using the [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense) function.

### `uFlags` [in]

Contains various options for acquiring the signed issuance license. This parameter can be one of the following values (although **DRM_AUTO_GENERATE_KEY** and **DRM_OWNER_LICENSE_NOPERSIST** can be combined with other flags). If **DRM_AUTO_GENERATE_KEY** is not specified, you must provide your own content key with a cryptographic system, such as the CryptoAPI functions from the Platform SDK.

#### DRM_SIGN_OFFLINE

Specifies an offline issuance license signing request. When signing offline, the issuance license is signed by using the [client licensor certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly) (CLC) obtained during a previous call to [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense). To get this certificate from the store, use [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense). Each CLC is tied to the server that issued it; be sure that you are using the correct client licensor certificate for the issuance license you are publishing.

This flag cannot be combined with the **DRM_SIGN_ONLINE** or **DRM_SERVER_ISSUANCELICENSE** flags.

#### DRM_SIGN_CANCEL

Cancels an online signing request. Offline requests are processed immediately and do not need to be canceled.

#### DRM_AUTO_GENERATE_KEY

Can be used with one of the preceding flags to have the Active Directory Rights Management Services system generate a content key for you. This key is used in encryption functions. Typically, the key type is AES and the cipher mode is ECB. If this flag is not specified, you must provide your own content key with a cryptographic system, such as with the CryptoAPI functions from the Platform SDK.

**Note** If you are using the AD RMS client included in Windows 7, or if you install the CBC hotfix, the value AES_CBC4K can be used to specify the AES algorithm with cipher-block chaining (CBC) cipher mode. See the [DRMEncrypt](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmencrypt) code examples for more information.

#### DRM_OWNER_LICENSE_NOPERSIST

The owner license is stored in memory instead of the permanent store. The owner license can subsequently be retrieved by the [DRMGetOwnerLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetownerlicense) function.

#### DRM_REUSE_KEY

Causes the content key to be reused. The content key is obtained from the signed issuance license associated with the bound license (*hBoundLicense*) that is passed in to [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense). You must ensure that the bound license is bound to either the **EDITRIGHTSDATA** or **OWNER** right. This flag is available only in Windows 7.

**Note** This flag must be combined with **DRM_SIGN_OFFLINE**. You can also optionally combine it with **DRM_OWNER_LICENSE_NOPERSIST**. These are the only allowed values. The parameters *pbSymKey* and *cbSymKey* must be set to 0.

**Caution** To avoid security implications, reuse the content key only if users or rights are being added. Additionally, it is a best practice to always generate a new content identifier for the publishing license to avoid an older end-user license being used with the new publishing license.

### `pbSymKey` [in]

The content key used to encrypt the document. If this value is **NULL**, the *uFlags* parameter must specify **DRM_AUTO_GENERATE_KEY** or **DRM_REUSE_KEY**. These *uFlags* values cause *pbSymKey* to be ignored.

### `cbSymKey` [in]

The size, in bytes, of the content key. Currently, this parameter can only be 16 unless the *uFlags* parameter specifies **DRM_AUTO_GENERATE_KEY** or **DRM_REUSE_KEY**, in which case this parameter can be zero.

### `wszSymKeyType` [in]

The key type. The value **AES** specifies the Advanced Encryption Standard (AES) algorithm with the electronic code book (ECB) cipher mode. If you are using Windows 7, the value **AES_CBC4K** can be used to specify the AES algorithm with cipher-block chaining (CBC) cipher mode. See the [DRMEncrypt](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmencrypt) code examples for more information.

### `pvReserved` [in]

Reserved for future use.

### `hEnablingPrincipal` [in]

A handle to an enabling principal in the end-user license that should be bound. Create this handle by using the [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal) function by passing in the rights account certificate. This parameter is required.

### `hBoundLicenseCLC` [in]

A handle to the bound license corresponding to the client licensor certificate created using [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense). This can be created by binding the *wszClientLicensorCertificate* to the **ISSUE** right using the *hEnablingPrincipal* handle. This parameter is required.

### `pfnCallback` [in]

A pointer to the callback function used to notify the application of an asynchronous request's progress. For the signature of the callback function you must provide, see [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback).

### `pvContext` [in]

A 32-bit, application-defined value that is sent in the *pvContext* parameter of the callback function. This value can be a pointer to data, a pointer to an event handle, or whatever else the custom callback function is designed to handle. For more information, see [Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function).

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

To use this function, create an enabling principal from the rights account certificate using [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal). After this, you must parse the client licensor certificate(CLC) to obtain the content ID, in the same manner as you do for the end-user license. Subsequently, call [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense), passing in the *hEnablingPrincipal* obtained from the call to **DRMCreateEnablingPrincipal** and the content ID to create an *hBoundLicense* that corresponds with the CLC. Next, call **DRMGetSignedIssuanceLicenseEx**, passing in the *hEnablingPrincipal* obtained from the call to **DRMCreateEnablingPrincipal** and the *hBoundLicense* obtained from the call to **DRMCreateBoundLicense**. Finally, cache the handles obtained from the call to **DRMCreateEnablingPrincipal** and the call to **DRMCreateBoundLicense**.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)

[Offline Signing Code Example](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/offline-signing-code-example)

[Online Signing Code Example](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/online-signing-code-example)
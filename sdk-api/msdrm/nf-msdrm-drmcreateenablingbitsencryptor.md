# DRMCreateEnablingBitsEncryptor function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateEnablingBitsEncryptor** function creates an AD RMS encrypting object that is used to encrypt content data.

## Parameters

### `hBoundLicense` [in]

A handle to a bound license, produced by [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

### `wszRight` [in, optional]

Optional null-terminated string containing a right. If you specify **NULL**, the AD RMS encrypting object binds to the first valid right in the license.

### `hAuxLib` [in]

Reserved for future use. This parameter must be **NULL**.

### `wszAuxPlug` [in, optional]

Reserved for future use. This parameter must be **NULL**.

### `phEncryptor` [out]

A pointer to the encrypting object.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Perform the following steps to encrypt content. For more information, see [Encrypting Content](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/encrypting-content).

* Acquire an end-user license. If the issuance license that you are using for this purpose was signed online, call [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense) followed by [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense). If the issuance license was signed offline, call [DRMGetOwnerLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetownerlicense) instead.
* Call [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) to create a license that binds to the EDIT or OWNER right in the end-user license. The bound license includes a symmetric key that can be used for encryption.
* Call **DRMCreateEnablingBitsEncryptor** to create an encrypting object associated with the bound right and content key.
* Call [DRMEncrypt](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmencrypt) to use the content key to encrypt the content.

Call the [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) function to close the encrypting object handle when you are finished with it. Both the encrypting object handle and the bound license handle must remain open until encryption is complete.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)

[DRMCreateEnablingBitsDecryptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingbitsdecryptor)

[Encrypting Content](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/encrypting-content)
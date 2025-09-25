# DRMCreateEnablingBitsDecryptor function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateEnablingBitsDecryptor** function creates a decryption object that is used to decrypt content data.

## Parameters

### `hBoundLicense` [in]

A handle to a bound license object created by using [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

### `wszRight` [in, optional]

An optional null-terminated string that contains the right to exercise. A decrypting object can be bound to only one right at a time.

### `hAuxLib` [in]

Reserved for future use. This parameter must be **NULL**.

### `wszAuxPlug` [in, optional]

Reserved for future use. This parameter must be **NULL**.

### `phDecryptor` [out]

A pointer to the decrypting object.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A consuming application performs the following steps to decrypt content previously encrypted by a publishing application.

1. Retrieve an end-user license. Call [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) to retrieve the license if it already exists in the store. If function succeeds, go to step 2. If the license is not in the store, call [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense) followed by **DRMEnumerateLicense**.
2. Call [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) to create a license that binds to one or more rights in the end-user license. The bound license includes a symmetric key that can be used for decryption.
3. Call **DRMCreateEnablingBitsDecryptor** to create a decrypting object associated with the bound right and content key.
4. Call [DRMDecrypt](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdecrypt) to use the content key to decrypt the content.

Call the [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) function to close the decrypting object handle when you are finished with it. Both the decrypting object handle and the bound license handle must remain open until decryption is complete.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMCreateEnablingBitsEncryptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingbitsencryptor)

[Decrypting Content](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/decrypting-content)
# DRMGetRevocationPoint function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetRevocationPoint** function retrieves information about the revocation point for an issuance license.

## Parameters

### `hIssuanceLicense` [in]

A handle to the issuance license to get the information from.

### `puIdLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszId* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszId* buffer.

### `wszId` [out]

A pointer to a null-terminated Unicode string that receives the GUID that identifies the revocation point. The size of this buffer is specified by the *puIdLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puIdLength* value.

### `puIdTypeLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszIdType* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszIdType* buffer.

### `wszIdType` [out]

A pointer to a null-terminated Unicode string that receives the type of the revocation point identifier. The size of this buffer is specified by the *puIdTypeLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puIdTypeLength* value.

### `puURLLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszURL* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszURL* buffer.

### `wszRL` [out]

A pointer to a null-terminated Unicode string that receives the URL where a revocation list can be obtained. The size of this buffer is specified by the *puURLLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puURLLength* value.

### `pstFrequency` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the frequency that the revocation list must be refreshed. This parameter is required and cannot be **NULL**.

### `puNameLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszName* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszName* buffer.

### `wszName` [out]

A pointer to a null-terminated Unicode string that receives the human-readable name for the revocation location. The size of this buffer is specified by the *puNameLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puNameLength* value.

### `puPublicKeyLength` [in, out]

A pointer to a **UINT** value that, on entry, contains the length, in characters, of the *wszPublicKey* buffer. This length must include the terminating null character.

After the function returns, this value contains the number of characters, including the terminating null character, that were copied to the *wszPublicKey* buffer.

### `wszPublicKey` [out]

A pointer to a null-terminated Unicode string that receives the optional public key to identify a revocation list outside the content's chain of trust. The size of this buffer is specified by the *puPublicKeyLength* parameter.

To determine the required size of this buffer, pass **NULL** for this parameter. The function will place the size, in characters, including the terminating null character, in the *puPublicKeyLength* value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A revocation list can revoke end-user licenses, server licensor certificates, or almost anything else that has an identifying GUID. The URL provided should refer to the list file itself. Active Directory Rights Management Services (AD RMS) handles checking for a valid revocation list. You could call this function for each revocation point structure in a license if [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) fails because of a stale or missing revocation list. However, a simpler method is to call [DRMAcquireAdvisories](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquireadvisories), which updates all revocation lists for you.

If a public key is provided, it should be a well-formed XrML public key node. If the revocation list is signed with a key pair outside the content's chain of trust, the public key of that key pair must be specified here. Otherwise, it should not be used.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMSetRevocationPoint](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetrevocationpoint)
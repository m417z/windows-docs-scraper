# DRMDecode function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMDecode** function decodes a string encoded with a common algorithm, such as base64.

## Parameters

### `wszAlgID` [in]

The encoding algorithm name. Currently "base64" is the only valid value.

### `wszEncodedString` [in]

The encoded string.

### `puDecodedDataLen` [in]

The length of the decoded string, in characters, plus one for a null terminator.

### `pbDecodedData` [out]

Pointer to the decoded data.

## Return value

 If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Encoding is not the same as encrypting.

Buffer space for the decoded data must be allocated and freed by the caller. The size necessary for this buffer can be determined by calling this function with **NULL** in the *pbDecodedData* parameter.

## See also

[DRMEncode](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmencode)
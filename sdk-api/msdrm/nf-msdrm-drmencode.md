# DRMEncode function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMEncode** function encodes data using a public encoding method, such as base64.

## Parameters

### `wszAlgID` [in]

The encoding algorithm. Currently the only valid value is "base64".

### `uDataLen` [in]

Length of the input data, in bytes.

### `pbDecodedData` [in]

Pointer to the data to encode.

### `puEncodedStringLen` [in, out]

Length of the output data, in bytes.

### `wszEncodedString` [out]

The encoded string.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Note that encoding is not encrypting. Encoding does not protect content, but transforms it into a format appropriate for a specific use.

Buffer space for the encoded data must be allocated and freed by the caller. The size necessary for this buffer can be determined by calling this function with **NULL** in the *wszEncodedString* parameter.

## See also

[DRMDecode](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmdecode)
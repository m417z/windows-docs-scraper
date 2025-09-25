# CryptXmlVerifySignature function

## Description

The **CryptXmlVerifySignature** function performs a cryptographic signature
validation of a **SignedInfo** element.

## Parameters

### `hSignature` [in]

The handle of a **Signature** element.

### `hKey` [in, optional]

The handle of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to verify the signature value on
the **SignedInfo** element.
This parameter must be **NULL** for HMAC-based signature algorithms.

### `dwFlags`

A **DWORD** value that controls which implementations are used. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.
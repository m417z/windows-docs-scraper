# CryptMsgEncodeAndSignCTL function

## Description

The **CryptMsgEncodeAndSignCTL** function encodes a [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and creates a signed message containing the encoded CTL.

This function first encodes the CTL pointed to by *pCtlInfo* and then calls
[CryptMsgSignCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgsignctl) to sign the encoded message.

## Parameters

### `dwMsgEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pCtlInfo` [in]

A pointer to the
[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) structure containing the CTL to be encoded and signed.

### `pSignInfo` [in]

A pointer to a
[CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure that contains an array of a
[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info) structures.

The message can be encoded without signers if the **cbSize** member of the structure is set to the size of the structure and all of the other members are set to zero.

### `dwFlags` [in]

CMSG_ENCODE_SORTED_CTL_FLAG is set if the CTL entries are to be sorted before encoding. This flag is set if the
[CertFindSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinsortedctl) or [CertEnumSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsubjectinsortedctl) functions will be called.

CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG is set if CMSG_ENCODE_SORTED_CTL_FLAG is set, and the identifier for the TrustedSubjects is a hash, such as MD5 or SHA1.

If CMS_PKCS7 is defined, *dwFlags* can be set to CMSG_CMS_ENCAPSULATED_CTL_FLAG to encode a CMS compatible V3 SignedData message.

### `pbEncoded` [out]

A pointer to a buffer that receives the encoded, signed message created.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncoded` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the *pbEncoded* buffer. When the function returns, the **DWORD** contains the number of bytes stored or to be stored in the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Errors can be propagated from calls to
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) and
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate).

## See also

[CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info)

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)

[CertEnumSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsubjectinsortedctl)

[CertFindSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinsortedctl)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[CryptMsgSignCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgsignctl)

[Verification Functions Using CTLs](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
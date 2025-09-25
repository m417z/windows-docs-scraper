# CRYPT_RC2_CBC_PARAMETERS structure

## Description

The **CRYPT_RC2_CBC_PARAMETERS** structure contains information used with szOID_RSA_RC2CBC encryption. It is used in calls to
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject),
[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex),
[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)
[CryptDecodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobjectex).

## Members

### `dwVersion`

Specifies the key length. Current usable key lengths are 40, 64, and 128 bits.

**Note** The numeric value of defined constants for **dwVersion** are not the same as the key lengths they specified. Currently defined values for **dwVersion** are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CRYPT_RC2_40BIT_VERSION**<br><br>160 | 40 bits |
| **CRYPT_RC2_56BIT_VERSION**<br><br>52 | 56 bits |
| **CRYPT_RC2_64BIT_VERSION**<br><br>120 | 64 bits |
| **CRYPT_RC2_128BIT_VERSION**<br><br>58 | 128 bits |

### `fIV`

Boolean specifying whether an 8-byte [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV) is contained in **rgbIV[8]**. Set to **TRUE** when IV is present.

### `rgbIV`

Eight byte [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly). Can be **NULL** if fIV is **FALSE**. The IV is encoded as an OCTET_STRING.

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) or
[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) with the *dwCertEncodingType* parameter set to X500_OCTET_STRING to create the encoded OCTET_STRING. The **ContentEncryptionAlgorithm**'s **Parameters** BLOB is updated to point to this encoded OCTET_STRING.

**Note** When a message is decrypted, if it has an IV parameter, the message functions calls
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) with the IV before doing the decryption.

## See also

[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info)

[CRYPT_ENCRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_encrypt_message_para)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam)
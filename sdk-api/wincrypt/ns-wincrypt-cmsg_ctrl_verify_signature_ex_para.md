# CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA structure

## Description

The **CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA** structure contains information used to verify a message signature. It contains the signer index and signer public key. The signer public key can be the signer's [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure, [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), or chain context.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used to verify the signature. If **NULL**, the cryptographic provider specified in [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) is used. If the *hCryptProv* in **CryptMsgOpenToDecode** is also **NULL**, the default provider according to the signer's public key [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) is used.This member's data type is **HCRYPTPROV**.

### `dwSignerIndex`

The index of the signer in the message.

### `dwSignerType`

The structure that contains the signer information. The following table shows the predefined values and the structures indicated.

| Value | Meaning |
| --- | --- |
| **CMSG_VERIFY_SIGNER_PUBKEY** | [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) |
| **CMSG_VERIFY_SIGNER_CERT** | [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) |
| **CMSG_VERIFY_SIGNER_CHAIN** | [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) |
| **CMSG_VERIFY_SIGNER_NULL** | **NULL** |

### `pvSigner`

A pointer to a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure, a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), a chain context, or **NULL** depending on the value of **dwSignerType**.

## Remarks

If **dwSignerType** is CMSG_VERIFY_SIGNER_NULL, the signature is expected to contain only the unencrypted hash octets.
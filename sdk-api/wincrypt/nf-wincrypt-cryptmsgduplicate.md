# CryptMsgDuplicate function

## Description

The **CryptMsgDuplicate** function duplicates a cryptographic message handle by incrementing its [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `hCryptMsg` [in]

Handle of the cryptographic message to be duplicated. Duplication is done by incrementing the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) of the message. A copy of the message is not made.

## Return value

The returned handle is the same as the handle input. A copy of the message is not created. When you have finished using the duplicated message handle, decrease the reference count by calling the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function.

## Remarks

**CryptMsgDuplicate** is used to increase the reference count on an **HCRYPTMSG** handle so that multiple calls to
[CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) are required to actually release the handle.

#### Examples

For an example that uses this function, see [Example C Program: Encoding and Decoding a Hashed Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-and-decoding-a-hashed-message).

## See also

[CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
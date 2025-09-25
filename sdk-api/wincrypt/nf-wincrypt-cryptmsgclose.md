# CryptMsgClose function

## Description

The **CryptMsgClose** function closes a cryptographic message handle. At each call to this function, the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the message is reduced by one. When the reference count reaches zero, the message is fully released.

## Parameters

### `hCryptMsg` [in]

Handle of the cryptographic message to be closed.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode)

[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
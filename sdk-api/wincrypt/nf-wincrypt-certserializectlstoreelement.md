# CertSerializeCTLStoreElement function

## Description

The **CertSerializeCTLStoreElement** function serializes an encoded [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and the encoded representation of its properties. The result can be persisted to storage so that the CTL and properties can be retrieved later.

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure being serialized.

### `dwFlags` [in]

Reserved for future use and must be zero.

### `pbElement` [out]

A pointer to a buffer that receives the serialized output, including the encoded CTL and, possibly, its properties.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbElement` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the buffer that is pointed to by the *pbElement* parameter. When the function returns the **DWORD** value contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CertAddSerializedElementToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddserializedelementtostore)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
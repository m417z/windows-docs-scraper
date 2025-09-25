# CryptXmlSetHMACSecret function

## Description

The **CryptXmlSetHMACSecret** function sets the HMAC secret on the handle before
calling the [CryptXmlSign](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlsign) or [CryptXmlVerify](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlverifysignature) function.

## Parameters

### `hSignature` [in]

The handle of the XML **Signature** element.

### `pbSecret` [in]

A pointer to a buffer that contains a block of bytes.
The pointer must be valid during the call to the [CryptXmlSign](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlsign) or [CryptXmlVerify](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlverifysignature) function.

### `cbSecret`

The size, in bytes, of the buffer pointed to by the *pbSecret* parameter.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.
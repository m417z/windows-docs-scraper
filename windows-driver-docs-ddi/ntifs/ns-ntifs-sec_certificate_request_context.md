## Description

The **SEC_CERTIFICATE_REQUEST_CONTEXT** structure provides the certificate request context when [**BufferType**](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secbuffer) is **SECBUFFER_CERTIFICATE_REQUEST_CONTEXT**.

## Members

### `cbCertificateRequestContext`

The size in bytes of the **rgCertificateRequestContext** array.

### `rgCertificateRequestContext`

The Transport Layer Security (TLS) 1.3 certificate request context. This context contains the payload bytes of the “opaque certificate_request_context<0..2^8-1>” field in the certificate request message, excluding the one byte size field that the protocol prepends to that buffer, that is stored as **cbCertificateRequestContext**.

## See also

[**SecBuffer**](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secbuffer)
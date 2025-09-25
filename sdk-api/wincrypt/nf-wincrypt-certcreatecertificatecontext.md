# CertCreateCertificateContext function

## Description

The **CertCreateCertificateContext** function creates a certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from an encoded certificate. The created context is not persisted to a certificate store. The function makes a copy of the encoded certificate within the created context.

## Parameters

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCertEncoded` [in]

A pointer to a buffer that contains the encoded certificate from which the context is to be created.

### `cbCertEncoded` [in]

The size, in bytes, of the *pbCertEncoded* buffer.

## Return value

If the function succeeds, the function returns a pointer to a read-only
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). When you have finished using the certificate context, free it by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

If the function is unable to decode and create the [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), it returns **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A certificate encoding type that is not valid was specified. Currently, only the X509_ASN_ENCODING type is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

The
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).
[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) can be called to make a duplicate.
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty) and
[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty) can be called to store and read properties for the certificate.

#### Examples

The following example shows creating a certificate context from an encoded certificate. The created context is not put in a certificate store. For another example that uses this function, see [Example C Program: Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-certificate-store-operations).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

void main()
{
	PCCERT_CONTEXT  pCertContext = NULL;

	//------------------------------------------------------------------
	//  Create a new certificate from the encoded part of
	//  an available certificate. pDesiredCert is a previously
	//  assigned PCCERT_CONTEXT variable.
	if(pCertContext = CertCreateCertificateContext(
		MY_ENCODING_TYPE,              // The encoding type
		pDesiredCert->pbCertEncoded,   // The encoded data from
									   // the certificate retrieved
		pDesiredCert->cbCertEncoded))  // The length of the encoded data
	{
		printf("A new certificate has been created.\n");
	
		// Use the certificate context as needed.
		// ...

		// When finished, free the certificate context.
		CertFreeCertificateContext(pCertContext);
	}
	else
	{
		printf("A new certificate could not be created.\n");
		exit(1);
	}
}
```

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CertCreateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecrlcontext)

[CertCreateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatectlcontext)

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
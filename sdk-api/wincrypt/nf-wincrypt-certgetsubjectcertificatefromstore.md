# CertGetSubjectCertificateFromStore function

## Description

The **CertGetSubjectCertificateFromStore** function returns from a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) a subject certificate context uniquely identified by its issuer and serial number.

## Parameters

### `hCertStore` [in]

A handle of a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `dwCertEncodingType` [in]

The type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pCertId` [in]

A pointer to a
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure. Only the **Issuer** and **SerialNumber** members are used.

## Return value

If the function succeeds, the function returns a pointer to a read-only
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). The **CERT_CONTEXT** must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

The returned certificate might not be valid. Usually, it is verified when getting its issuer certificate ([CertGetIssuerCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetissuercertificatefromstore)).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). One possible error code is the following.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | The subject certificate was not found in the store. |

## Remarks

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) can be called to make a duplicate certificate.

#### Examples

The following example shows retrieving a subject's certificate context, uniquely identified by its issuer and serial number, from the certificate store. For an example that includes the complete context for this example, see
[Example C Program: Signing, Encoding, Decoding, and Verifying a Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-signing-encoding-decoding-and-verifying-a-message).

``` syntax

#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

void main()
{
//-------------------------------------------------------------------
// Declare and initialize variables.

HCERTSTORE hStoreHandle;           // certificate store handle
HCRYPTMSG hMsg;
PCCERT_CONTEXT pSignerCertContext;
DWORD          cbSignerCertInfo;
PCERT_INFO     pSignerCertInfo;
//-------------------------------------------------------------------
//  This code is based on hMsg being a signed, encoded message
//  read from a file or otherwise acquired. For detailed code, see
//  "Example C Program: Signing, Encoding, Decoding, and Verifying a
//  Message."

//-------------------------------------------------------------------
// Retrieve the signer CERT_INFO from the message by first getting
// the size of the memory required for the certificate.

if(CryptMsgGetParam(
   hMsg,                         // handle to the message
   CMSG_SIGNER_CERT_INFO_PARAM,  // parameter type
   0,                            // index
   NULL,
   &cbSignerCertInfo))           // size of the returned information

{
   printf("%d bytes needed for the buffer.\n", cbSignerCertInfo);
}
else
{
   printf("Verify SIGNER_CERT_INFO #1 failed\n");
   exit(1);
}

//-------------------------------------------------------------------
// Allocate memory.

pSignerCertInfo = (PCERT_INFO) malloc(cbSignerCertInfo);
if (!pSignerCertInfo)
{
    printf("Verify memory allocation failed.\n");
    exit(1);
}

//-------------------------------------------------------------------
// Get the message certificate information (CERT_INFO
// structure).

if(!(CryptMsgGetParam(
     hMsg,                         // handle to the message
     CMSG_SIGNER_CERT_INFO_PARAM,  // parameter type
     0,                            // index
     pSignerCertInfo,              // address for returned information
     &cbSignerCertInfo)))          // size of the returned information

{
    printf("Verify SIGNER_CERT_INFO #2 failed.\n");
    exit(1);
}

//-------------------------------------------------------------------
// Open a certificate store in memory using CERT_STORE_PROV_MSG,
// which initializes it with the certificates from the message.

hStoreHandle = CertOpenStore(
   CERT_STORE_PROV_MSG,         // store provider type
   MY_ENCODING_TYPE,            // encoding type
   NULL,                        // cryptographic provider
                                // use NULL for the default
   0,                           // flags
   hMsg));                      // handle to the message

if (hStoreHandle)
{
    printf("The certificate store to be used for message\n ");
    printf("    verification has been opened. \n");
}
else
{
    printf("Verify open store failed.\n");
    exit(1);
}

//-------------------------------------------------------------------
// Find the signer's certificate in the store.

pSignerCertContext = CertGetSubjectCertificateFromStore(
    hStoreHandle,       // handle to store
    MY_ENCODING_TYPE,   // encoding type
    pSignerCertInfo));  // pointer to retrieved CERT_CONTEXT

if(pSignerCertContext)
{

//-------------------------------------------------------------------
// Use the certificate retrieved from the message. For some
// processing that can be done with the certificate, see the full
// program.

}
//-------------------------------------------------------------------
// Clean up.

if(pSignerCertInfo)
   free(pSignerCertInfo);
if(pSignerCertContext)
   CertFreeCertificateContext(pSignerCertContext);
if(hStoreHandle)
   CertCloseStore(hStoreHandle, CERT_CLOSE_STORE_FORCE_FLAG);
if(hMsg)
   CryptMsgClose(hMsg);

}
```

## See also

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertGetIssuerCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetissuercertificatefromstore)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertEnumCertificatesInStore function

## Description

The **CertEnumCertificatesInStore** function retrieves the first or next certificate in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Used in a loop, this function can retrieve in sequence all certificates in a certificate store.

## Parameters

### `hCertStore` [in]

A handle of a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pPrevCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the previous [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) found.

This parameter must be **NULL** to begin the enumeration and get the first certificate in the store. Successive certificates are enumerated by setting *pPrevCertContext* to the pointer returned by a previous call to the function. This function frees the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) referenced by non-**NULL** values of this parameter.

For [logical stores](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), including collection stores, a duplicate of the *pCertContext* returned by this function cannot be used to begin a new subsequence of enumerations because the duplicated certificate loses the initial enumeration [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The enumeration skips any certificate previously deleted by
[CertDeleteCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecertificatefromstore).

## Return value

If the function succeeds, the function returns a pointer to the next
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) in the store. If no more certificates exist in the store, the function returns **NULL**.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Value | Description |
| --- | --- |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the certificate context pointed to by *pPrevCertContext*. |
| **CRYPT_E_NOT_FOUND** | No certificates were found. This happens if the store is empty or if the function reached the end of the store's list. |
| **ERROR_NO_MORE_FILES** | Applies to external stores. No certificates were found. This happens if the store is empty or if the function reached the end of the store's list. |

## Remarks

The returned pointer is freed when passed as the *pPrevCertContext* parameter on a subsequent call. Otherwise, the pointer must be freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). A non-**NULL** *pPrevCertContext* passed to **CertEnumCertificatesInStore** is always freed even for an error.

A duplicate of the currently enumerated certificate can be made by calling
[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext).

#### Examples

The following example lists the certificate contexts in the certificate store. For another example that uses this function, see [Example C Program: Deleting Certificates from a Certificate Store](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-deleting-certificates-from-a-certificate-store).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>
#pragma comment(lib, "crypt32.lib")

//--------------------------------------------------------------------
// Declare and initialize variables.
HANDLE          hStoreHandle = NULL;
PCCERT_CONTEXT  pCertContext = NULL;
char * pszStoreName = "CA";

//--------------------------------------------------------------------
// Open a system certificate store.
if (hStoreHandle = CertOpenSystemStore(
     NULL,
     pszStoreName))
    {
         printf("The %s store has been opened. \n", pszStoreName);
    }
    else
    {
         printf("The store was not opened.\n");
         exit(1);
    }

//-------------------------------------------------------------------
// Find the certificates in the system store.
while(pCertContext= CertEnumCertificatesInStore(
      hStoreHandle,
      pCertContext)) // on the first call to the function,
                     // this parameter is NULL
                     // on all subsequent calls,
                     // this parameter is the last pointer
                     // returned by the function
{
    //----------------------------------------------------------------
    // Do whatever is needed for a current certificate.
    // ...
} // End of while.

//--------------------------------------------------------------------
//   Clean up.
if (!CertCloseStore(
         hStoreHandle,
         0))
{
    printf("Failed CertCloseStore\n");
    exit(1);
}

```

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CertDeleteCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecertificatefromstore)

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext)

[CertFindCRLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcrlinstore)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
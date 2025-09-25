# CertOpenSystemStoreW function

## Description

The **CertOpenSystemStore** function is a simplified function that opens the most common system [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). To open certificate stores with more complex requirements, such as file-based or memory-based stores, use [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore).

## Parameters

### `hProv` [in]

This parameter is not used and should be set to **0**.

**Windows Server 2003 and Windows XP:** A handle of a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). Set *hProv* to **0** to use the default CSP. If *hProv* is not **0**, it must be a CSP handle created by using the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.This parameter's data type is **HCRYPTPROV**.

### `szSubsystemProtocol` [in]

A string that names a system store. If the system store name provided in this parameter is not the name of an existing system store, a new system store will be created and used. [CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore) can be used to list the names of existing system stores. Some example system stores are listed in the following table.

| Value | Meaning |
| --- | --- |
| **CA** | [Certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) certificates. |
| **MY** | A certificate store that holds certificates with associated private keys. |
| **ROOT** | [Root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). |
| **SPC** | [Software Publisher Certificate](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |

## Return value

If the function succeeds, the function returns a handle to the certificate store.

If the function fails, it returns **NULL**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called function [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) are propagated to this function.

## Remarks

Only current user certificates are accessible using this method, not the local machine store.

After the system store is opened, all the standard certificate store functions can be used to manipulate the certificates.

After use, the store should be closed by using [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore).

For more information about the stores that are automatically migrated, see [Certificate Store Migration](https://learn.microsoft.com/windows/desktop/SecCrypto/certificate-store-migration).

#### Examples

The following example shows a simplified method for opening the most common system certificate stores. For another example that uses this function, see [Example C Program: Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-certificate-store-operations).

```cpp
//--------------------------------------------------------------------
// Declare and initialize variables.

HCERTSTORE  hSystemStore;              // system store handle

//--------------------------------------------------------------------
// Open the CA system certificate store. The same call can be
// used with the name of a different system store, such as My or Root,
// as the second parameter.

if(hSystemStore = CertOpenSystemStore(
    0,
    "CA"))
{
  printf("The CA system store is open. Continue.\n");
}
else
{
  printf("The CA system store did not open.\n");
  exit(1);
}

// Use the store as needed.
// ...

// When done using the store, close it.
if(!CertCloseStore(hSystemStore, 0))
{
  printf("Unable to close the CA system store.\n");
  exit(1);
}
```

> [!NOTE]
> The wincrypt.h header defines CertOpenSystemStore as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore)

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)

[CertGetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlcontextproperty)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[CertSaveStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsavestore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
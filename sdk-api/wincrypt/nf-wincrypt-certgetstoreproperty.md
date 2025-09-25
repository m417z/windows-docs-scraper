# CertGetStoreProperty function

## Description

The **CertGetStoreProperty** function retrieves a store property.

## Parameters

### `hCertStore` [in]

A handle of an open [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `dwPropId` [in]

Indicates one of a range of store properties. There is one predefined store property, CERT_STORE_LOCALIZED_NAME_PROP_ID, the localized name of the store.

User defined properties must be outside the current range of values for predefined context properties. Currently, user defined *dwPropId* values begin at 4,096.

### `pvData` [out]

A pointer to a buffer that receives the data as determined by *dwPropId*. For CERT_STORE_LOCALIZED_NAME_PROP_ID, this is the localized name of the store, and *pvData* points to a null-terminated Unicode wide-character string. For other *dwPropId*s, *pvData* points to an array of bytes.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbData` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the *pvData* buffer. When the function returns, the **DWORD** value contains the number of bytes stored in the buffer.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero.

If the store property is found, the function returns nonzero, *pvData* points to the property, and *pcbData* points to the length of the string. If the store property is not found, the function returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns CRYPT_E_NOT_FOUND.

## Remarks

Store property identifiers are properties applicable to an entire store. They are not properties on an individual [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL), or [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context. Currently, no store properties are persisted.

To find the localized name of a store, you can also use the [CryptFindLocalizedName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindlocalizedname) function.

#### Examples

The following example shows querying a store for its local name property. Similar code can be used to retrieve other store properties. For a complete example that uses this function, see [Example C Program: Setting and Getting Certificate Store Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-certificate-store-properties).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

//--------------------------------------------------------------------
// Declare and initialize variables.
void *pvData = NULL;
DWORD cbData = 0;

//--------------------------------------------------------------------
// Call CertGetStoreProperty a first time
// to get the length of the store name string to be returned.
// hCertStore is a previously assigned HCERTSTORE variable that
// represents an open certificate store.
if(CertGetStoreProperty(
    hCertStore,
    CERT_STORE_LOCALIZED_NAME_PROP_ID,
    NULL,     // NULL on the first call
              // to establish the length of the string
              // to be returned
    &cbData))
{
     printf("The length of the property is %d. \n",cbData);
}
else
{
     printf("The length of the property was not calculated.\n");
     exit(1);
}

//--------------------------------------------------------------------
// cbData is the length of a string to be allocated.
// Allocate the space for the string and call the function a
// second time.
if(pvData = malloc(cbData))
{
     printf("%d bytes of memory allocated.\n",cbData);
}
else
{
     printf("Memory was not allocated.\n");
     exit(1);
}

// Call CertGetStoreProperty a second time
// to copy the local store name into the pvData buffer.
if(CertGetStoreProperty(
    hCertStore,
    CERT_STORE_LOCALIZED_NAME_PROP_ID,
    pvData,
    &cbData))
{
     printf("The localized name is %S.\n",pvData);
}
else
{
     printf("CertGetStoreProperty failed.\n");
     exit(1);
}

// Free memory when done.
if (pvData)
    free(pvData);

```

## See also

[CertSetStoreProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetstoreproperty)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
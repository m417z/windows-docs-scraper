# CertEnumSystemStoreLocation function

## Description

The **CertEnumSystemStoreLocation** function retrieves all of the system store locations. The function calls the provided callback function for each system store location found.

## Parameters

### `dwFlags` [in]

Reserved for future use; must be zero.

### `pvArg` [in]

A pointer to a **void** that allows the application to declare, define, and initialize a structure to hold any information to be passed to the callback enumeration function.

### `pfnEnum` [in]

A pointer to the callback function used to show the details for each store location. This callback function determines the content and format for the presentation of information on each store location. For the signature and parameters of the callback function, see [CertEnumSystemStoreLocationCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_enum_system_store_location).

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

To use **CertEnumSystemStoreLocation**, an application must declare and define the **ENUM_ARG** structure and an enumeration callback function.

#### Examples

For an example that uses this function, see
[Example C Program: Listing System and Physical Stores](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-listing-system-and-physical-stores).

## See also

[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
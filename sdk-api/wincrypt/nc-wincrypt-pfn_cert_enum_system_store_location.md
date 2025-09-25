# PFN_CERT_ENUM_SYSTEM_STORE_LOCATION callback function

## Description

The **CertEnumSystemStoreLocationCallback**
callback function formats and presents information on each system store location found by a call to
[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation).

## Parameters

### `pwszStoreLocation` [in]

String that contains information on the store location found.

### `dwFlags` [in]

Flag used to call for an alteration of the presentation.

### `pvReserved` [in]

Reserved for future use.

### `pvArg` [in]

A pointer to information passed to the callback function in the *pvArg*
passed to [CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation).

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.
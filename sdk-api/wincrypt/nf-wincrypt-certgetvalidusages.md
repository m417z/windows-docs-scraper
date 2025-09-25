# CertGetValidUsages function

## Description

The **CertGetValidUsages** function returns an array of usages that consist of the intersection of the valid usages for all certificates in an array of certificates.

## Parameters

### `cCerts` [in]

The number of certificates in the array to be checked.

### `rghCerts` [in]

An array of certificates to be checked for valid usage.

### `cNumOIDs` [out]

The number of valid usages found as the intersection of the valid usages of all certificates in the array. If all of the certificates are valid for all usages, *cNumOIDs* is set to negative one (–1).

### `rghOIDs` [out]

An array of the [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) of the valid usages that are shared by all of the certificates in the *rghCerts* array. This parameter can be **NULL** to set the size of this structure for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbOIDs` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the *rghOIDs* array and the strings pointed to. When the function returns, the **DWORD** value contains the number of bytes needed for the array.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).
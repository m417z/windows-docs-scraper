# PFN_CERT_ENUM_SYSTEM_STORE callback function

## Description

The **CertEnumSystemStoreCallback**
callback function formats and presents information on each system store found by a call to
[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore).

## Parameters

### `pvSystemStore` [in]

A pointer to information on the system store found by a call to
[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore). Where appropriate, this argument will contain a leading computer name or service name prefix.

### `dwFlags` [in]

Flag used to call for an alteration of the presentation. This can be a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_LOCATION_MASK** | Specifies the location of the system store. |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | If set, the *pvSystemStore* parameter points to a CERT_SYSTEM_STORE_RELOCATE_PARA structure. If not set, *pvSystemStore* points to a **NULL**-terminated Unicode string. |

### `pStoreInfo` [in]

A pointer to a
[CERT_SYSTEM_STORE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_info) structure that contains information about the store.

### `pvReserved` [in]

Reserved for future use.

### `pvArg` [in]

A pointer to information passed to the callback function in the *pvArg*
passed to [CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore).

## Return value

If the function succeeds, the function returns **TRUE**.

To stop the enumeration, the function must return **FALSE**.
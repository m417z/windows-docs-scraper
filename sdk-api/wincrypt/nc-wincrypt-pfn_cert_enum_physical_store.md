# PFN_CERT_ENUM_PHYSICAL_STORE callback function

## Description

The **CertEnumPhysicalStoreCallback**
callback function formats and presents information on each physical store found by a call to
[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore).

## Parameters

### `pvSystemStore` [in]

If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in *dwFlags*, *pvSystemStore* points to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure that indicates both the name and the location of the system store to be enumerated. Otherwise, *pvSystemStore* is a pointer to a Unicode string that names the system store whose physical stores are to be enumerated. For information about prefixing the name of a service or computer to the system store name, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

### `dwFlags` [in]

Specifies the location of the system store. The following flag values are defined:

* CERT_SYSTEM_STORE_CURRENT_USER
* CERT_SYSTEM_STORE_CURRENT_SERVICE
* CERT_SYSTEM_STORE_LOCAL_MACHINE
* CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
* CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY
* CERT_SYSTEM_STORE_SERVICES
* CERT_SYSTEM_STORE_USERS
* CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE

In addition, CERT_SYSTEM_STORE_RELOCATE_FLAG or CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG can be combined using a bitwise-**OR** operation with any of the high-word location flags. The CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG constant is set if the physical store is predefined rather than registered.

### `pwszStoreName` [in]

Name of the physical store.

### `pStoreInfo` [in]

A pointer to a [CERT_PHYSICAL_STORE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_physical_store_info) structure containing information about the store.

### `pvReserved` [in]

Reserved for future use.

### `pvArg` [in]

A pointer to information passed to the callback function in the *pvArg* passed to [CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore).

## Return value

Returns **TRUE** if the function succeeds, **FALSE** if it fails.

## See also

[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
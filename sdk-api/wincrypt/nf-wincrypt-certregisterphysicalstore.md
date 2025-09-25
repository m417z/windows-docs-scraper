# CertRegisterPhysicalStore function

## Description

The **CertRegisterPhysicalStore** function adds a physical store to a registry system store collection.

## Parameters

### `pvSystemStore` [in]

The system store collection to which the physical store is added. This parameter points either to a **null**-terminated Unicode string or to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. For information about using the structure and on adding a ServiceName or ComputerName before the system store name string, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

### `dwFlags` [in]

The high word of the *dwFlags* parameter specifies the location of the system store. For information about defined high-word flags and appending ServiceName, UserNames, and ComputerNames to the end of the system store name, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

The following low-word flags are also defined and can be combined with high-word flags using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | The system store is not in its default registry location and the *pvSystemStore* parameter must be a pointer to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. |
| **CERT_STORE_CREATE_NEW_FLAG** | The function fails if the physical store already exists in the store location. |

### `pwszStoreName` [in]

A pointer to a Unicode string that names the physical store to be added to the system store collection. To remove a physical store from the system store collection, call the [CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore) function.

### `pStoreInfo` [in]

A pointer to a
[CERT_PHYSICAL_STORE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_physical_store_info) structure that provides basic information about the physical store.

### `pvReserved` [in]

Reserved for future use and must be set to **NULL**.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero.

## See also

[CERT_PHYSICAL_STORE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_physical_store_info)

[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertUnregisterPhysicalStore function

## Description

The **CertUnregisterPhysicalStore** function removes a physical store from a specified system store collection. **CertUnregisterPhysicalStore** can also be used to delete the physical store.

## Parameters

### `pvSystemStore` [in]

A pointer to an identifier of the system store collection from which the physical store is to be removed. It is either to a null-terminated Unicode string or to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. For information about using the structure and on appending a ServiceName or ComputerName to the end of the system store name string, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

### `dwFlags` [in]

The high word of the *dwFlags* parameter specifies the location of the system store. For information about defined high-word flags and on appending ServiceName, UserNames, and ComputerNames to the end of the system store name, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

The following low-word values are also defined. They can be combined using bitwise-**OR** operations with high-word values.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | The system store is not in its default registry location and *pvSystemStore* must be a pointer to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. |
| **CERT_STORE_DELETE_FLAG** | The physical store is first removed from the system store collection and is then deleted. |

### `pwszStoreName` [in]

Null-terminated Unicode string that contains the name of the physical store.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## See also

[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para)

[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertUnregisterSystemStore function

## Description

The **CertUnregisterSystemStore** function unregisters a specified system store.

## Parameters

### `pvSystemStore` [in]

Identifies the system store to be unregistered. It points either to a null-terminated Unicode string or to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. For information about using the structure and on appending a ServiceName or ComputerName to the end of the system store name string, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

### `dwFlags` [in]

The high word of the *dwFlags* parameter specifies the location of the system store. For information about defined high-word flags and on appending ServiceName, UserNames, and ComputerNames to the end of the system store name, see
[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore).

The following low-word values are also defined and can be combined with high-word values using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | The system store is not in its default registry location and *pvSystemStore* must be a pointer to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. |
| **CERT_STORE_DELETE_FLAG** | The system store is deleted after it has been unregistered. |

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

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CertEnumPhysicalStore function

## Description

The **CertEnumPhysicalStore** function retrieves the physical stores on a computer. The function calls the provided callback function for each physical store found.

## Parameters

### `pvSystemStore` [in]

If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in *dwFlags*, *pvSystemStore* points to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure that indicates both the name and the location of the system store to be enumerated. Otherwise, *pvSystemStore* is a pointer to a Unicode string that names the system store whose physical stores are to be enumerated. For information about prefixing a ServiceName or ComputerName to the system store name, see
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

In addition, CERT_SYSTEM_STORE_RELOCATE_FLAG or CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG can be combined using a bitwise-**OR** operation with any of the high-word location flags.

### `pvArg` [in]

A pointer to a **void** that allows the application to declare, define, and initialize a structure to hold any information to be passed to the callback enumeration function.

### `pfnEnum` [in]

A pointer to the callback function used to show the details for each physical store. This callback function determines the content and format for the presentation of information on each physical store. The application must provide the [CertEnumPhysicalStoreCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_enum_physical_store) callback function.

## Return value

If the function succeeds and another physical store was found, the return value is **TRUE**.

If the system store location only supports system stores and does not support physical stores, the function returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the ERROR_NOT_SUPPORTED code.

If the function fails and another physical store was not found, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To use **CertEnumPhysicalStore**, an application must declare and define the **ENUM_ARG** structure and an enumeration callback function.

#### Examples

See
[Example C Program: Listing System and Physical Stores](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-listing-system-and-physical-stores).

## See also

[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
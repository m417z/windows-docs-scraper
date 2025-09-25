# CertEnumSystemStore function

## Description

The **CertEnumSystemStore** function retrieves the system stores available. The function calls the provided callback function for each system store found.

## Parameters

### `dwFlags` [in]

Specifies the location of the system store. This parameter can be one of the following flags:

* CERT_SYSTEM_STORE_CURRENT_USER
* CERT_SYSTEM_STORE_CURRENT_SERVICE
* CERT_SYSTEM_STORE_LOCAL_MACHINE
* CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
* CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY
* CERT_SYSTEM_STORE_SERVICES
* CERT_SYSTEM_STORE_USERS
* CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE

In addition, the CERT_SYSTEM_STORE_RELOCATE_FLAG can be combined, by using a bitwise-**OR** operation, with any of the high-word location flags.

### `pvSystemStoreLocationPara` [in, optional]

If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in the *dwFlags* parameter, *pvSystemStoreLocationPara* points to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure that indicates both the name and the location of the system store. Otherwise, *pvSystemStoreLocationPara* is a pointer to a Unicode string that names the system store.

For CERT_SYSTEM_STORE_LOCAL_MACHINE or CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY, *pvSystemStoreLocationPara* can optionally be set to a Unicode computer name for enumerating local computer stores on a remote computer, for example "\\*computer_name*" or "*computer_name*". The leading backslashes (\\) are optional in the *computer_name*.

For CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS, if *pvSystemStoreLocationPara* is **NULL**, the function enumerates both the service/user names and the stores for each service/user name. Otherwise, *pvSystemStoreLocationPara* is a Unicode string that contains a remote computer name and, if available, a service/user name, for example, "*service_name*", "\\*computer_name*", or "*computer_name*\".

If only the *computer_name* is specified, it must have either the leading backslashes (\\) or a trailing backslash (\\). Otherwise, it is interpreted as the *service_name* or *user_name*.

### `pvArg` [in]

A pointer to a **void** that allows the application to declare, define, and initialize a structure to hold any information to be passed to the callback enumeration function.

### `pfnEnum` [in]

A pointer to the callback function used to show the details for each system store. This callback function determines the content and format for the presentation of information on each system store. The application must provide the [CertEnumSystemStoreCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_enum_system_store) callback function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

To use **CertEnumSystemStore**, the application must declare and define the **ENUM_ARG** structure and the [CertEnumSystemStoreCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_enum_system_store) callback function.

#### Examples

For an example that uses this function, see
[Example C Program: Listing System and Physical Stores](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-listing-system-and-physical-stores).

## See also

[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para)

[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertRegisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregistersystemstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
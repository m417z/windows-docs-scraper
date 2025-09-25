# CertRegisterSystemStore function

## Description

The **CertRegisterSystemStore** function registers a system store.

## Parameters

### `pvSystemStore` [in]

Identifies the system store to be registered. If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in the *dwFlags* parameter, *pvSystemStore* points to a
[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. Otherwise, it points to a **null**-terminated Unicode string that names the system store.

With appropriate settings in *dwFlags*, the identified store can be a system store on a remote local computer. Stores on remote computers can be registered with the computer name as a prefix to the name of the system store. For example, a remote local computer store can be registered with *pvSystemStore* pointing to the string "\\ComputerName\Trust" or "ComputerName\Trust".

Leading "\\" backslashes are optional before a ComputerName.

### `dwFlags` [in]

The high word of the *dwFlags* parameter is used to specify the location of the system store.

The following high-word values are defined.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_CURRENT_SERVICE** | *pvSystemStore* can be a system store name that is prefixed with the ServiceName. |
| **CERT_SYSTEM_STORE_CURRENT_USER** | *pvSystemStore* can be a system store name that is prefixed with the UserName. |
| **CERT_SYSTEM_STORE_LOCAL_MACHINE** | *pvSystemStore* can be a system store that is on a remote computer. |
| **CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY** | *pvSystemStore* is a group policy store and can be on a remote computer. |
| **CERT_SYSTEM_STORE_SERVICES** | *pvSystemStore* must be a system store name prefixed with the ServiceName. |
| **CERT_SYSTEM_STORE_USERS** | *pvSystemStore* must be a system store name that is prefixed with the UserName. |

Stores on remote computers can be registered for CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES, CERT_SYSTEM_STORE_USERS, or CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY.

The following low-word values are also defined and can be combined using a bitwise-**OR** operation with high-word values.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | The system store is not in its default register location and *pvSystemStore* must be a pointer to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure. |
| **CERT_STORE_CREATE_NEW_FLAG** | The function fails if the system store already exists in the store location. |

### `pStoreInfo` [in]

Reserved for future use and must be set to **NULL**.

### `pvReserved` [in]

Reserved for future use and must be set to **NULL**.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero.

## Remarks

To unregister a system store that has been registered by this function, call [CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore).

#### Examples

The following example shows adding a system store to a registry system store collection. For an example that includes the complete context for this example, see [Example C Program: Listing System and Physical Stores](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-listing-system-and-physical-stores).

```cpp
//--------------------------------------------------------------------
// Declare and initialize variables.

LPCWSTR pvSystemName= L"NEWSTORE";  // For this setting of
                                    // dwFlags, the store name may
                                    // be prefixed with a user name.
DWORD dwFlags= CERT_SYSTEM_STORE_CURRENT_USER;

if(CertRegisterSystemStore(
    pvSystemName,
    dwFlags,
    NULL,
    NULL))
{
  printf("System store %S is registered. \n",pvSystemName);
}
else
{
  printf("The system store did not register. \n");
  exit(1);
}

```

## See also

[CertEnumPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumphysicalstore)

[CertEnumSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstore)

[CertEnumSystemStoreLocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsystemstorelocation)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CertUnregisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregisterphysicalstore)

[CertUnregisterSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certunregistersystemstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
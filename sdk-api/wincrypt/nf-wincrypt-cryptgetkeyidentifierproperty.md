# CryptGetKeyIdentifierProperty function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptGetKeyIdentifierProperty** acquires a specific property from a specified key identifier.

## Parameters

### `pKeyIdentifier` [in]

A pointer to the
[CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the key identifier.

### `dwPropId` [in]

Identifies the property to retrieve. The value of *dwPropId* determines the type and content of the *pvData* parameter. Any certificate property ID can be used.

### `dwFlags` [in]

The following flags can be used. They can be combined with a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CRYPT_KEYID_MACHINE_FLAG** | Search the list of key identifiers of the LocalMachine (if *pwszComputerName* is **NULL**) or remote computer (if *pwszComputerName* is not **NULL**). For more information, see *pwszComputerName*. |
| **CRYPT_KEYID_ALLOC_FLAG** | The **LocalAlloc()** function is called to allocate memory for *pvData*. **pvData* is updated with a pointer to the allocated memory. **LocalFree()** must be called to free the allocated memory. |

### `pwszComputerName` [in]

A pointer to the name of a remote computer to be searched. If CRYPT_KEYID_MACHINE_FLAG flag is set, searches the remote computer for a list of key identifiers. If the local computer is to be searched and not a remote computer, set *pwszComputerName* to **NULL**.

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

### `pvData` [out]

A pointer to a buffer to receive the data as determined by *dwPropId*. Elements pointed to by fields in the *pvData* structure follow the structure. Therefore, the size contained in *pcbData* can exceed the size of the structure.

If *dwPropId* is CERT_KEY_PROV_INFO_PROP_ID, *pvData* points to a CRYPT_KEY_PROV_INFO structure that contains the property of the key identifier.

If *dwPropId* is not CERT_KEY_PROV_INFO_PROP_ID, *pvData* points to an array of bytes that contains the property of the key identifier.

To get the size of this information for memory allocation purposes, this parameter can be **NULL** when the CRYPT_KEYID_ALLOC_FLAG is not set. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

When the CRYPT_KEYID_ALLOC_FLAG is set, *pvData* is the address of a pointer to the buffer that will be updated. Because memory is allocated and its pointer is stored at **pvData*, *pvData* must not be **NULL**.

### `pcbData` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pvData* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer. The size contained in the variable pointed to by *pcbData* can indicate a size larger than the
[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure because the structure can contain pointers to auxiliary data. This size is the sum of the size needed by the structure and all auxiliary data.

When the CRYPT_KEYID_ALLOC_FLAG is set, *pcbData* is the address of a pointer to the **DWORD** that will be updated.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. On input, buffer sizes are usually specified large enough to ensure that the largest possible output data fits in the buffer. On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CryptEnumKeyIdentifierProperties](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptenumkeyidentifierproperties)

[CryptSetKeyIdentifierProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyidentifierproperty)

[Key Identifier Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
# CERT_PHYSICAL_STORE_INFO structure

## Description

The **CERT_PHYSICAL_STORE_INFO** structure contains information on physical [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Some members of these structures are passed directly to system calls of
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) to open the physical store.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pszOpenStoreProvider`

A pointer to a string that names a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) provider type. This string is passed in a system call to [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) and determines the provider type of a certificate store to be opened. For the names of predefined certificate store types, see
**CertOpenStore**.

In addition to predefined certificate store provider types, new store provider types can be installed and registered with
[CryptInstallOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalloidfunctionaddress) or
[CryptRegisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidfunction). For more information, see
[CertOpenStore](https://learn.microsoft.com/windows/desktop/SecCrypto/extending-certopenstore-functionality).

### `dwOpenEncodingType`

This member is applicable only when CERT_STORE_PROV_MSG, CERT_STORE_PROV_PKCS7, or CERT_STORE_PROV_FILENAME is passed in *lpszStoreProvider*. Otherwise, this member is not used.

It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwOpenFlags`

If a system store is opened with the SERVICES or USERS store location, the **dwOpenFlags** store location is set to CERT_SYSTEM_STORE_USERS or CERT_SYSTEM_STORE_SERVICES.

### `OpenParameters`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains data to be passed to the *pvPara* parameter of the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function. The data type depends on the provider specified. For detailed information about the type and content to be passed, see descriptions of available providers in
**CertOpenStore**.

### `dwFlags`

The following **dwFlags** values for CERT_PHYSICAL_STORE_INFO are defined.

| Value | Meaning |
| --- | --- |
| **CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG** | Enables addition to a [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the store. |
| **CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG** | Set by the [CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore) function. By default, all system stores located in the registry have an implicit SystemRegistry physical store that is opened. To disable the opening of this store, the SystemRegistry physical store that corresponds to the System store must be registered by setting CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG or by registering a physical store named ".Default" with **CertRegisterPhysicalStore**. |
| **CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG** | Disables remote opening of the physical store. |
| **CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG** | Places the string \\ComputerName in front of other provider types. |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | Enables [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) to open a store relative to a user-specified HKEY instead of one of the predefined HKEY constants. For example, HKEY_CURRENT_USER can be replaced with a user-specified HKEY. When CERT_SYSTEM_STORE_RELOCATE_FLAG is set, the *pvPara* parameter passed to **CertOpenStore** points to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure instead of pointing to the store name as a null-terminated [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) or [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string. |

### `dwPriority`

When a system store is opened, its physical stores are ordered according to their **dwPriority** settings. A higher **dwPriority** indicates higher priority. The **dwPriority** member is passed to
[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection).

## See also

[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore)

[CryptInstallOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalloidfunctionaddress)

[CryptRegisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidfunction)
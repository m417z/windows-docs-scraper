# CertOpenStore function

## Description

The **CertOpenStore** function opens a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by using a specified store provider type. While this function can open a certificate store for most purposes,
[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) is recommended to open the most common certificate stores. **CertOpenStore** is required for more complex options and special cases.

## Parameters

### `lpszStoreProvider` [in]

A pointer to a null-terminated ANSI string that contains the store provider type.

The following values represent the predefined store types. The store provider type determines the contents of the *pvPara* parameter and the use and meaning of the high word of the *dwFlags* parameter. Additional store providers can be installed or registered by using
the [CryptInstallOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptinstalloidfunctionaddress) or
[CryptRegisterOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisteroidfunction) function. For more information about adding store providers, see
[Extending CertOpenStore Functionality](https://learn.microsoft.com/windows/desktop/SecCrypto/extending-certopenstore-functionality).

| Value | Meaning |
| --- | --- |
| **CERT_STORE_PROV_COLLECTION**<br><br>**sz_CERT_STORE_PROV_COLLECTION** | Opens a store that will be a collection of other stores. Stores are added to or removed from the collection by using [CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection) and [CertRemoveStoreFromCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certremovestorefromcollection). When a store is added to a collection, all certificates, CRLs, and CTLs in that store become available to searches or enumerations of the collection store.<br><br>The high word of *dwFlags* is set to zero.<br><br>***pvPara* value:** The *pvPara* parameter must be **NULL**. |
| **CERT_STORE_PROV_FILE** | Initializes the store with certificates, CRLs, and CTLs read from a specified open file. This provider expects the file to contain only a serialized store and not either PKCS #7 signed messages or a single encoded certificate.<br><br>The file pointer must be positioned at the beginning of the serialized store information. After the data in the serialized store has been loaded into the certificate store, the file pointer is positioned at the beginning of any data that can follow the serialized store data in the file. If CERT_FILE_STORE_COMMIT_ENABLE is set in *dwFlags*, the file handle is duplicated and the store is always committed as a serialized store. The file is not closed when the store is closed.<br><br>***pvPara* value:** The *pvPara* parameter must contain a pointer to the handle of a file opened by using [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). |
| **CERT_STORE_PROV_FILENAME_A** | Initializes the store with certificates, CRLs, and CTLs from a file. The provider opens the file and first attempts to read the file as a serialized store, then as a PKCS #7 signed message, and finally as a single encoded certificate.<br><br>The *dwEncodingType* parameter must contain the encoding types to be used with both messages and certificates. If the file contains an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) encoded certificate, the open operation fails and a call to the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function will return **ERROR_ACCESS_DENIED**. If the **CERT_FILE_STORE_COMMIT_ENABLE** flag is set in *dwFlags*, the *dwCreationDisposition* value passed to [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) is as follows:<br><br>* If the **CERT_STORE_CREATE_NEW_FLAG** flag is set,   [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) uses **CREATE_NEW**.<br>* If the **CERT_STORE_OPEN_EXISTING_FLAG** flag is set, [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) uses **OPEN_EXISTING**.<br>* For all other settings of *dwFlags*, [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) uses **OPEN_ALWAYS**.<br><br>If *dwFlags* includes **CERT_FILE_STORE_COMMIT_ENABLE**, the file is committed as either a PKCS #7 or a serialized store depending on the file type opened. If the file was empty or if the file name has either a .p7c or .spc extension, the file is committed as a PKCS #7. Otherwise, the file is committed as a serialized store.<br><br>***pvPara* value:** The *pvPara* parameter must contain a pointer to null-terminated ANSI string that contains the name of an existing, unopened file. |
| **CERT_STORE_PROV_FILENAME(_W)**<br><br>**sz_CERT_STORE_PROV_FILENAME(_W)** | Same as **CERT_STORE_PROV_FILENAME_A**.<br><br>***pvPara* value:** The *pvPara* parameter must contain a pointer to null-terminated Unicode string that contains the name of an existing, unopened file. |
| **CERT_STORE_PROV_LDAP(_W)**<br><br>**sz_CERT_STORE_PROV_LDAP(_W)** | Initializes the store with certificates, CRLs, and CTLs from the results of an LDAP query.<br><br>To perform write operations on the store, the query string must specify a BASE query with no filter and a single attribute.<br><br>***pvPara* value:** If the *dwFlags* parameter contains **CERT_LDAP_STORE_OPENED_FLAG**, set *pvPara* to the address of a [CERT_LDAP_STORE_OPENED_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_ldap_store_opened_para) structure that specifies the established LDAP session to use.<br><br>Otherwise, set *pvPara* to point to a null-terminated Unicode string that contains the LDAP query string. For more information about LDAP query strings, see [LDAP Dialect](https://learn.microsoft.com/windows/desktop/ADSI/ldap-dialect). |
| **CERT_STORE_PROV_MEMORY**<br><br>**sz_CERT_STORE_PROV_MEMORY** | Creates a certificate store in cached memory. No certificates, [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), or [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs) are initially loaded into the store. Typically used to create a temporary store.<br><br>Any addition of certificates, CRLs, or CTLs or changes in properties of certificates, CRLs, or CTLs in a memory store are not automatically saved. They can be saved to a file or to a memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) by using [CertSaveStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsavestore).<br><br>***pvPara* value:** The *pvPara* parameter is not used. |
| **CERT_STORE_PROV_MSG** | Initializes the store with certificates, CRLs, and CTLs from the specified cryptographic message. The *dwEncodingType* parameter must contain the encoding types used with both messages and certificates.<br><br>***pvPara* value:** The *pvPara* parameter contains an **HCRYPTMSG** handle of the encoded message, returned by a call to [CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode). |
| **CERT_STORE_PROV_PHYSICAL(_W)**<br><br>**sz_CERT_STORE_PROV_PHYSICAL(_W)** | Initializes the store with certificates, CRLs, and CTLs from a specified physical store that is a member of a logical system store.<br><br>Two names are separated with an intervening backslash (\\), for example "Root\.Default". Here, "Root" is the name of the system store and ".Default" is the name of the physical store. The system and physical store names cannot contain any backslashes. The high word of *dwFlags* indicates the system store location, usually CERT_SYSTEM_STORE_CURRENT_USER. For more information, see *dwFlags* later in this topic and see [System Store Locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations). Some physical store locations can be opened remotely.<br><br>***pvPara* value:** The *pvPara* parameter points to a null-terminated Unicode string that contains both the system store name and physical names. |
| **CERT_STORE_PROV_PKCS7**<br><br>**sz_CERT_STORE_PROV_PKCS7** | Initializes the store with certificates, CRLs, and CTLs from an encoded PKCS #7 signed message. The *dwEncodingType* parameter must specify the encoding types to be used with both messages and certificates.<br><br>***pvPara* value:** The *pvPara* parameter points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the encoded message. |
| **CERT_STORE_PROV_PKCS12**<br><br>**sz_CERT_STORE_PROV_PKCS12** | Initializes the store with the contents of a [PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) packet.<br><br>If the PKCS #12 packet is protected with a NULL or empty password, this function will succeed in opening the store.<br><br>Beginning with Windows 8 and Windows Server 2012, if the password embedded in the PFX packet was protected to an Active Directory (AD) principal and the current user, as a member of that principal, has permission to decrypt the password, this function will succeed in opening the store. For more information, see the *pvPara* parameter and the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag of the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function.<br><br>You can protect PFX passwords to an AD principal beginning in Windows 8 and Windows Server 2012.<br><br>***pvPara* value:** The *pvPara* parameter points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the PKCS #12 packet. |
| **CERT_STORE_PROV_REG** | Initializes the store with certificates, CRLs, and CTLs from a registry subkey.<br><br>This provider opens or creates the registry subkeys **Certificates**, **CRLs**, and **CTLs** under the key passed in *pvPara*. The input key is not closed by the provider. Before returning, the provider opens its own copy of the key passed in *pvPara*. If CERT_STORE_READONLY_FLAG is set in the low word of *dwFlags*, registry subkeys are opened by using the [RegOpenKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeya) with KEY_READ_ACCESS. Otherwise, registry subkeys are created by using [RegCreateKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeya) with KEY_ALL_ACCESS. Any changes to the contents of the opened store are immediately persisted to the registry. However, if CERT_STORE_READONLY_FLAG is set in the low word of *dwFlags*, any attempt to add to the contents of the store or to change a context's property results in an error with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the E_ACCESSDENIED code.<br><br>***pvPara* value:** The *pvPara* parameter contains the handle of an open registry key. |
| **CERT_STORE_PROV_SERIALIZED**<br><br>**sz_CERT_STORE_PROV_SERIALIZED** | Initializes the store with certificates, CRLs, and CTLs from a memory location that contains a serialized store.<br><br>***pvPara* value:** The *pvPara* parameter points to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the serialized memory BLOB. |
| **CERT_STORE_PROV_SMART_CARD(_W)**<br><br>**sz_CERT_STORE_PROV_SMART_CARD(_W)** | Not currently used. |
| **CERT_STORE_PROV_SYSTEM_A** | Initializes the store with certificates, CRLs, and CTLs from the specified system store.<br><br>The system store is a logical, collection store that consists of one or more physical stores. A physical store associated with a system store is registered with the [CertRegisterPhysicalStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certregisterphysicalstore) function. After the system store is opened, all of the physical stores that are associated with it are also opened by calls to **CertOpenStore** and are added to the system store collection by using the [CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection) function. The high word of *dwFlags* indicates the system store location, usually set to CERT_SYSTEM_STORE_CURRENT_USER. For details about registry locations, see *dwFlags* later in this topic and [System Store Locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations). Some system store locations can be opened remotely; for more information, see System Store Locations.<br><br>***pvPara* value:** The *pvPara* parameter points to a null-terminated ANSI string that contains a system store name, such as "My" or "Root". |
| **CERT_STORE_PROV_SYSTEM(_W)**<br><br>**sz_CERT_STORE_PROV_SYSTEM(_W)** | Same as **CERT_STORE_PROV_SYSTEM_A**.<br><br>***pvPara* value:** The *pvPara* parameter points to a null-terminated Unicode string that contains a system store name, such as "My" or "Root". |
| **CERT_STORE_PROV_SYSTEM_REGISTRY_A** | Initializes the store with certificates, CRLs, and CTLs from a physical registry store. The physical store is not opened as a collection store. Enumerations and searches go through only the certificates, CRLs, and CTLs in that one physical store.<br><br>The high word of *dwFlags* indicates the system store location, usually set to CERT_SYSTEM_STORE_CURRENT_USER. For more information, see *dwFlags* later in this topic. Some system store locations can be open remotely; for more information, see [System Store Locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations).<br><br>***pvPara* value:** The *pvPara* parameter points to a null-terminated ANSI string that contains a system store name, such as "My" or "Root". |
| **CERT_STORE_PROV_SYSTEM_REGISTRY(_W)**<br><br>**sz_CERT_STORE_PROV_SYSTEM_REGISTRY(_W)** | Same as **CERT_STORE_PROV_SYSTEM_REGISTRY_A**.<br><br>***pvPara* value:** The *pvPara* parameter points to a null-terminated Unicode string that contains a system store name, such as "My" or "Root". |

### `dwEncodingType` [in]

Specifies the [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly). Encoding is used only when the *dwSaveAs* parameter of the [CertSaveStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsavestore) function contains **CERT_STORE_SAVE_AS_PKCS7**. Otherwise, the *dwMsgAndCertEncodingType* parameter is not used.

This parameter is only applicable when the **CERT_STORE_PROV_MSG**, **CERT_STORE_PROV_PKCS7**, or **CERT_STORE_PROV_FILENAME** provider type is specified in the *lpszStoreProvider* parameter. For all other provider types, this parameter is unused and should be set to zero.

This parameter can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies PKCS #7 message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to a cryptographic provider. Passing **NULL** for this parameter causes an appropriate, default provider to be used. Using the default provider is recommended. The default or specified cryptographic provider is used for all store functions that verify the signature of a subject certificate or CRL.This parameter's data type is **HCRYPTPROV**.

### `dwFlags` [in]

These values consist of high-word and low-word values combined by using a bitwise-**OR** operation.

The low-word portion of *dwFlags* controls a variety of general characteristics of the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) opened. This portion can be used with all store provider types. The low-word portion of *dwFlags* can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_BACKUP_RESTORE_FLAG** | Use the thread's SE_BACKUP_NAME and SE_RESTORE_NAME [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to open registry or file-based system stores. If the thread does not have these privileges, this function must fail with an access denied error. |
| **CERT_STORE_CREATE_NEW_FLAG** | A new store is created if one did not exist. The function fails if the store already exists.<br><br>If neither **CERT_STORE_OPEN_EXISTING_FLAG** nor **CERT_STORE_CREATE_NEW_FLAG** is set, a store is opened if it exists or is created and opened if it did not already exist. |
| **CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG** | Defer closing of the store's provider until all certificates, CRLs, or CTLs obtained from the store are no longer in use. The store is actually closed when the last certificate, CRL, or CTL obtained from the store is freed. Any changes made to properties of these certificates, CRLs, and CTLs, even after the call to [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore), are persisted.<br><br>If this flag is not set and certificates, CRLs, or CTLs obtained from the store are still in use, any changes to the properties of those certificates, CRLs, and CTLs will not be persisted.<br><br>If this function is called with **CERT_CLOSE_STORE_FORCE_FLAG**, **CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG** is ignored.<br><br>When this flag is set and a non-**NULL** *hCryptProv* parameter value is passed, that provider will continue to be used even after the call to this function. |
| **CERT_STORE_DELETE_FLAG** | The store is deleted instead of being opened. This function returns **NULL** for both success and failure of the deletion. To determine the success of the deletion, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns zero if the store was deleted and a nonzero value if it was not deleted. |
| **CERT_STORE_ENUM_ARCHIVED_FLAG** | Normally, an enumeration of all certificates in the store will ignore any certificate with the **CERT_ARCHIVED_PROP_ID** property set. If this flag is set, an enumeration of the certificates in the store will contain all of the certificates in the store, including those that have the **CERT_ARCHIVED_PROP_ID** property. |
| **CERT_STORE_MAXIMUM_ALLOWED_FLAG** | Open the store with the maximum set of allowed permissions. If this flag is specified, registry stores are first opened with write access and if that fails, they are reopened with read-only access. |
| **CERT_STORE_NO_CRYPT_RELEASE_FLAG** | This flag is not used when the *hCryptProv* parameter is **NULL**. This flag is only valid when a non-**NULL** CSP handle is passed as the *hCryptProv* parameter. Setting this flag prevents the automatic release of a nondefault CSP when the certificate store is closed. |
| **CERT_STORE_OPEN_EXISTING_FLAG** | Only open an existing store. If the store does not exist, the function fails. |
| **CERT_STORE_READONLY_FLAG** | Open the store in read-only mode. Any attempt to change the contents of the store will result in an error. When this flag is set and a registry based store provider is being used, the registry subkeys are opened by using [RegOpenKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeya) with **KEY_READ_ACCESS**. Otherwise, the registry subkeys are created by using [RegCreateKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeya) with **KEY_ALL_ACCESS**. |
| **CERT_STORE_SET_LOCALIZED_NAME_FLAG** | If this flag is supported, the provider sets the store's **CERT_STORE_LOCALIZED_NAME_PROP_ID** property. The localized name can be retrieved by calling the [CertGetStoreProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetstoreproperty) function with *dwPropID* set to **CERT_STORE_LOCALIZED_NAME_PROP_ID**. This flag is supported for providers of types **CERT_STORE_PROV_FILENAME**, **CERT_STORE_PROV_SYSTEM**, **CERT_STORE_PROV_SYSTEM_REGISTRY**, and **CERT_STORE_PROV_PHYSICAL_W**. |
| **CERT_STORE_SHARE_CONTEXT_FLAG** | When opening a store multiple times, you can set this flag to ensure efficient memory usage by reusing the memory for the encoded parts of a certificate, CRL, or CTL context across the opened instances of the stores. |
| **CERT_STORE_UPDATE_KEYID_FLAG** | Lists of key identifiers exist within CurrentUser and LocalMachine. These key identifiers have properties much like the properties of certificates. If the **CERT_STORE_UPDATE_KEYID_FLAG** is set, then for every key identifier in the store's location that has a **CERT_KEY_PROV_INFO_PROP_ID** property, that property is automatically updated from the key identifier property **CERT_KEY_PROV_INFO_PROP_ID** or the **CERT_KEY_IDENTIFIER_PROP_ID** of the certificate related to that key identifier. |

The **CERT_STORE_PROV_SYSTEM**,
**CERT_STORE_PROV_SYSTEM_REGISTRY**, and
**CERT_STORE_PROV_PHYSICAL** provider types use the following high words of *dwFlags* to specify system store registry locations:

#### CERT_SYSTEM_STORE_CURRENT_SERVICE

#### CERT_SYSTEM_STORE_CURRENT_USER

#### CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY

#### CERT_SYSTEM_STORE_LOCAL_MACHINE

#### CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE

#### CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY

#### CERT_SYSTEM_STORE_SERVICES

#### CERT_SYSTEM_STORE_USERS

By default, a system store location is opened relative to the **HKEY_CURRENT_USER**, **HKEY_LOCAL_MACHINE**, or **HKEY_USERS** predefined registry key. For more information, see
[System Store Locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations).

The following high-word flags override this default behavior.

| Value | Meaning |
| --- | --- |
| **CERT_SYSTEM_STORE_RELOCATE_FLAG** | When set, *pvPara* must contain a pointer to a [CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para) structure rather than a string. The structure indicates both the name of the store and its location in the registry. |
| **CERT_SYSTEM_STORE_UNPROTECTED_FLAG** | By default, when the CurrentUser "Root" store is opened, any SystemRegistry roots not on the protected root list are deleted from the cache before this function returns. When this flag is set, this default is overridden and all of the roots in the SystemRegistry are returned and no check of the protected root list is made. |

The **CERT_STORE_PROV_REGISTRY** provider uses the following high-word flags.

| Value | Meaning |
| --- | --- |
| **CERT_REGISTRY_STORE_REMOTE_FLAG** | *pvPara* contains a handle to a registry key on a remote computer. To access a registry key on a remote computer, security permissions on the remote computer must be set to allow access. For more information, see Remarks. |
| **CERT_REGISTRY_STORE_SERIALIZED_FLAG** | The **CERT_STORE_PROV_REG** provider saves certificates, CRLs, and CTLs in a single serialized store subkey instead of performing the default save operation. The default is that each certificate, CRL, or CTL is saved as a separate registry subkey under the appropriate subkey.<br><br>This flag is mainly used for stores downloaded from the group policy template (GPT), such as the CurrentUserGroupPolicy and LocalMachineGroupPolicy stores.<br><br>When **CERT_REGISTRY_STORE_SERIALIZED_FLAG** is set, store additions, deletions, or property changes are not persisted until there is a call to either [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) or [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore) using **CERT_STORE_CTRL_COMMIT**. |

The **CERT_STORE_PROV_FILE** and **CERT_STORE_PROV_FILENAME** provider types use the following high-word flags.

| Value | Meaning |
| --- | --- |
| **CERT_FILE_STORE_COMMIT_ENABLE** | Setting this flag commits any additions to the store or any changes made to properties of contexts in the store to the file store either when [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) is called or when [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore) is called with **CERT_STORE_CONTROL_COMMIT**.<br><br>**CertOpenStore** fails with **E_INVALIDARG** if both **CERT_FILE_STORE_COMMIT_ENABLE** and **CERT_STORE_READONLY_FLAG** are set in *dwFlags*. |

The **CERT_STORE_PROV_LDAP** provider type uses the following high-word flags.

| Value | Meaning |
| --- | --- |
| **CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG** | Performs an A-Record-only DNS lookup on the URL named in the *pvPara* parameter. This prevents false DNS queries from being generated when resolving URL host names. Use this flag when passing a host name as opposed to a domain name for the *pvPara* parameter. |
| **CERT_LDAP_STORE_OPENED_FLAG** | Use this flag to use an existing LDAP session. When this flag is specified, the *pvPara* parameter is the address of a [CERT_LDAP_STORE_OPENED_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_ldap_store_opened_para) structure that contains information about the LDAP session to use. |
| **CERT_LDAP_STORE_SIGN_FLAG** | To provide integrity required by some applications, digitally sign all LDAP traffic to and from an LDAP server by using the Kerberos authentication protocol. |
| **CERT_LDAP_STORE_UNBIND_FLAG** | Use this flag with the **CERT_LDAP_STORE_OPENED_FLAG** flag to cause the LDAP session to be unbound when the store is closed. The system will unbind the LDAP session by using the [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) function when the store is closed. |

### `pvPara` [in]

A 32-bit value that can contain additional information for this function. The contents of this parameter depends on the value of the *lpszStoreProvider* and other parameters.

## Return value

If the function succeeds, the function returns a handle to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). When you have finished using the store, release the handle by calling the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.

If the function fails, it returns **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea), [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile), or registry errors might be propagated and their error codes returned. **CertOpenStore** has a single error code of its own, the ERROR_FILE_NOT_FOUND code, which indicates that the function was unable to find the provider specified by the *lpszStoreProvider* parameter.

## Remarks

A system store is a collection that consists of one or more physical sibling stores. For each system store, there are predefined physical sibling stores. After opening a system store such as "My" at CERT_SYSTEM_STORE_CURRENT_USER, **CertOpenStore** is called to open all of the physical stores in the system store collection. Each of these physical stores is added to the system store collection by using
the [CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection) function. All certificates, CRLs, and CTLs in those physical stores are available through the logical system store collection.

**Note** The order of the certificate context may not be preserved within the store.
To access a specific certificate you must iterate across the certificates in the store.

The following system store locations can be opened remotely:

* CERT_SYSTEM_STORE_LOCAL_MACHINE
* CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
* CERT_SYSTEM_STORE_SERVICES
* CERT_SYSTEM_STORE_USERS

System store locations are opened remotely by prefixing the store name in the string passed to *pvPara* with the computer name. Examples of remote system store names are:

* *ComputerName*\*CA*
* \\*ComputerName*\*CA*
* *ComputerName*\*ServiceName*\*Trust*
* \\*ComputerName*\*ServiceName*\*Trust*

For more information about system stores, see
[System Store Locations](https://learn.microsoft.com/windows/desktop/SecCrypto/system-store-locations).

For more information about the stores that are automatically migrated, see [Certificate Store Migration](https://learn.microsoft.com/windows/desktop/SecCrypto/certificate-store-migration).

#### Examples

The following example shows opening several certificate stores of different store provider types. The example uses the **CreateMyDACL** function, defined in the [Creating a DACL](https://learn.microsoft.com/windows/desktop/SecBP/creating-a-dacl) topic, to ensure the open file is created with a proper DACL. For more examples of opening other store provider types, see
[Example C Code for Opening Certificate Stores](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-code-for-opening-certificate-stores).

```cpp
//-------------------------------------------------------------------
// Open a system store, in this case, the My store.

HCERTSTORE hSysStore = NULL;
if(hSysStore = CertOpenStore(
   CERT_STORE_PROV_SYSTEM,          // The store provider type
   0,                               // The encoding type is
                                    // not needed
   NULL,                            // Use the default HCRYPTPROV
   CERT_SYSTEM_STORE_CURRENT_USER,  // Set the store location in a
                                    // registry location
   L"MY"                            // The store name as a Unicode
                                    // string
   ))
{
    printf("The system store was created successfully.\n");
}
else
{
    printf("An error occurred during creation "
        "of the system store!\n");
    exit(1);
}

// Other common system stores include "Root", "Trust", and "Ca".

//-------------------------------------------------------------------
// Open a memory store.

HCERTSTORE hMemStore = NULL;
if(hMemStore = CertOpenStore(
   CERT_STORE_PROV_MEMORY,   // The memory provider type
   0,                        // The encoding type is not needed
   NULL,                     // Use the default HCRYPTPROV
   0,                        // Accept the default dwFlags
   NULL                      // pvPara is not used
   ))
{
    printf("The memory store was created successfully.\n");
}
else
{
    printf("An error occurred during creation "
        "of the memory store!\n");
    exit(1);
}

//-------------------------------------------------------------------
// Open a read-only store from disk.

HANDLE       hFile = NULL;
HCERTSTORE   hFileStore = NULL;
LPCSTR       pszFileName = "TestStor2.sto";
SECURITY_ATTRIBUTES  sa;        // For DACL

// Create a DACL to use when opening the file.
sa.nLength = sizeof(SECURITY_ATTRIBUTES);
sa.bInheritHandle = FALSE;

// Call function to set the DACL. The DACL is set in the
// SECURITY_ATTRIBUTES lpSecurityDescriptor member.
if (!CreateMyDACL(&sa))
{
     // Error encountered; generate message and exit.
     printf("Failed CreateMyDACL.\n");
        exit(1);
}

// Obtain the file handle of an existing file.
if (hFile = CreateFile(
     pszFileName,                  // The file name
     GENERIC_READ|GENERIC_WRITE,   // Access mode: Read from and
                                   // write to this file
     0,                            // Share mode
     &sa,                          // Uses the DACL created
                                   // previously
     OPEN_ALWAYS,                  // How to create
     FILE_ATTRIBUTE_NORMAL,        // File attributes
     NULL))                        // Template
{
    printf("The file was opened successfully.\n");
}
else
{
    printf("An error occurred during opening of the file!\n");
    exit(1);
}

//-------------------------------------------------------------------
//  This file can contain data before the store itself.
//  At this point, read and use data in the open file that precedes
//  the serialized certificate store data.
//  To open the certificate store, the file pointer must
//  be placed at the beginning of the certificate store data.

//-------------------------------------------------------------------
//  Open the store.

if(hFileStore = CertOpenStore(
    CERT_STORE_PROV_FILE,     // Load certificates from a file
    0,                        // Encoding type not used
    NULL,                     // Use the default HCRYPTPROV
    CERT_STORE_READONLY_FLAG, // Read-only store
    hFile                     // The handle for the open file
                              // that is the source of the
                              // certificates
    ))
{
    printf("The file store was created successfully.\n");
}
else
{
    printf("An error occurred during creation of the file store!\n");
    exit(1);
}

//-------------------------------------------------------------------
// After processing, close the certificate stores and the file.

if(CertCloseStore(
        hSysStore,
        CERT_CLOSE_STORE_CHECK_FLAG))
{
    printf("The system store was closed successfully.\n");
}
else
{
    printf("An error occurred during closing of the "
        "system store.\n");
}

if(CertCloseStore(
        hMemStore,
        CERT_CLOSE_STORE_CHECK_FLAG))
{
    printf("The memory store was closed successfully.\n");
}
else
{
    printf("An error occurred during closing of the "
        "memory store.\n");
}

if(CertCloseStore(
        hFileStore,
        CERT_CLOSE_STORE_CHECK_FLAG))
{
    printf("The file store was closed successfully.\n");
}
else
{
    printf("An error occurred during closing of the file store.\n");
}

if(CloseHandle(hFile))
{
    printf("The file was closed successfully.\n");
}
else
{
    printf("An error occurred during closing of the file.\n");
}

```

## See also

[CERT_SYSTEM_STORE_RELOCATE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_system_store_relocate_para)

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)

[CertSaveStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsavestore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)
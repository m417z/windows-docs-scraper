# CryptCATOpen function

## Description

[The **CryptCATOpen** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATOpen** function opens a catalog and returns a context handle to the open catalog.

**Note** Some older versions of Wintrust.lib do not contain the export information for this function. In this case, you must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `pwszFileName` [in]

A pointer to a null-terminated string for the catalog file name.

### `fdwOpenFlags` [in]

Zero, to open an existing catalog file, or a bitwise combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTCAT_OPEN_ALWAYS** | Opens the file, if it exists, or creates a new file, if needed. |
| **CRYPTCAT_OPEN_CREATENEW** | A new catalog file is created. If a previously created file exists, it is overwritten. |
| **CRYPTCAT_OPEN_EXISTING** | An existing catalog file is opened. |
| **CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES** | An existing catalog file is opened. Exclude page hashes in SPC_INDIRECT_DATA. |
| **CRYPTCAT_OPEN_INCLUDE_PAGE_HASHES** | An existing catalog file is opened. Include page hashes in SPC_INDIRECT_DATA. The above CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES takes precedence if also set. |
| **CRYPTCAT_OPEN_VERIFYSIGHASH** | An existing catalog file is opened. Verifies the signature, not the certificates. |
| **CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG** | An existing catalog file is opened. Does CryptMsgDecode without content. |
| **CRYPTCAT_OPEN_SORTED** | An existing catalog file is opened. Does CertCreateContext(CERT_CREATE_CONTEXT_SORTED_FLAG). |

### `hProv` [in]

A handle to a cryptographic service provider (CSP).

### `dwPublicVersion` [in]

Version of the file. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTCAT_VERSION_1**<br><br>0x100 | Version 1 file format. |
| **CRYPTCAT_VERSION_2**<br><br>0x200 | Version 2 file format.<br><br>**Windows 8 and Windows Server 2012:** Support for this value begins. |

### `dwEncodingType` [in]

Encoding type used for the file. If this value is 0, then the encoding type is set to PKCS_7_ASN_ENCODING | X509_ASN_ENCODING.

## Return value

Upon success, this function returns a handle to the open catalog. When you have finished using the handle, close it by calling the [CryptCATClose](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatclose) function. The **CryptCATOpen** function returns INVALID_HANDLE_VALUE if it fails.

## See also

[CryptCATClose](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatclose)
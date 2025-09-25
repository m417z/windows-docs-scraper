# WINTRUST_BLOB_INFO structure

## Description

[The **WINTRUST_BLOB_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **WINTRUST_BLOB_INFO** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to verify a memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

**Note** This structure is not currently supported for the following Inbox file formats. There may be other formats besides these that are not supported.

* Portable executable (such as .exe, .dll, .ocx)
* Cab files (.cab)
* Catalog files (.cat)

This structure is only supported by files formats with [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) providers that support this structure.

## Members

### `cbStruct`

The number of bytes in this structure.

### `gSubject`

The **GUID** of the SIP to load.

### `pcwszDisplayName`

A string that contains the name of the memory object pointed to by **pbMem**.

### `cbMemObject`

The length, in bytes, of the memory BLOB to be verified.

### `pbMemObject`

A pointer to a memory BLOB to be verified.

### `cbMemSignedMsg`

This member is reserved. Do not use it.

### `pbMemSignedMsg`

This member is reserved. Do not use it.
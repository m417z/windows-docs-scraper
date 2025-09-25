# AMSI_ATTRIBUTE enumeration

## Description

The **AMSI_ATTRIBUTE** enumeration specifies the types of attributes that can be requested by [IAmsiStream::GetAttribute](https://learn.microsoft.com/windows/desktop/api/amsi/nf-amsi-iamsistream-getattribute).

## Constants

### `AMSI_ATTRIBUTE_APP_NAME`

Return the name, version, or GUID string of the calling application, copied from a **LPWSTR**.

### `AMSI_ATTRIBUTE_CONTENT_NAME`

Return the filename, URL, unique script ID, or similar of the content, copied from a **LPWSTR**.

### `AMSI_ATTRIBUTE_CONTENT_SIZE`

Return the size of the input, as a **ULONGLONG**.

### `AMSI_ATTRIBUTE_CONTENT_ADDRESS`

Return the memory address if the content is fully loaded into memory.

### `AMSI_ATTRIBUTE_SESSION`

Session is used to associate different scan calls, such as if the contents to be scanned belong to the sample original script. Return a **PVOID** to the next portion of the content to be scanned. Return **nullptr** if the content is self-contained.

### `AMSI_ATTRIBUTE_REDIRECT_CHAIN_SIZE`

### `AMSI_ATTRIBUTE_REDIRECT_CHAIN_ADDRESS`

### `AMSI_ATTRIBUTE_ALL_SIZE`

### `AMSI_ATTRIBUTE_ALL_ADDRESS`

### `AMSI_ATTRIBUTE_QUIET`
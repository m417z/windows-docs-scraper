# ITEM_INFO structure

## Description

Contains information passed to the [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object about the current item; for example, the application name and catalog name.

## Members

### `dwSize`

Type: **DWORD**

Size of the structure in bytes.

### `pcwszFromEMail`

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing an email address that is notified in case of error.

### `pcwszApplicationName`

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing the application name.

### `pcwszCatalogName`

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing the workspace name from which the crawl to this content source was initiated.

### `pcwszContentClass`

Type: **LPCWSTR**

Not used by protocol handlers.
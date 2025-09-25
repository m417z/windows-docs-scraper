# BCRYPT_KEY_DATA_BLOB_HEADER structure

## Description

The **BCRYPT_KEY_DATA_BLOB_HEADER** structure is used to contain information about a key data BLOB. The key data BLOB must immediately follow this structure in memory.

## Members

### `dwMagic`

The magic value for the key.

This member must be the following value.

#### BCRYPT_KEY_DATA_BLOB_MAGIC (0x4d42444b)

### `dwVersion`

Contains the numeric version of the key.

| Value | Meaning |
| --- | --- |
| **BCRYPT_KEY_DATA_BLOB_VERSION1**<br><br>1 | Version 1. |

### `cbKeyData`

The size, in bytes, of the key data.

## See also

[BCryptExportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptexportkey)

[BCryptImportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkey)
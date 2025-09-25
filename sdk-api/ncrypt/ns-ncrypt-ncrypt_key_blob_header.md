# NCRYPT_KEY_BLOB_HEADER structure

## Description

The **NCRYPT_KEY_BLOB_HEADER** structure contains a key **BLOB**. This structure is used by the [NCryptExportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptexportkey) and [NCryptImportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptimportkey) functions.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwMagic`

Identifies the **BLOB** type. This can be one of the following values.

* NCRYPT_CIPHER_KEY_BLOB_MAGIC
* NCRYPT_PROTECTED_KEY_BLOB_MAGIC

### `cbAlgName`

Size, in bytes, of the null-terminated algorithm name, including the terminating zero.

### `cbKeyData`

Size, in bytes, of the **BLOB**.

## See also

[NCryptExportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptexportkey)

[NCryptImportKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptimportkey)
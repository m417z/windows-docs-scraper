# CATALOG_INFO structure

## Description

[The **CATALOG_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CATALOG_INFO** structure contains the name of a catalog file. This structure is used by the [CryptCATCatalogInfoFromContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcataloginfofromcontext) function.

## Members

### `cbStruct`

Specifies the size, in bytes, of this structure.

### `wszCatalogFile`

Name of the catalog file.

## See also

[CryptCATCatalogInfoFromContext](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcataloginfofromcontext)
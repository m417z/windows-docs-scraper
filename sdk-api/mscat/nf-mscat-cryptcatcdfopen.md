# CryptCATCDFOpen function

## Description

[The **CryptCATCDFOpen** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The [CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf) structure. **CryptCATCDFOpen** is called by [MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat).

## Parameters

### `pwszFilePath` [in]

A pointer to a null-terminated string that contains the path of the CDF file to open.

### `pfnParseError` [in, optional]

A pointer to a user-defined function to handle file parse errors.

## Return value

Upon success, this function returns a pointer to the newly created [CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf) structure. The **CryptCATCDFOpen** function returns a **NULL** pointer if it fails.

## Remarks

The following default values are used by the **CryptCATCDFOpen** function for given conditions in the CDF **CatalogHeader** section.

| **CatalogHeader** condition | Default value |
| --- | --- |
| No **Name** value is specified. | The file name in *pwszFilePath* is used for the catalog (.cat) output file. |
| No **PublicVersion** value is specified. | 0x00000001 |
| No **EncodingType** value is specified. | **PKCS_7_ASN_ENCODING** or **X509_ASN_ENCODING** (0x00010001) |

The following actions are performed by the **CryptCATCDFOpen** function for given error conditions.

| Error condition | Action performed |
| --- | --- |
| No **CatalogHeader** or **Name** tags are found in CDF. | If specified by the caller, the **CryptCATCDFOpen** function calls the function specified by *pfnParseError* and returns a **NULL** pointer. |
| The **CryptCATCDFOpen** function calls the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) function to get a handle to the catalog (.cat) output file, but it gets an invalid or **NULL** handle. | Calls the [CryptCATCDFClose](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcdfclose) function and returns a **NULL** pointer. |

| Additional OIDs for the Catalog branch | Definition |
| --- | --- |
| szOID_CATALOG_LIST_MEMBER_V2 | 1.3.6.1.4.1.311.12.1.3 |
| CAT_MEMBERINFO2_OBJID | 1.3.6.1.4.1.311.12.2.3 |

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** The additional Catalog OIDs are not available.

## See also

[CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf)

[CryptCATCDFClose](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcdfclose)

[CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen)

[MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat)
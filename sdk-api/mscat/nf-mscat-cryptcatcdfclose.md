# CryptCATCDFClose function

## Description

[The **CryptCATCDFClose** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The [CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf) structure. **CryptCATCDFClose** is called by [MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat).

## Parameters

### `pCDF` [in]

A pointer to a [CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf) structure.

## Return value

Upon success, this function returns **TRUE**. The **CryptCATCDFClose** function returns **FALSE** with an **ERROR_INVALID_PARAMETER** error if it fails.

## Remarks

Before closing the catalog output file specified in *pCDF*, the **CryptCATCDFClose** function signs and persists it to the file system.

## See also

[CRYPTCATCDF](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatcdf)

[MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat)
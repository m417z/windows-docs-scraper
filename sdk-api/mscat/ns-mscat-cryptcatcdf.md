# CRYPTCATCDF structure

## Description

[The **CRYPTCATCDF** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTCATCDF** structure contains information used to create a signed catalog file (.cat) from a catalog definition file (CDF). This structure is used by the [MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat) tool.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `hFile`

A handle to the catalog definition file (.cdf).

### `dwCurFilePos`

A value that specifies the current position of the parser measured in bytes from the beginning of the catalog definition file.

### `dwLastMemberOffset`

A value that specifies the number of bytes to the position of the last member parsed in the catalog definition file.

### `fEOF`

An integer that indicates whether the parser finished reading the file. **TRUE** indicates that the last read operation returned zero bytes.

### `pwszResultDir`

A pointer to a null-terminated string that contains the name of a directory where the catalog file (.cat) will be written.

### `hCATStore`

A handle to the catalog file (.cat).

## Remarks

A parser can update *dwCurFilePos* and *dwLastMemberOffset* as it reads the CDF. A user-defined callback function can use this information for recoverable parse errors in the CDF.

## See also

[CryptCATCDFClose](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcdfclose)

[CryptCATCDFEnumAttributesWithCDFTag](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptcatcdfenumattributeswithcdftag)

[CryptCATCDFEnumCatAttributes](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcdfenumcatattributes)

[CryptCATCDFEnumMembersByCDFTagEx](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptcatcdfenummembersbycdftagex)

[CryptCATCDFOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatcdfopen)

[MakeCat](https://learn.microsoft.com/windows/desktop/SecCrypto/makecat)
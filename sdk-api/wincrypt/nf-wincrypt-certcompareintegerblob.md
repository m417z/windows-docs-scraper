# CertCompareIntegerBlob function

## Description

The **CertCompareIntegerBlob** function compares two integer [BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to determine whether they represent equal numeric values.

## Parameters

### `pInt1` [in]

A pointer to a
[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the first integer in the comparison.

### `pInt2` [in]

A pointer to a [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the second integer in the comparison.

## Return value

If the representations of the integer BLOBs are identical and the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before doing the comparison, most significant bytes with a value of 0x00 are removed from a positive number. Positive here means that the most significant bit in the next nonzero byte is not set.

Most significant bytes with a value of 0xFF are removed from a negative number. Negative here means that the most significant bit in the next non-0xFF byte is set. This produces the unique representation of that integer, as shown in the following table.

| Original bytes | Reduced form |
| --- | --- |
| 0xFFFFFF88 | 0xFF88 |
| 0xFF23 | 0xFF23 |
| 0x007F | 0x7F |
| 0x00000080 | 0x80 |

Multiple-byte integers are treated as [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). The least significant byte is *pbData*[0]. The most significant byte is *pbData*[*cbData* - 1], that is, 0xFFFFFF88 is stored in four bytes as:

{0x88, 0xFF, 0xFF, 0xFF}

#### Examples

For an example that uses this function, see
[Example C Program: Using CertOIDToAlgId and CertCompareIntegerBlob](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-using-certoidtoalgid-and-certcompareintegerblob).

## See also

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)
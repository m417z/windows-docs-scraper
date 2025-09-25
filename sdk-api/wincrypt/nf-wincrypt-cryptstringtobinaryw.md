# CryptStringToBinaryW function

## Description

The **CryptStringToBinary** function converts a formatted string into an array of bytes.

## Parameters

### `pszString` [in]

A pointer to a string that contains the formatted string to be converted.

### `cchString` [in]

The number of characters of the formatted string to be converted, not including the terminating **NULL** character. If this parameter is zero, *pszString* is considered to be a null-terminated string.

### `dwFlags` [in]

Indicates the format of the string to be converted. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_STRING_BASE64HEADER**<br><br>0x00000000 | Base64 between lines of the form `-----BEGIN ...-----` and `-----END ...-----`. See Remarks below. |
| **CRYPT_STRING_BASE64**<br><br>0x00000001 | Base64, without headers. |
| **CRYPT_STRING_BINARY**<br><br>0x00000002 | Pure binary copy. |
| **CRYPT_STRING_BASE64REQUESTHEADER**<br><br>0x00000003 | Base64 between lines of the form `-----BEGIN ...-----` and `-----END ...-----`. See Remarks below. |
| **CRYPT_STRING_HEX**<br><br>0x00000004 | Hexadecimal only format. |
| **CRYPT_STRING_HEXASCII**<br><br>0x00000005 | Hexadecimal format with [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) character display. |
| **CRYPT_STRING_BASE64_ANY**<br><br>0x00000006 | Tries the following, in order: <br><br>CRYPT_STRING_BASE64HEADER<br><br>CRYPT_STRING_BASE64 |
| **CRYPT_STRING_ANY**<br><br>0x00000007 | Tries the following, in order: <br><br>CRYPT_STRING_BASE64HEADER<br><br>CRYPT_STRING_BASE64<br><br>CRYPT_STRING_BINARY |
| **CRYPT_STRING_HEX_ANY**<br><br>0x00000008 | Tries the following, in order: <br><br>CRYPT_STRING_HEXADDR<br><br>CRYPT_STRING_HEXASCIIADDR<br><br>CRYPT_STRING_HEX<br><br>CRYPT_STRING_HEXRAW<br><br>CRYPT_STRING_HEXASCII |
| **CRYPT_STRING_BASE64X509CRLHEADER**<br><br>0x00000009 | Base64 between lines of the form `-----BEGIN ...-----` and `-----END ...-----`. See Remarks below. |
| **CRYPT_STRING_HEXADDR**<br><br>0x0000000a | Hex, with address display. |
| **CRYPT_STRING_HEXASCIIADDR**<br><br>0x0000000b | Hex, with ASCII character and address display. |
| **CRYPT_STRING_HEXRAW**<br><br>0x0000000c | A raw hexadecimal string.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRYPT_STRING_STRICT**<br><br>0x20000000 | Set this flag for Base64 data to specify that the end of the binary data contain only white space and at most three equals "=" signs.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `pbBinary` [in]

A pointer to a buffer that receives the returned sequence of bytes. If this parameter is **NULL**, the function calculates the length of the buffer needed and returns the size, in bytes, of required memory in the **DWORD** pointed to by *pcbBinary*.

### `pcbBinary` [in, out]

A pointer to a **DWORD** variable that, on entry, contains the size, in bytes, of the *pbBinary* buffer. After the function returns, this variable contains the number of bytes copied to the buffer. If this value is not large enough to contain all of the data, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_MORE_DATA**.

If *pbBinary* is **NULL**, the **DWORD** pointed to by *pcbBinary* is ignored.

### `pdwSkip` [out]

A pointer to a **DWORD** value that receives the number of characters skipped to reach the beginning of the
`-----BEGIN ...-----` header.
If no header is present, then the **DWORD** is set to zero.
This parameter is optional and can be **NULL** if it is not needed.

### `pdwFlags` [out]

A pointer to a **DWORD** value that receives the flags actually used in the conversion. These are the same flags used for the *dwFlags* parameter. In many cases, these will be the same flags that were passed in the *dwFlags* parameter. If *dwFlags* contains one of the following flags, this value will receive a flag that indicates the actual format of the string. This parameter is optional and can be **NULL** if it is not needed.

| Value | Meaning |
| --- | --- |
| **CRYPT_STRING_ANY** | This variable will receive one of the following values. Each value indicates the actual format of the string.<br><br>CRYPT_STRING_BASE64HEADER<br><br>CRYPT_STRING_BASE64<br><br>CRYPT_STRING_BINARY |
| **CRYPT_STRING_BASE64_ANY** | This variable will receive one of the following values. Each value indicates the actual format of the string.<br><br>CRYPT_STRING_BASE64HEADER<br><br>CRYPT_STRING_BASE64 |
| **CRYPT_STRING_HEX_ANY** | This variable will receive one of the following values. Each value indicates the actual format of the string.<br><br>CRYPT_STRING_HEXADDR<br><br>CRYPT_STRING_HEXASCIIADDR<br><br>CRYPT_STRING_HEX<br><br>CRYPT_STRING_HEXRAW<br><br>CRYPT_STRING_HEXASCII |

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**).

## See also

[CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa)

## Remarks

The
**CRYPT_STRING_BASE64HEADER**,
**CRYPT_STRING_BASE64REQUESTHEADER**,
and
**CRYPT_STRING_BASE64X509CRLHEADER**
flags are all treated identically by this function:
They attempt to parse the first block of
base64-encoded data between lines of the form
`-----BEGIN ...-----` and `-----END ...-----`.
The `...` portions are ignored, and they need not match.
If parsing is successful, the value passed in the *dwFlags* parameter
is returned in the **DWORD** pointed to by the *pdwFlags* parameter.
Note that a value of
**CRYPT_STRING_BASE64REQUESTHEADER**
or
**CRYPT_STRING_BASE64X509CRLHEADER**
does not mean that a request header or
[X.509](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly#_SECURITY_X.509_GLY)
[certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly#_security_certificate_revocation_list_gly) (CRL)
was found.

> [!NOTE]
> The wincrypt.h header defines CryptStringToBinary as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
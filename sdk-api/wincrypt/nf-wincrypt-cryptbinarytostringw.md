# CryptBinaryToStringW function

## Description

The **CryptBinaryToString** function converts an array of bytes into a formatted string.

## Parameters

### `pbBinary` [in]

A pointer to the array of bytes to be converted into a string.

### `cbBinary` [in]

The number of elements in the *pbBinary* array.

### `dwFlags` [in]

Specifies the format of the resulting formatted string. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_STRING_BASE64HEADER**<br><br>0x00000000 | Base64, with certificate beginning and ending headers. |
| **CRYPT_STRING_BASE64**<br><br>0x00000001 | Base64, without headers. |
| **CRYPT_STRING_BINARY**<br><br>0x00000002 | Pure binary copy. |
| **CRYPT_STRING_BASE64REQUESTHEADER**<br><br>0x00000003 | Base64, with request beginning and ending headers. |
| **CRYPT_STRING_HEX**<br><br>0x00000004 | Hexadecimal only. |
| **CRYPT_STRING_HEXASCII**<br><br>0x00000005 | Hexadecimal, with [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) character display. |
| **CRYPT_STRING_BASE64X509CRLHEADER**<br><br>0x00000009 | Base64, with [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) CRL beginning and ending headers. |
| **CRYPT_STRING_HEXADDR**<br><br>0x0000000a | Hexadecimal, with address display. |
| **CRYPT_STRING_HEXASCIIADDR**<br><br>0x0000000b | Hexadecimal, with ASCII character and address display. |
| **CRYPT_STRING_HEXRAW**<br><br>0x0000000c | A raw hexadecimal string.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRYPT_STRING_BASE64URI**<br><br>0x0000000d | Base64, without headers, with "+" replaced by "-" and "/" replaced by "_" as defined in RFC 4648 Section 5. |
| **CRYPT_STRING_STRICT**<br><br>0x20000000 | Enforce strict decoding of ASN.1 text formats. Some ASN.1 binary BLOBS can have the first few bytes of the BLOB incorrectly interpreted as Base64 text. In this case, the rest of the text is ignored. Use this flag to enforce complete decoding of the BLOB.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

In addition to the values above, one or more of the following values can be specified to modify the behavior of the function.

| Value | Meaning |
| --- | --- |
| **CRYPT_STRING_NOCRLF**<br><br>0x40000000 | Do not append any new line characters to the encoded string. The default behavior is to use a carriage return/line feed (CR/LF) pair (0x0D/0x0A) to represent a new line.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **CRYPT_STRING_NOCR**<br><br>0x80000000 | Only use the line feed (LF) character (0x0A) for a new line. The default behavior is to use a CR/LF pair (0x0D/0x0A) to represent a new line. |

### `pszString` [out, optional]

A pointer to a buffer that receives the converted string. To calculate the number of characters that must be allocated to hold the returned string, set this parameter to **NULL**. The function will place the required number of characters, including the terminating **NULL** character, in the value pointed to by *pcchString*.

### `pcchString` [in, out]

A pointer to a **DWORD** variable that contains the size, in **TCHAR**s, of the *pszString* buffer. If *pszString* is **NULL**, the function calculates the length of the return string (including the terminating null character) in **TCHAR**s and returns it in this parameter. If *pszString* is not **NULL** and big enough, the function converts the binary data into a specified string format including the terminating null character, but *pcchString* receives the length in **TCHAR**s, not including the terminating null character.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## Remarks

With the exception of when **CRYPT_STRING_BINARY** encoding is used, all strings are appended with a new line sequence. By default, the new line sequence is a CR/LF pair (0x0D/0x0A). If the *dwFlags* parameter contains the **CRYPT_STRING_NOCR** flag, then the new line sequence is a LF character (0x0A). If the *dwFlags* parameter contains the **CRYPT_STRING_NOCRLF** flag, then no new line sequence is appended to the string.

> [!NOTE]
> The wincrypt.h header defines CryptBinaryToString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya)
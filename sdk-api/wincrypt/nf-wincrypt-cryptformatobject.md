# CryptFormatObject function

## Description

The **CryptFormatObject** function formats the encoded data and returns a Unicode string in the allocated buffer according to the certificate encoding type.

## Parameters

### `dwCertEncodingType` [in]

Type of encoding used on the certificate. The currently defined certificate encoding type used is X509_ASN_ENCODING.

### `dwFormatType` [in]

Format type values. Not used. Set to zero.

### `dwFormatStrType` [in]

Structure format type values. This parameter can be zero, or you can specify one or more of the following flags by using the bitwise-**OR** operator to combine them.

| Value | Meaning |
| --- | --- |
| **0** | Display the data in a single line. Each subfield is concatenated with a comma (,). For more information, see Remarks. |
| **CRYPT_FORMAT_STR_MULTI_LINE**<br><br>0x0001 | Display the data in multiple lines rather than single line (the default). For more information, see Remarks. |
| **CRYPT_FORMAT_STR_NO_HEX**<br><br>0x0010 | Disables the hexadecimal dump. For more information, see Remarks. |

### `pFormatStruct` [in]

A pointer to the format of the structure. Not used. Set to **NULL**.

### `lpszStructType` [in]

A pointer to an OID that defines the encoded data. If the high-order word of the *lpszStructType* parameter is zero, the low-order word specifies the integer identifier for the type of the given structure. Otherwise, this parameter is a long pointer to a **null**-terminated string.

The following table lists supported OIDs with their associated OID extension.

| Value | Meaning |
| --- | --- |
| **SPC_FINANCIAL_CRITERIA_OBJID** | 1.3.6.1.4.1.311.2.1.27 |
| **SPC_SP_AGENCY_INFO_OBJID** | 1.3.6.1.4.1.311.2.1.10 |
| **szOID_AUTHORITY_INFO_ACCESS** | 1.3.6.1.5.5.7.1.1 |
| **szOID_AUTHORITY_KEY_IDENTIFIER2** | 2.5.29.35 |
| **szOID_BASIC_CONSTRAINTS2** | 2.5.29.19 |
| **szOID_CERT_POLICIES** | 2.5.29.32 |
| **szOID_CRL_DIST_POINTS** | 2.5.29.31 |
| **szOID_CRL_REASON_CODE** | 2.5.29.21 |
| **szOID_ENHANCED_KEY_USAGE** | 2.5.29.37 |
| **szOID_ISSUER_ALT_NAME2** | 2.5.29.18 |
| **szOID_KEY_ATTRIBUTES** | 2.5.29.2 |
| **szOID_KEY_USAGE** | 2.5.29.15 |
| **szOID_KEY_USAGE_RESTRICTION** | 2.5.29.4 |
| **szOID_NEXT_UPDATE_LOCATION** | 1.3.6.1.4.1.311.10.2 |
| **szOID_RSA_SMIMECapabilities** | 1.2.840.113549.1.9.15 |
| **szOID_SUBJECT_ALT_NAME2** | 2.5.29.17 |
| **szOID_SUBJECT_KEY_IDENTIFIER** | 2.5.29.14 |

### `pbEncoded` [in]

A pointer to the encoded data to be formatted. If *lpszStructType* is one of the OIDs listed above, the *pbEncoded* is the encoded extension.

### `cbEncoded` [in]

The size, in bytes, of the *pbEncoded* structure.

### `pbFormat` [out]

A pointer to a buffer that receives the formatted string. When the buffer that is specified is not large enough to receive the decoded structure, the function sets ERROR_MORE_DATA and stores the required buffer size, in bytes, into the variable pointed to by *pcbFormat*. This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see [Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbFormat` [in, out]

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by the *pbFormat* parameter. When the function returns, the variable pointed to by the *pcbFormat* parameter contains the number of bytes stored in the buffer. This parameter can be **NULL**, only if *pbFormat* is **NULL**.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size may be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit into the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is **TRUE**. If it does not succeed, the return value is **FALSE**. To retrieve extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The default behavior of this function is to return a single-line display of the encoded data, that is, each subfield is concatenated with a comma (,) on one line. If you prefer to display the data in multiple lines, set the CRYPT_FORMAT_STR_MULTI_LINE flag. Each subfield will then be displayed on a separate line.

If there is no formatting routine installed or registered for the *lpszStructType* parameter, the hexadecimal dump of the encoded
[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) will be returned. A user can set the CRYPT_FORMAT_STR_NO_HEX flag to disable the hexadecimal dump.

## See also

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))
# INTERNET_CERTIFICATE_INFO structure

## Description

Contains certificate information returned from the server. This structure is used by the
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) function.

## Members

### `ftExpiry`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date the certificate expires.

### `ftStart`

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date the certificate becomes valid.

### `lpszSubjectInfo`

Pointer to a buffer that contains the name of the organization, site, and server for which the certificate was issued. The application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the resources allocated for this parameter.

### `lpszIssuerInfo`

Pointer to a buffer that contains the name of the organization, site, and server that issued the certificate. The application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the resources allocated for this parameter.

### `lpszProtocolName`

Pointer to a buffer that contains the name of the protocol used to provide the secure connection. The application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the resources allocated for this parameter.

### `lpszSignatureAlgName`

Pointer to a buffer that contains the name of the algorithm used for signing the certificate. The application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the resources allocated for this parameter.

### `lpszEncryptionAlgName`

Pointer to a buffer that contains the name of the algorithm used for doing encryption over the secure channel (SSL/PCT) connection. The application must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the resources allocated for this parameter.

### `dwKeySize`

Size, in **TCHAR**s, of the key.

## Remarks

Despite what the header indicates, the implementation of **INTERNET_CERTIFICATE_INFO** is not Unicode-aware. All of the string members are filled as ANSI strings regardless of whether Unicode is enabled. Consequently, when reading these values, the caller must cast them to LPSTR if Unicode is enabled.

Applications requesting this information must free pointers that are allocated and placed in the returned structure.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)
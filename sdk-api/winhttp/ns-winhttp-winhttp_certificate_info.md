## Description

The **WINHTTP_CERTIFICATE_INFO** structure contains certificate information returned from the server. This structure is used by the
[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) function.

## Members

### `ftExpiry`

A
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date the certificate expires.

### `ftStart`

A
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date the certificate becomes valid.

### `lpszSubjectInfo`

A pointer to a buffer that contains the name of the organization, site, and server for which the certificate was issued.

### `lpszIssuerInfo`

A pointer to a buffer that contains the name of the organization, site, and server that issued the certificate.

### `lpszProtocolName`

A pointer to a buffer that contains the name of the protocol used to provide the secure connection. This member is not current used.

### `lpszSignatureAlgName`

A pointer to a buffer that contains the name of the algorithm used to sign the certificate. This member is not current used.

### `lpszEncryptionAlgName`

A pointer to a buffer that contains the name of the algorithm used to perform encryption over the secure channel (SSL/TLS) connection. This member is not current used.

### `dwKeySize`

The size, in bytes, of the key.

## Remarks

The **WINHTTP_CERTIFICATE_INFO** structure contains information on the certificate returned by the server when the connection uses SSL/TLS. The [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) function returns the **WINHTTP_CERTIFICATE_INFO** structure when the *dwOption* parameter passed to the **WinHttpQueryOption** function is set to **WINHTTP_OPTION_SECURITY_CERTIFICATE_STRUCT**. For more information, see [Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags).

The [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) function does not set the **lpszProtocolName**, **lpszSignatureAlgName**, and **lpszEncryptionAlgName** members of the **WINHTTP_CERTIFICATE_INFO** structure, so these member are always returned as **NULL**.

Once the application no longer needs the returned **WINHTTP_CERTIFICATE_INFO** structure, the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function should be called to free any pointers returned in the structure. The structure members containing pointers that are not NULL and need to be freed are **lpszSubjectInfo** and **lpszIssuerInfo**.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the [Windows HTTP Services](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) start page.

## See also

[Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags)

[WinHTTP
Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)
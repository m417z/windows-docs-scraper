# URL_COMPONENTSW structure

## Description

Contains the constituent parts of a URL. This structure is used with the
[InternetCrackUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcrackurla) and
[InternetCreateUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcreateurla) functions.

## Members

### `dwStructSize`

Size of this structure, in bytes.

### `lpszScheme`

Pointer to a string that contains the scheme name.

### `dwSchemeLength`

Size of the scheme name, in **TCHARs**.

### `nScheme`

[INTERNET_SCHEME](https://learn.microsoft.com/windows/desktop/api/wininet/ne-wininet-internet_scheme) value that indicates the Internet protocol scheme.

### `lpszHostName`

Pointer to a string that contains the host name.

### `dwHostNameLength`

Size of the host name, in **TCHARs**.

### `nPort`

Converted port number.

### `lpszUserName`

Pointer to a string value that contains the user name.

### `dwUserNameLength`

Size of the user name, in **TCHARs**.

### `lpszPassword`

Pointer to a string that contains the password.

### `dwPasswordLength`

Size of the password, in **TCHARs**.

### `lpszUrlPath`

Pointer to a string that contains the URL path.

### `dwUrlPathLength`

Size of the URL path, in **TCHARs**.

### `lpszExtraInfo`

Pointer to a string that contains the extra information (for example, ?something or #something).

### `dwExtraInfoLength`

Size of the extra information, in **TCHARs**.

## Remarks

For
[InternetCrackUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcrackurla), if a pointer member and its corresponding length member are both zero, that component is not returned. If the pointer member is **NULL** but the length member is not zero, both the pointer and length members are returned. If both pointer and corresponding length members are nonzero, the pointer member points to a buffer where the component is copied. The component can be un-escaped, depending on the
*dwFlags* parameter of
[InternetCrackUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcrackurla).

For
[InternetCreateUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcreateurla), the pointer members should be **NULL** if the component is not required. If the corresponding length member is zero, the pointer member is the address of a zero-terminated string. If the length member is not zero, it is the string length of the corresponding pointer member.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines URL_COMPONENTS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[InternetCrackUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcrackurla)

[InternetCreateUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcreateurla)
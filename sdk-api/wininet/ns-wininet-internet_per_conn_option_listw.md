# INTERNET_PER_CONN_OPTION_LISTW structure

## Description

Contains the list of options for a particular Internet connection.

## Members

### `dwSize`

Size of the
structure, in bytes.

### `pszConnection`

Pointer to a string that contains the name of the RAS connection or **NULL**, which indicates the default or LAN connection, to set or query options on.

### `dwOptionCount`

Number of options to query or set.

### `dwOptionError`

Options that failed, if an error occurs.

### `pOptions`

Pointer to an array of
[INTERNET_PER_CONN_OPTION](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_per_conn_optiona) structures containing the options to query or set.

## Remarks

In Microsoft Internet Explorer 5, only the ANSI versions of
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) and
[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona) will work with the
**INTERNET_PER_CONN_OPTION_LIST** structure. The Unicode versions will support using the
**INTERNET_PER_CONN_OPTION_LIST** structure in later versions of Internet Explorer.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines INTERNET_PER_CONN_OPTION_LIST as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INTERNET_PER_CONN_OPTION](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_per_conn_optiona)

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)
# INTERNET_BUFFERSA structure

## Description

Contains both the data and header information.

## Members

### `dwStructSize`

Size of the
structure, in bytes.

### `Next`

Pointer to the next
**INTERNET_BUFFERS** structure.

### `lpcszHeader`

Pointer to a string value that contains the headers. This member can be **NULL**.

### `dwHeadersLength`

Size of the headers, in **TCHARs**, if
**lpcszHeader** is not **NULL**.

### `dwHeadersTotal`

Size of the headers, if there is not enough memory in the buffer.

### `lpvBuffer`

Pointer to the data buffer.

### `dwBufferLength`

Size of the buffer, in bytes, if
**lpvBuffer** is not **NULL**.

### `dwBufferTotal`

Total size of the resource, in bytes.

### `dwOffsetLow`

Reserved; do not use.

### `dwOffsetHigh`

Reserved; do not use.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines INTERNET_BUFFERS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa)

[InternetReadFileEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfileexa)
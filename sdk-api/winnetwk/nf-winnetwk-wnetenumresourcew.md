# WNetEnumResourceW function

## Description

The
**WNetEnumResource** function continues an enumeration of network resources that was started by a call to the
[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma) function.

## Parameters

### `hEnum` [in]

Handle that identifies an enumeration instance. This handle must be returned by the
[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma) function.

### `lpcCount` [in, out]

Pointer to a variable specifying the number of entries requested. If the number requested is –1, the function returns as many entries as possible.

If the function succeeds, on return the variable pointed to by this parameter contains the number of entries actually read.

### `lpBuffer` [out]

Pointer to the buffer that receives the enumeration results. The results are returned as an array of [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structures. Note that the buffer you allocate must be large enough to hold the structures, plus the strings to which their members point. For more information, see the following Remarks section.

The buffer is valid until the next call using the handle specified by the *hEnum* parameter. The order of
**NETRESOURCE** structures in the array is not predictable.

### `lpBufferSize` [in, out]

Pointer to a variable that specifies the size of the *lpBuffer* parameter, in bytes. If the buffer is too small to receive even one entry, this parameter receives the required size of the buffer.

## Return value

If the function succeeds, the return value is one of the following values.

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The enumeration succeeded, and the buffer contains the requested data. The calling application can continue to call **WNetEnumResource** to complete the enumeration. |
| **ERROR_NO_MORE_ITEMS** | There are no more entries. The buffer contents are undefined. |

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | More entries are available with subsequent calls. For more information, see the following Remarks section. |
| **ERROR_INVALID_HANDLE** | The handle specified by the *hEnum* parameter is not valid. |
| **ERROR_NO_NETWORK** | The network is unavailable. (This condition is tested before *hEnum* is tested for validity.) |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |

## Remarks

The
**WNetEnumResource** function does not enumerate users connected to a share; you can call the
[NetConnectionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netconnectionenum) function to accomplish this task. To enumerate hidden shares, call the
[NetShareEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareenum) function.

An application cannot set the *lpBuffer* parameter to **NULL** and retrieve the required buffer size from the *lpBufferSize* parameter. Instead, the application should allocate a buffer of a reasonable size—16 kilobytes is typical—and use the value of *lpBufferSize* for error detection.

#### Examples

For a code sample that illustrates an application-defined function that enumerates all the resources on a network, see
[Enumerating Network Resources](https://learn.microsoft.com/windows/desktop/WNet/enumerating-network-resources).

> [!NOTE]
> The winnetwk.h header defines WNetEnumResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew)

[WNetCloseEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcloseenum)

[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)
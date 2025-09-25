# WNetGetProviderNameA function

## Description

The
**WNetGetProviderName** function obtains the provider name for a specific type of network.

## Parameters

### `dwNetType` [in]

Network type that is unique to the network. If two networks claim the same type, the function returns the name of the provider loaded first. Only the high word of the network type is used. If a network reports a subtype in the low word, it is ignored.

You can find a complete list of network types in the header file Winnetwk.h.

### `lpProviderName` [out]

Pointer to a buffer that receives the network provider name.

### `lpBufferSize` [in, out]

Size of the buffer passed to the function, in characters. If the return value is ERROR_MORE_DATA, *lpBufferSize* returns the buffer size required (in characters) to hold the provider name.

**Windows Me/98/95:** The size of the buffer is in bytes, not characters. Also, the buffer must be at least 1 byte long.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The buffer is too small to hold the network provider name. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_INVALID_ADDRESS** | The *lpProviderName* parameter or the *lpBufferSize* parameter is invalid. |

## See also

[WNetGetNetworkInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetnetworkinformationa)

[WNetGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetresourceinformationa)

[WNetGetUniversalName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetuniversalnamea)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

## Remarks

> [!NOTE]
> The winnetwk.h header defines WNetGetProviderName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
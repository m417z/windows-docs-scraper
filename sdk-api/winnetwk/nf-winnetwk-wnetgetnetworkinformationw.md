# WNetGetNetworkInformationW function

## Description

The
**WNetGetNetworkInformation** function returns extended information about a specific network provider whose name was returned by a previous network enumeration.

## Parameters

### `lpProvider` [in]

Pointer to a constant null-terminated string that contains the name of the network provider for which information is required.

### `lpNetInfoStruct` [out]

Pointer to a
[NETINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netinfostruct) structure. The structure describes characteristics of the network.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PROVIDER** | The *lpProvider* parameter does not match any running network provider. |
| **ERROR_BAD_VALUE** | The **cbStructure** member of the **NETINFOSTRUCT** structure does not contain a valid structure size. |

## See also

[NETINFOSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netinfostruct)

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew)

[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea)

[WNetGetProviderName](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetprovidernamea)

[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

## Remarks

> [!NOTE]
> The winnetwk.h header defines WNetGetNetworkInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
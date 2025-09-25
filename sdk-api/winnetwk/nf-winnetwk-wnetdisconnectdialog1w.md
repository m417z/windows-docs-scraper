# WNetDisconnectDialog1W function

## Description

The
**WNetDisconnectDialog1** function attempts to disconnect a network resource. If the underlying network returns ERROR_OPEN_FILES, the function prompts the user for confirmation. If there is any error, the function informs the user. The function requires a
[DISCDLGSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-discdlgstructa) to specify the parameters for the disconnect attempt.

## Parameters

### `lpConnDlgStruct` [in]

Pointer to a
**DISCDLGSTRUCT** structure. The structure specifies the behavior for the disconnect attempt.

## Return value

If the function succeeds, the return value is NO_ERROR. If the user cancels the dialog box, the return value is –1.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | When the system prompted the user for a decision about disconnecting, the user elected not to disconnect. |
| **ERROR_OPEN_FILES** | Unable to disconnect because the user is actively using the connection. |
| **ERROR_BUSY** | The network provider is busy (possibly initializing). The caller should retry. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is insufficient memory to start the dialog box. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function to obtain a description of the error. |

## See also

[DISCDLGSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-discdlgstructa)

[WNetConnectionDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog)

[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a)

[WNetDisconnectDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetdisconnectdialog)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

## Remarks

> [!NOTE]
> The winnetwk.h header defines WNetDisconnectDialog1 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
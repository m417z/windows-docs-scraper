# WNetConnectionDialog1A function

## Description

The
**WNetConnectionDialog1** function brings up a general browsing dialog for connecting to network resources. The function requires a
[CONNECTDLGSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-connectdlgstructa) to establish the dialog box parameters.

## Parameters

### `lpConnDlgStruct` [in, out]

Pointer to a
**CONNECTDLGSTRUCT** structure. The structure establishes the browsing dialog parameters.

## Return value

If the user cancels the dialog box, the function returns –1. If the function is successful, it returns NO_ERROR. Also, if the call is successful, the **dwDevNum** member of the
**CONNECTDLGSTRUCT** structure contains the number of the connected device.

Typically this dialog returns an error only if the user cannot enter a dialog session. This is because errors that occur after a dialog session are reported to the user directly. If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Both the CONNDLG_RO_PATH and the CONNDLG_USE_MRU dialog box options are set. (Dialog box options are specified by the **dwFlags** member of the [CONNECTDLGSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-connectdlgstructa) structure.) <br><br>-or-<br><br>Both the CONNDLG_PERSIST and the CONNDLG_NOT_PERSIST dialog box options are set.<br><br>-or-<br><br>The CONNDLG_RO_PATH dialog box option is set and the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure does not point to a remote network. (The **CONNECTDLGSTRUCT** structure points to a **NETRESOURCE** structure.) |
| **ERROR_BAD_DEV_TYPE** | The **dwType** member of the **NETRESOURCE** structure is not set to RESOURCETYPE_DISK. |
| **ERROR_BUSY** | The network provider is busy (possibly initializing). The caller should retry. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is insufficient memory to display the dialog box. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Call [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) to obtain a description of the error. |

## See also

[CONNECTDLGSTRUCT](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-connectdlgstructa)

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea)

[WNetConnectionDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog)

[WNetDisconnectDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetdisconnectdialog)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

## Remarks

> [!NOTE]
> The winnetwk.h header defines WNetConnectionDialog1 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
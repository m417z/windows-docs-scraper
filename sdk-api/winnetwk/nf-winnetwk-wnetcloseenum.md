# WNetCloseEnum function

## Description

The
**WNetCloseEnum** function ends a network resource enumeration started by a call to the
[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma) function.

## Parameters

### `hEnum` [in]

Handle that identifies an enumeration instance. This handle must be returned by the
**WNetOpenEnum** function.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_NO_NETWORK** | The network is unavailable. (This condition is tested before the handle specified in the *hEnum* parameter is tested for validity.) |
| **ERROR_INVALID_HANDLE** | The *hEnum* parameter does not specify a valid handle. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |

## See also

[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea)

[WNetOpenEnum](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetopenenuma)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)
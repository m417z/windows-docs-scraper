# IMultisessionSequential::get_LastWrittenAddressOfPreviousSession

## Description

Retrieves the last sector written in the previous session on the media.

## Parameters

### `value`

Sector number that identifies the last sector written in the previous write session.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## See also

[IMultisessionSequential](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisessionsequential)
# ISyncSessionState::GetForgottenKnowledgeRecoveryRangeEnd

## Description

Gets the upper bound of the recovery range when the session is performing forgotten knowledge recovery.

## Parameters

### `pbRangeEnd` [in, out]

Returns the upper bound of the recovery range when the session is performing forgotten knowledge recovery.

### `pcbRangeEnd` [in, out]

Specifies the number of bytes in *pbRangeEnd*. Returns the number of bytes required to retrieve the range value when *pcbRangeEnd* is too small, or the number of bytes written.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pcbRangeEnd* is too small. In this case, the required number of bytes is returned in *pcbRangeEnd*. |

## See also

[ISyncSessionState Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncsessionstate)
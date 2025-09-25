# ITMultiTrackTerminal::RemoveTrackTerminal

## Description

The
**RemoveTrackTerminal** method removes the specified terminal from the collection of track terminals that belong to the multitrack terminal on which the method was called. If the track terminal has been selected on a stream, it should be unselected first.

## Parameters

### `pTrackTerminalToRemove` [in]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface of the terminal to remove.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTrackTerminalToRemove* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The primary use of the
**RemoveTrackTerminal** method is cleanup during the terminal selection process. For example, if a track has been created, but it has not been selected on a stream, this method can be used to remove the track.

The actual action performed by this method may vary in the actual implementation of the terminal. For instance, calling this method on a File Recording Terminal causes the corresponding file data stream to be removed from the file. Calling this method on a File Playback Terminal fails because its set of terminals is determined solely by file configuration and cannot be changed by the caller.

## See also

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)
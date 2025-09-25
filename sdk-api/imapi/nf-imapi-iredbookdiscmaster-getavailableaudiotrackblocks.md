# IRedbookDiscMaster::GetAvailableAudioTrackBlocks

## Description

Retrieves the current number of blocks that can be added to the track before an additional add will cause a failure for lack of space.

## Parameters

### `pnBlocks` [out]

Number of audio blocks that can be added to the open track before it must be closed.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

This method accounts for gaps associated with open tracks. Additionally, if this method is called when there is no open track, it returns the maximum number of audio blocks that could be added if a new track is created (accounting for gaps, and so on).

## See also

[IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)
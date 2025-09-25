# IRedbookDiscMaster::GetTotalAudioBlocks

## Description

Retrieves the total number of blocks available for staging audio tracks. The total includes all block types, including blocks that may need to be allocated for track gaps.

## Parameters

### `pnBlocks` [out]

Total number of audio blocks available on a disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)
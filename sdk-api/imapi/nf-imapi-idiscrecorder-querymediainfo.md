# IDiscRecorder::QueryMediaInfo

## Description

Retrieves information about the currently mounted media, such as the total number of blocks used on the media.

## Parameters

### `pbSessions` [out]

Number of sessions on the disc.

### `pbLastTrack` [out]

Track number of the last track of the previous session.

### `ulStartAddress` [out]

Start address of the last track of the previous session.

### `ulNextWritable` [out]

Address at which writing is to begin.

### `ulFreeBlocks` [out]

Number of blocks available for writing.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Using this method allows the calculation of parameters such as the amount of free space left on the disc without using a setting on the active disc recorder, which causes an exclusive open. The total size of the disc can be calculated by summing the next writable address and free blocks.

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)
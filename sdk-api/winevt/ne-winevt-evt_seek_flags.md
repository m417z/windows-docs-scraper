# EVT_SEEK_FLAGS enumeration

## Description

Defines the relative position in the result set from which to seek.

## Constants

### `EvtSeekRelativeToFirst:1`

Seek to the specified offset from the first entry in the result set. The offset must be a positive value.

### `EvtSeekRelativeToLast:2`

Seek to the specified offset from the last entry in the result set. The offset must be a negative value.

### `EvtSeekRelativeToCurrent:3`

Seek to the specified offset from the current entry in the result set. The offset can be a positive or negative value.

### `EvtSeekRelativeToBookmark:4`

Seek to the specified offset from the bookmarked entry in the result set. The offset can be a positive or negative value.

### `EvtSeekOriginMask:7`

A bitmask that you can use to determine which of the following flags is set:

* EvtSeekRelativeToFirst
* EvtSeekRelativeToLast
* EvtSeekRelativeToBookmark

### `EvtSeekStrict:0x10000`

Force the function to fail if the event does not exist.

## Remarks

If the offset or bookmark seeks past the boundary of the result set (past the first or last record), and EvtSeekStrict is not set, seek will return the last record within the boundary.

If the bookmark is within the boundaries of the result set (based on event record ID) but is not included in the result set, the seek function will apply the offset relative to the bookmark's record ID. In the following table, the first column shows the record IDs of the events in the result set. If the bookmark's record ID is 3989, the second column shows the record that the seek function would seek to given the specified offset.

| Record ID | Offset |
| --- | --- |
| 3995 | –2 |
| 3991 | –1 |
| 3987 | 0, 1 |
| 3983 | 2 |
| 3979 | 3 |
| 3975 | 4 |
| 3971 | 5 |
| 3968 | 6 |
| 3959 | 7 |
| 3955 | 8 |

## See also

[EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek)
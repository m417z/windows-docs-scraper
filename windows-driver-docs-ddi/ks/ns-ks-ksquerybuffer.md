## Description

The **KSQUERYBUFFER** structure is used when querying for outstanding buffers available on an event with **KSEVENT_TYPE_QUERYBUFFER**.

## Members

### `Event`

Specifies the description of the original event, with the **KSEVENT_TYPE_QUERYBUFFER** flag set instead of the **KSEVENT_TYPE_ENABLEBUFFERED** flag.

### `EventData`

A pointer to a [**KSEVENTDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure. This is the same pointer supplied to [AVStrMiniAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksaddevent) at event enable time. This pointer is used as the unique identifier in locating the event, just as it is used when disabling the event.

### `Reserved`

Not used, and set to zero.

## Remarks

If **KSEVENT_TYPE_ENABLEBUFFERED** was used to enable an event that also buffers data, then the data produced by the event can be queried using this method. The description of the event being queried is provided as the first parameter, and any buffer is provided as the second parameter to the query.

The buffer length needed can be queried by providing a zero length output buffer. The size of buffer is returned in the **BytesReturned** parameter, with a warning status of **STATUS_BUFFER_OVERFLOW**.

Alternatively, the query returns one of the following status values:

| Return Value | Description |
|---|---|
| STATUS_NOT_FOUND | event was not found |
| STATUS_INVALID_PARAMETER | it was not being buffered |
| STATUS_NO_MORE_ENTRIES | no buffers were available |
| STATUS_BUFFER_TOO_SMALL | buffer size was insufficient. |
| STATUS_SUCCESS | life is good. |

## See also

[**KSBUFFER_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksbuffer_item)

[**KSEVENT**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)
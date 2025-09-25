## Description

The KsStreamPointerScheduleTimeout function registers a timeout callback with AVStream for the given stream pointer.

## Parameters

### `StreamPointer` [in]

A pointer to a [**KSSTREAM_POINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure representing the stream pointer for which to register a timeout.

### `Callback` [in]

A pointer to a minidriver-supplied [AVStrMiniTimeoutCallback](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556362(v=vs.85)) routine. If the stream pointer has not been deleted or the timeout canceled before the interval expires, AVStream calls this routine immediately following expiration of the interval.

### `Interval` [in]

Specifies the interval in 100-nanosecond units from the current time to the time that the timeout occurs.

## Remarks

It is safe to call KsStreamPointerScheduleTimeout on a stream pointer that already has a timeout scheduled. In this case, AVStream cancels the previous timeout and replaces it with the new timeout.

If you call KsStreamPointerScheduleTimeout while the pin associated with the [**KSSTREAM_POINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) is still in the pause state, the scheduled timeout may not fire unless another timeout is scheduled later in the run state. At that point, it is possible for all the timeouts that were scheduled during pause to become active and fire immediately in a chain. Also see [Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/stream-pointers).

## See also

[**KSSTREAM_POINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

[KsStreamPointerCancelTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointercanceltimeout)

[KsStreamPointerDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerdelete)
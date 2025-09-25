# KsPinGetAvailableByteCount function

## Description

The **KsPinGetAvailableByteCount** routine outputs the number of bytes of input data ahead of the leading edge and the number of bytes of output buffer ahead of the leading edge, both for the queue of a caller-specified pin.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to calculate these queue parameters.

### `InputDataBytes` [out, optional]

A pointer to a LONG value in which the routine returns the number of input data bytes ahead of the leading edge. Caller sets to **NULL** if this value is not requested.

### `OutputBufferBytes` [out, optional]

A pointer to a LONG value in which the routine returns the number of output buffer bytes ahead of the leading edge. Caller sets to **NULL** if this value is not requested.

## Return value

Returns STATUS_SUCCESS if the requested count(s) have been retrieved. An unsuccessful return status indicates that *Pin* does not have an associated queue.

## Remarks

Noninplace pins should use *InputDataBytes* for input pins and *OutputBufferBytes* for output pins.

The results of this call are not guaranteed to be safe unless either the processing mutex is held at call-time, or the caller has privately synchronized before calling the routine. To private synchronize, ensure that the pin does not transition from Acquire to Stop while the routine is executing. See [Processing Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/processing-mutex-in-avstream).

Also note that in-place transform can supply input and output counts.

In Windows XP and DirectX 8.0, the *InputDataBytes* count is not valid unless frames that the filter receives are full.

For additional information, see [Leading and Trailing Edge Stream Pointers](https://learn.microsoft.com/windows-hardware/drivers/stream/leading-and-trailing-edge-stream-pointers).

## See also

[AVStrMiniPinProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspin)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)

[KsFilterAcquireProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquireprocessingmutex)

[KsFilterReleaseProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterreleaseprocessingmutex)

[KsPinAcquireProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinacquireprocessingmutex)

[KsPinGetLeadingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetleadingedgestreampointer)

[KsPinGetTrailingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingettrailingedgestreampointer)

[KsPinReleaseProcessingMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinreleaseprocessingmutex)
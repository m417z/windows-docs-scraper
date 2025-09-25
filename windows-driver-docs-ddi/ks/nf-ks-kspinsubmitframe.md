## Description

If a pin has been placed into injection mode by a call to [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback), the **KsPinSubmitFrame** function submits a frame directly into the transport circuit.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure on which to submit a frame.

### `Data` [in, optional]

A pointer to a frame buffer. This should be **NULL** if and only if *Size* is equal to 0. Optional.

### `Size` [in, optional]

The size in bytes of the frame buffer to which the *Data* field points. If the *Data* field is **NULL**, set this parameter to zero. Optional.

### `StreamHeader` [in, optional]

A pointer to a [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure. The stream header is copied if this parameter is supplied. Optional.

### `Context` [in, optional]

A pointer to a caller-allocated buffer. AVStream provides this pointer to the frame return callback registered through a call to [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback). Optional.

## Return value

Returns STATUS_SUCCESS if frame submission is successful. Otherwise returns an appropriate error code.

## See also

[KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback)

[KsPinSubmitFrameMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframemdl)
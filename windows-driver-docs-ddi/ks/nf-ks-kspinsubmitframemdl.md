# KsPinSubmitFrameMdl function

## Description

If a pin has been placed into injection mode by a call to [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback), the **KsPinSubmitFrameMdl** function submits a frame directly into the transport circuit.

## Parameters

### `Pin` [in]

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the pin on which to submit a frame.

### `Mdl` [in, optional]

A pointer to a memory descriptor list describing the frame buffer. Optional.

### `StreamHeader` [in, optional]

A pointer to a [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure. The stream header is copied if this parameter is supplied. Optional.

### `Context` [in, optional]

A pointer to a caller-allocated buffer that is passed to the frame return callback registered through [KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback). This parameter is optional and is solely for the caller's use.

## Return value

Returns STATUS_SUCCESS if frame submission is successful. Otherwise returns an appropriate error code.

## Remarks

The difference between this function and [KsPinSubmitFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframe) is that this function will submit a frame using an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure rather than a data and size argument.

## See also

[KsPinRegisterFrameReturnCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterframereturncallback)

[KsPinSubmitFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframe)
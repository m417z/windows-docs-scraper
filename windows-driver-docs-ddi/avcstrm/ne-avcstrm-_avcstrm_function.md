# _AVCSTRM_FUNCTION enumeration

## Description

The AVCSTRM_FUNCTION enumeration defines the functionality exposed by the *avcstrm.sys* driver.

## Constants

### `AVCSTRM_READ`

Read data from a stream.

### `AVCSTRM_WRITE`

Write data to a stream.

### `AVCSTRM_ABORT_STREAMING`

Abort streaming. This cancels *all* streaming IRPs. To cancel an individual IRP, use [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp).

### `AVCSTRM_OPEN`

Open a stream in a specific format.

### `AVCSTRM_CLOSE`

Close a stream and free any resources allocated for the stream.

### `AVCSTRM_GET_STATE`

Obtain the stream state.

### `AVCSTRM_SET_STATE`

Place the stream into a new state.

### `AVCSTRM_GET_PROPERTY`

Get stream property. This function is not implemented.

### `AVCSTRM_SET_PROPERTY`

Set stream property. This function is not implemented.

## See also

[AVCSTRM_ABORT_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-abort-streaming)

[AVCSTRM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-close)

[AVCSTRM_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-property)

[AVCSTRM_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-state)

[AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open)

[AVCSTRM_READ](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-read)

[AVCSTRM_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-property)

[AVCSTRM_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-state)

[AVCSTRM_WRITE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-write)
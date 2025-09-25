# IAudioClient2::GetBufferSizeLimits

## Description

The **GetBufferSizeLimits** method returns the buffer size limits of the hardware audio engine in 100-nanosecond units.

## Parameters

### `pFormat` [in]

A pointer to the target format that is being queried for the buffer size limit.

### `bEventDriven` [in]

Boolean value to indicate whether or not the stream can be event-driven.

### `phnsMinBufferDuration` [out]

Returns a pointer to the minimum buffer size (in 100-nanosecond units) that is
required for the underlying hardware audio engine to operate at the format specified in the *pFormat* parameter, without frequent audio glitching.

### `phnsMaxBufferDuration` [out]

Returns a pointer to the maximum buffer size (in 100-nanosecond units) that the underlying hardware
audio engine can support for the format specified in the *pFormat* parameter.

## Return value

The **GetBufferSizeLimits** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code. For example, it can return **AUDCLNT_E_DEVICE_INVALIDATED**, if the device was removed and the method is called.

## Remarks

The **GetBufferSizeLimits** method is a device-facing method
and does not require prior audio stream initialization.

## See also

[IAudioClient2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient2)
# IMiniportMidiStream::Write

## Description

The `Write` method writes data to an outgoing MIDI stream.

## Parameters

### `BufferAddress` [in]

Pointer to a caller-allocated buffer that contains the outgoing MIDI data

### `BytesToWrite` [in]

Specifies the number of bytes of MIDI data contained in the buffer that *BufferAddress* points to.

### `BytesWritten` [out]

Output pointer to a caller-allocated variable into which the method writes a count specifying the actual number of bytes that the method succeeded in writing to the MIDI output device. For more information, see the following Remarks section.

## Return value

`Write` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_IO_DEVICE_ERROR** | The call failed due to a device error. |
| **STATUS_INVALID_DEVICE_REQUEST** | Invalid device request (for example, calling `Write` on a MIDI input stream). |

## Remarks

If the method succeeds, it outputs one of the following values to the caller through the *BytesWritten* parameter:

* The same value as *BytesToWrite*. This value indicates that the method succeeded in writing all *BytesToWrite* bytes of data to the device.
* A multiple of four that is less than *BytesToWrite*. If the method is able to write some but not all of the caller's data to the device, it should write a number of bytes that is a multiple of four. This value indicates that the caller should make another call to the method to write the remaining data.
* Zero. This value indicates that the device is too busy to write any of the caller's data during the current call, but that the caller should try again later. The miniport driver is responsible for distinguishing a busy device from a device error. The method should avoid generating an endless succession of calls that always return success but write zero bytes.

## See also

[IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream)

[IMiniportMidiStream::Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidistream-read)
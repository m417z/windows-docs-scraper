# IMiniportMidiStream::Read

## Description

The `Read` method reads data from an incoming MIDI stream.

## Parameters

### `BufferAddress` [in]

Specifies the address of a caller-allocated buffer. The method copies the incoming MIDI data from the device to the buffer. The allocated size of this buffer must be greater than or equal to *BufferLength*.

### `BufferLength` [in]

Specifies the length in bytes of the buffer pointed to by *BufferAddress*.

### `BytesRead` [out]

Output pointer to a caller-allocated variable into which the method writes a count specifying the actual number of bytes successfully read from the device into the buffer.

## Return value

`Read` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | Invalid device request (for example, calling `Read` on a MIDI output stream). |

## Remarks

The miniport driver calls [IPortMidi::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportmidi-notify) to notify the port driver when incoming MIDI data becomes available from the capture device. The port driver calls **IMiniportMidi::Read** to retrieve the data. The port driver continues to call `Read` as long as more data is available.

The `Read` method returns STATUS_SUCCESS and a *BytesRead* count of zero to indicate that no more MIDI input data is currently available from the device.

## See also

[IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream)

[IMiniportMidiStream::Write](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportmidistream-write)

[IPortMidi::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportmidi-notify)
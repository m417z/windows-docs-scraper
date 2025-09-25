# IMiniportMidiStream::SetFormat

## Description

The `SetFormat` method sets the KS data format of the MIDI stream.

## Parameters

### `DataFormat` [in]

Specifies the new format for the stream. This parameter is a pointer to a structure of type [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

## Return value

`SetFormat` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The `SetFormat` method essentially does nothing because the data format of a MIDI stream cannot be changed to anything other than MIDI. This method is provided for the sake of completeness and for orthogonality with the `SetFormat` methods in the **IMiniportWaveCyclic** and **IMiniportWavePci** interfaces. See the trivial implementation of this method in the fmsynth sample audio driver in the Microsoft Windows Driver Kit (WDK). You can use the sample code as a template for your own implementation.

## See also

[IMiniportMidiStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidistream)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)
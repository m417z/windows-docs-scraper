# KSRTAUDIO_HWLATENCY structure

## Description

The KSRTAUDIO_HWLATENCY structure describes the latency that the audio hardware adds to a wave stream during playback or recording.

## Members

### `FifoSize`

Specifies the size, in bytes, of the hardware FIFO.

### `ChipsetDelay`

Specifies the delay through the chipset in 100-nanosecond units.

### `CodecDelay`

Specifies the delay through the codec in 100-nanosecond units.

## Remarks

The [KSPROPERTY_RTAUDIO_HWLATENCY](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-hwlatency) property request uses the KSRTAUDIO_HWLATENCY structure to pass hardware-latency information from the driver to the client.

The **FifoSize** member specifies the size of the hardware FIFO that the audio device uses to buffer the wave data that is in transit between memory and the digital-to-analog or analog-to-digital converter (DAC or ADC). During playback, the audio device reads data from memory and holds the data in the FIFO until the time arrives to feed the data to the DAC. During recording, the FIFO accumulates data from the ADC before writing it to main memory. The size of the FIFO can vary with the sample rate and transfer mode.

The **ChipsetDelay** member is the maximum delay that the chipset adds to data packets traveling between the CPU and main memory. Packet-based hardware interfaces such as PCI Express have nonzero delays with guaranteed upper bounds for isochronous transfer modes, that is, continuous data streaming at periodic intervals. However, for legacy PCI, which uses traditional parallel-bus transfers, the delay is specified as 0.

The **CodecDelay** member is the delay that the codec adds to an audio stream. The time required for a sample to travel between the audio bus and the input or output jack includes delays through the FIFO, DAC, or ADC, and any intermediate processing stages. The codec delay can vary with the sample rate and is therefore only a best estimate.

## See also

[KSPROPERTY_RTAUDIO_HWLATENCY](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-hwlatency)
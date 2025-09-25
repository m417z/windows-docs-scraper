# IMiniportWavePciStream::GetAllocatorFraming

## Description

The `GetAllocatorFraming` method gets the preferred allocator-framing parameters for the stream.

## Parameters

### `AllocatorFraming` [out]

Pointer to a [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing) structure into which the method writes the miniport driver's allocator-framing preferences for this stream.

## Return value

`GetAllocatorFraming` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport driver should not assume that the actual allocator-framing parameters for the stream match those specified in the `GetAllocatorFraming` call. The port driver interprets the allocation-framing parameters from the `GetAllocatorFraming` as the miniport driver's preferences. Other factors might outweigh these preferences, however, when the [SysAudio system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components) builds the audio filter graph.

See the discussion of allocator framing in [WavePci Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/wavepci-latency).

## See also

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)
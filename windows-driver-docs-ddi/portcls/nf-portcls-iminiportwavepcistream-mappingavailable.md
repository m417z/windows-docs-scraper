# IMiniportWavePciStream::MappingAvailable

## Description

The `MappingAvailable` method indicates that a new mapping is available.

## Remarks

The port driver calls the `MappingAvailable` method to notify the miniport driver that a new mapping has become available, but it does so only when the miniport driver's previous request for mapping through [IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping) has been refused.

The port driver (Portcls.sys) can call the `MappingAvailable` method at any level equal to or below DISPATCH_LEVEL, depending on the circumstances under which the call is made. As a result, the `MappingAvailable` method must be in a non-paged code segment and can only touch non-paged code.

See the discussion of allocator framing in [WavePci Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/wavepci-latency).

## See also

[IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)

[IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping)
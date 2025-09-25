# KSSTREAMALLOCATOR_STATUS structure

## Description

The KSSTREAMALLOCATOR_STATUS structure describes framing requirements and current number of allocated frames for a specific allocator.

## Members

### `Framing`

A [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing) structure that contains the framing specified when the allocator was created.

### `AllocatedFrames`

Contains the current number of allocated frames. This value changes on an extremely frequent basis.

### `Reserved`

Reserved and set to zero.

## Remarks

Clients can query allocator status by providing a KSSTREAMALLOCATOR_STATUS structure in a [KSPROPERTY_STREAMALLOCATOR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-status) property request.

## See also

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)

[KSPROPERTY_STREAMALLOCATOR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-status)
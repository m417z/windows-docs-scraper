# KSSTREAMALLOCATOR_STATUS_EX structure

## Description

Client use KSSTREAMALLOCATOR_STATUS_EX to query the status for allocators supporting the extended allocator framing.

## Members

### `Framing`

Contains the framing specified when the allocator was created.

### `AllocatedFrames`

Contains the current number of allocated frames.

### `Reserved`

Reserved and set to zero.

## Remarks

KSSTREAMALLOCATOR_STATUS_EX corresponds closely to KSSTREAMALLOCATOR_STATUS except that instead of passing back a KSALLOCATOR_FRAMING, it passes back the extended structure.
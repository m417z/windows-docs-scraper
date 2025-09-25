# DXGI_RESIDENCY enumeration

## Description

Flags indicating the memory location of a resource.

## Constants

### `DXGI_RESIDENCY_FULLY_RESIDENT:1`

The resource is located in video memory.

### `DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY:2`

At least some of the resource is located in CPU memory.

### `DXGI_RESIDENCY_EVICTED_TO_DISK:3`

At least some of the resource has been paged out to the hard drive.

## Remarks

This enum is used by [QueryResourceResidency](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgidevice-queryresourceresidency).

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)
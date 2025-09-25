# _D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION_TYPE enumeration

## Description

**D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION_TYPE** describes the details of the virtual address update operation being performed.

## Constants

### `D3DDDI_UPDATEGPUVIRTUALADDRESS_MAP`

Maps the given virtual address range to the given allocation range. The allocation does not have to be resident at the time of submission or at the time of mapping. The read-write protection is set to the pages. **DriverProtection** for the pages is set to zero.

### `D3DDDI_UPDATEGPUVIRTUALADDRESS_UNMAP`

Puts the specified virtual address range to the *zero* state or to the *invalid* state.

### `D3DDDI_UPDATEGPUVIRTUALADDRESS_COPY`

The *copy* operation copies all mappings from source GPU virtual address range to the destination range. The source and destination ranges are allowed to intersect. Both ranges must belong to a reserved (zero) virtual address range.

### `D3DDDI_UPDATEGPUVIRTUALADDRESS_MAP_PROTECT`

Maps the given virtual address range to the given allocation range. The allocation does not have to be resident at the time of submission or at the time of mapping. The page protection is specified in the operation.
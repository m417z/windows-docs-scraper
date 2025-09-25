# _D3DKMT_VA_RANGE_DESC structure

## Description

The virtual address (VA) range description.

## Members

### `VadAddress` [in]

The video acceleration display (VAD) address.

### `VaRangeIndex` [in]

The virtual address range index.

### `PhysicalAdapterIndex` [in]

The physical adapter index in the LDA (linked display adapter) chain.

### `StartAddress` [out]

The start address.

### `EndAddress` [out]

The end address.

### `DriverProtection` [out]

The driver protection.

### `OwnerType` [out]

A VIDMM_VAD_OWNER_TYPE owner type.

### `pOwner` [out]

Pointer to the owner.

### `OwnerOffset` [out]

The owner offset.

### `Protection` [out]

A D3DDDIGPUVIRTUALADDRESS_PROTECTION_TYPE protection type.

## Remarks

## See also
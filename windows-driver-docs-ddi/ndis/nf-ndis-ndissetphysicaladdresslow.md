# NdisSetPhysicalAddressLow macro

## Description

**NdisSetPhysicalAddressLow** sets the low-order part of a given physical address to a given
value.

## Parameters

### `_PhysicalAddress` [in]

Specifies a physical address of an OS-dependent size.

### `_Value` [in]

Specifies the value to be written into the low-order part of the address.

## See also

[NDIS_PHYSICAL_ADDRESS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557129(v=vs.85))

[NdisGetPhysicalAddressLow](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetphysicaladdresslow)

[NdisSetPhysicalAddressHigh](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetphysicaladdresshigh)
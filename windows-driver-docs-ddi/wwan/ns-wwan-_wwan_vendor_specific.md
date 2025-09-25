# _WWAN_VENDOR_SPECIFIC structure

## Description

The WWAN_VENDOR_SPECIFIC structure represents vendor-specific data.

## Members

### `uVendorSpecificBufferSize`

The size, in bytes, of the vendor-specific buffer that follows the structure instance in
memory.

## Remarks

NDIS_WWAN_VENDOR_SPECIFIC should have the data following the
**uVendorSpecificBufferSize** member.

## See also

[NDIS_WWAN_VENDOR_SPECIFIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_vendor_specific)
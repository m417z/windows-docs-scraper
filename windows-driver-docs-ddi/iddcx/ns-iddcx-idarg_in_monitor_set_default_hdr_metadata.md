## Description

The **IDARG_IN_MONITOR_SET_DEFAULT_HDR_METADATA** structure contains the input arguments for the [**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata) callback function.

## Members

### `Type`

An [**IDDCX_DEFAULT_HDR_METADATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_default_hdr_metadata_type) value that identifies the type of the default metadata that **Data** points to.

### `Size`

The size in bytes of the buffer that **Data** points to.

### `Data`

Union with the metadata.

### `Data.pHdr10`

Pointer to an [**IDDCX_HDR10_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_metadata) structure that contains the HDR10 metadata that the driver is to save and use if requested later.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_MONITOR_SET_DEFAULT_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_set_default_hdr_metadata)

[**IDDCX_DEFAULT_HDR_METADATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_default_hdr_metadata_type)

[**IDDCX_HDR10_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_metadata)
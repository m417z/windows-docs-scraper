# IDDCX_MONITOR_DESCRIPTION structure

## Description

A **IDDCX_MONITOR_DESCRIPTION** structure provides a monitor description.

## Members

### `Size`

Total size of the structure, in bytes.

### `Type`

A [**IDDCX_MONITOR_DESCRIPTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_monitor_description_type) value that describes the monitor's type.

### `DataSize`

The size in bytes of the monitor description data that **pData** points to.

### `pData`

Pointer to the monitor description data. The data layout depends on **Type** as follows:

* If **Type** is IDDCX_MONITOR_DESCRIPTION_TYPE_EDID:
  * If **DataSize** > 0 and **pData** != NULL, **pData** points to an EDID data formatted monitor description.
  * If **DataSize** = 0 and **pData** = NULL, no monitor description is available.
* If **Type** is IDDCX_MONITOR_DESCRIPTION_TYPE_DISPLAYID_AND_EDID, the monitor description starts with a DisplayID description followed by EDID without any padding in between. The EDID format should contain all available data blocks and be present. The call to connect the monitor will fail if DisplayID is missing or invalid, or if EDID is missing.

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description)

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)
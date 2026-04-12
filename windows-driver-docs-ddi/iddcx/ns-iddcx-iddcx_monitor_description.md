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
* If **Type** is IDDCX_MONITOR_DESCRIPTION_TYPE_DISPLAYID, the monitor description data only contains a DisplayID descriptor. This type can be set by a driver when calling [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate). It can also be set by the OS when calling [**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description), [**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2), [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes), or [**EVT_IDD_CX_MONITOR_QUERY_TARGET_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_query_target_modes2).

## Remarks

In order to support displays that only contain a DisplayID descriptor the **IDDCX_MONITOR_DESCRIPTION** structure has been updated. Specifically, a new IDDCX_MONITOR_DESCRIPTION_TYPE has been added to the [IDDCX_MONITOR_DESCRIPTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_monitor_description_type) enumeration.

Drivers must check for OS support for this functionality, that is, ensure IDDCX_DEVICE_FEATURES_1_11_DISPLAY_ID_ONLY is set in the data returned from a call to [**IddCxCheckOsFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxcheckosfeaturesupport). If the OS doesn't support this functionality, either because it doesn't support IddCx 1.11 or it supports 1.11 but the feature support isn't present, then sending DisplayID only descriptors is an error.

> [!NOTE]
> The **IDDCX_MONITOR_DESCRIPTION::pData** field isn't new, but the summary comments have been updated to reflect the new functionality.
## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description)

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)
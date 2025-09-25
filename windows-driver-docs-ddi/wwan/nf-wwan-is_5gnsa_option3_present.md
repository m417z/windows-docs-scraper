## Description

The **IS_5GNSA_OPTION3_PRESENT** macro determines whether a mobile broadband (MBB) device is registered in a 5G NSA (Option 3) network.

## Parameters

### `dataClass`

A bitmap that represents the data class(es) that the device supports. For a detailed list of values, see the **WwanDataClass** member of [**WWAN_DEVICE_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps). The WWAN_DATA_CLASS_5G bit must be set if 5G NSA data service is supported.

### `dataSubclass`

A bitmap that represents the data subclass(es) that the device supports. For a detailed list of values, see the **dataSubclass** member of [**IS_5G_5GC_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/nf-wwan-is_5g_5gc_present). 5G NSA data service is supported if the WWAN_DATA_SUBCLASS_5G_ENDC bit is set.

## Remarks

## See also

[**IS_5G_5GC_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/nf-wwan-is_5g_5gc_present)
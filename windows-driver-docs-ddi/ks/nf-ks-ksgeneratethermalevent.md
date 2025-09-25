## Description

This function is used by clients (miniport drivers) that do not want to subscribe to the thermal manager, but want to do their own thermal management.

There is a check that verifies whether the miniport driver has the query interface support for a thermal manager (for example, the device is actively managed by a thermal manager). In cases of devices managed by a thermal manager, this call is rejected.

## Parameters

### `Object` [in]

Can be [**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice), [**KSFILTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter), or [**KSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin). Depending on the object passed, the thermal notification is sent device-wide, filter-wide, or to the pin.

### `Value` [in]

KSDEVICE_THERMAL_STATE_LOW or KSDEVICE_THERMAL_STATE_HIGH

## Return value

 Returns STATUS_SUCCESS for success and STATUS_INVALID_DEVICE_REQUEST if the parameters are incorrect.
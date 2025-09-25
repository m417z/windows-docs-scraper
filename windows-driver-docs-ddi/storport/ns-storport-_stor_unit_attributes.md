# STOR_UNIT_ATTRIBUTES structure

## Description

The **STOR_UNIT_ATTRIBUTES** structure contains bit fields that indicate a storage device unit's support for various attributes.

## Members

### `DeviceAttentionSupported`

Set to 1 if device attention is supported for the unit. Otherwise, set to 0.

### `AsyncNotificationSupported`

Set to 1 if the device supports asynchronous notifications. Otherwise, set to 0.

### `D3ColdNotSupported`

Set to 1 if the D3 Cold power state is *not* supported. Otherwise, set to 0.

### `BypassIOSupported`

Set to 1 if [BypassIO](https://learn.microsoft.com/windows-hardware/drivers/storage/bypassio) is supported for the unit. Otherwise, set to 0.

### `Reserved`

Reserved bits. Must be set to 0.

## Remarks

To register a unit's support for various attributes with Storport, a Storport miniport driver calls [**StorPortSetUnitAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetunitattributes) with this structure as a parameter.

If the miniport driver supports asynchronous notifications, the **AsyncNotificationSupported** field set to 1, it will send notifications to the Storport driver using the [**StorPortAsyncNotificationDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportasyncnotificationdetected) routine.

## See also

[**StorPortAsyncNotificationDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportasyncnotificationdetected)

[**StorPortSetUnitAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetunitattributes)
# PCW_CALLBACK_TYPE enumeration

## Description

The `PCW_CALLBACK_TYPE` enumeration defines the type of the notification sent by the system to the provider-defined [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) function. The system passes a value of this enumeration in the `Type` parameter of the callback.

## Constants

### `PcwCallbackAddCounter`

The system invokes the provider's callback with this `Type` value to notify the provider that a consumer has added an instance filter to a query involving this counterset.

Most providers will ignore notifications with this `Type`, but some might use this notification to optimize their data collection. For example, a provider might `InterlockedIncrement` a global counter for each AddCounter notification and only track performance data when the global counter is non-zero.

### `PcwCallbackRemoveCounter`

The system invokes the provider's callback with this `Type` value to notify the provider that a consumer has removed an instance filter from a query involving this counterset.

Most providers will ignore notifications with this `Type`, but some might use this notification to optimize their data collection. For example, a provider might `InterlockedDecrement` a global counter for each RemoveCounter notification and only track performance data when the global counter is non-zero.

### `PcwCallbackEnumerateInstances`

The system invokes the provider's callback with this `Type` value to request the provider to provide the Name and Id values for the instances of the counterset.

Most providers will use the same implementation for PcwCallbackEnumerateInstances and PcwCallbackCollectData notifications, but some might optimize data collection by skipping collection of counter data values when responding to a PcwCallbackEnumerateInstances callback.

### `PcwCallbackCollectData`

The system invokes the provider's callback with this `Type` value to request the provider to provide the Name, Id, and counter data values for the instances of the counterset.

Refer to the documentation for the [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) function for details and examples of handling this notification.

## See also

[PCW_CALLBACK callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback)
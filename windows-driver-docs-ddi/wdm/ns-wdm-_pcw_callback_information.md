# PCW_CALLBACK_INFORMATION structure

## Description

The `PCW_CALLBACK_INFORMATION` union contains details for a notification sent by the system to a provider-defined [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) function. The system passes a pointer to this union in the `Info` parameter of the callback. The active field of the union is determined by the value of the `Type` parameter of the callback.

## Members

### `AddCounter`

A [PCW_COUNTER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_counter_information) structure that contains details for a `PcwCallbackAddCounter` notification.

### `RemoveCounter`

A [PCW_COUNTER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_counter_information) structure that contains details for a `PcwCallbackRemoveCounter` notification.

### `EnumerateInstances`

A [PCW_MASK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_mask_information) structure that contains details for a `PcwCallbackEnumerateInstances` notification.

### `CollectData`

A [PCW_MASK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_mask_information) structure that contains details for a `PcwCallbackCollectData` notification.

## See also

[PCW_CALLBACK callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback)

[_PCW_COUNTER_INFORMATION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_counter_information)

[_PCW_MASK_INFORMATION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_mask_information)
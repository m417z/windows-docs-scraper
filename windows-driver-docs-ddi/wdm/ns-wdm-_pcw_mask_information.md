# PCW_MASK_INFORMATION structure

## Description

The `PCW_MASK_INFORMATION` structure is the type of the `EnumerateInstances` and `CollectData` members of the [_PCW_CALLBACK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_callback_information) union. It contains details of a notification sent by the system to a provider-defined [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) function.

## Members

### `CounterMask`

A bitmask. If the `x`-th bit is set, the counter with ID `x` is included in the query.

### `InstanceMask`

A Unicode string that contains a wildcard specification of instance names to be matched in the query. If all instance names should match the query, the `InstanceMask` field will be `"*"`. Otherwise, `"*"` and `"?"` have the usual wildcard meaning of "zero-or-more-characters" and "any-character" respectively. Note that instance name matching is not case-sensitive.

### `InstanceId`

The numeric value that identifies the ID of the instance(s) to be collected. If the value is `PCW_ANY_INSTANCE_ID` (0xFFFFFFFF), all instance IDs should match the query.

### `CollectMultiple`

The BOOLEAN value that indicates whether the consumer will accept more than one instance in the results of the query. This will be FALSE if the counterset is being treated as a single-instance counterset. This will be TRUE if the counterset is being treated as a multi-instance counterset.

This value can be used to optimize data collection. If `CollectMultiple` is false then the data collection callback can return after adding one instance since additional instances will be ignored by the consumer.

### `Buffer`

A handle to the system-managed buffer to which the instance(s) of the counterset will be added. This handle should be used when calling [**PcwAddInstance**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwaddinstance) - or when calling the CTRPP-generated AddXxx function, which wraps the call to **PcwAddInstance**. For more info, see the Remarks of that page.

### `CancelEvent`

If this field is non-NULL, it is an initialized event object that will be signaled if the request is canceled.

## See also

[PCW_CALLBACK callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback)

[_PCW_CALLBACK_INFORMATION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_callback_information)
# PCW_COUNTER_INFORMATION structure

## Description

The `PCW_COUNTER_INFORMATION` structure is the type of the `AddCounter` and `RemoveCounter` members of the [PCW_CALLBACK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_callback_information) union. It contains details of a notification sent by the system to a provider-defined [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) function.

## Members

### `CounterMask`

A bitmask. If the `x`-th bit is set, counter with ID `x` is included in the query.

### `InstanceMask`

A Unicode string that contains a wildcard specification of instance names to be matched in the query. If all instance names should match the query, the `InstanceMask` field will be `"*"`. Otherwise, `"*"` and `"?"` have the usual wildcard meaning of "zero-or-more-characters" and "any-character" respectively. Note that instance name matching is not case-sensitive.

## See also

[PCW_CALLBACK callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback)

[_PCW_CALLBACK_INFORMATION structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_callback_information)
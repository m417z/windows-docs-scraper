# KSAUTOMATION_TABLE_ structure

## Description

The KSAUTOMATION_TABLE structure defines a structure that combines tables for properties, methods, and events.

## Members

### `PropertySetsCount`

This member specifies the number of property sets in this automation table.

### `PropertyItemSize`

This member specifies size in bytes of property items in this table.

### `PropertySets`

A pointer to an array of [KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) objects (**PropertySetsCount** in length) defining the property sets in this automation table. Each set contains a specific number of items of size **PropertyItemSize**.

### `MethodSetsCount`

This member specifies the number of method sets in this automation table.

### `MethodItemSize`

This member specifies the size in bytes of method items in this table.

### `MethodSets`

An array of [KSMETHOD_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set) objects (**MethodSetsCount** in length) defining the method sets in this automation table. Each set has a specific number of items in it of size **MethodItemSize**.

### `EventSetsCount`

This member specifies the number of event sets in this automation table.

### `EventItemSize`

This member specifies the size in bytes of event items in this table.

### `EventSets`

An array of [KSEVENT_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_set) objects (**EventSetsCount** in length) defining the event sets in this automation table. Each set has a specific number of items in it of size **EventItemSize**.

### `Alignment`

Reserved for internal use by AVStream. Minidrivers should not manipulate this member.

## Remarks

Note that each object (pin, filter, topology node) should define an automation table. Minidrivers can use macros defined in *Ks.h* to define automation tables and the arrays they contain:

- DEFINE_KSAUTOMATION_TABLE

- DEFINE_KSAUTOMATION_PROPERTIES

- DEFINE_KSAUTOMATION_METHODS

- DEFINE_KSAUTOMATION_EVENTS

To specify an automation table containing an empty property array, event array, or method array:

- DEFINE_KSAUTOMATION_PROPERTIES_NULL

- DEFINE_KSAUTOMATION_METHODS_NULL

- DEFINE_KSAUTOMATION_EVENTS_NULL

For example:

```cpp
DEFINE_KSAUTOMATION_TABLE (MyAutomationTable) {
    DEFINE_KSAUTOMATION_PROPERTIES (MyPropertyTable),
    DEFINE_KSAUTOMATION_METHODS (MyMethodTable),
    DEFINE_KSAUTOMATION_EVENTS (MyEventTable)
    };
```

## See also

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)

[KSEVENT_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_set)

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[KSMETHOD_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set)

[KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)

[KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set)
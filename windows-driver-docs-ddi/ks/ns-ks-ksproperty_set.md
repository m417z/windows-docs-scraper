# KSPROPERTY_SET structure

## Description

A kernel streaming driver or pin may use the KSPROPERTY_SET structure to describe how it supports a property set.

## Members

### `Set`

Specifies the GUID that identifies the property set.

### `PropertiesCount`

Specifies the size of the array pointed to by the **PropertyItem** member.

### `PropertyItem`

Points to the beginning of an array of [KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item) structures that describe how the driver or pin supports each property in the set.

### `FastIoCount`

Reserved for system use.

### `FastIoTable`

A pointer to a [KSFASTPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksfastproperty_item) structure. This member is reserved for system use.

## Remarks

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item)
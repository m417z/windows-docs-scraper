# KSOBJECT_CREATE structure

## Description

The KSOBJECT_CREATE structure contains an array of create handlers for base object classes supported by this device object.

## Members

### `CreateItemsCount`

Contains the number of items in the following array.

### `CreateItemsList`

Points to an array of [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item) structures for base object classes supported by this device object.

## See also

[KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item)
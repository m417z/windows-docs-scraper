# _HIDP_LINK_COLLECTION_NODE structure

## Description

The HIDP_LINK_COLLECTION_NODE structure contains information about a [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) in a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [link collection array](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections).

## Members

### `LinkUsage`

Specifies the [usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of a top-level collection.

### `LinkUsagePage`

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of the collection.

### `Parent`

Specifies the index of the collection's parent collection. If the collection has no parent, **Parent** is zero.

### `NumberOfChildren`

Specifies the number of child collections that the collection contains.

### `NextSibling`

Specifies the index of the collection's immediate sibling. If the collection has no sibling, **NextSibling** is zero.

### `FirstChild`

Specifies the index of the collection's first child collection. If the collection has no children, **FirstChild** is zero.

### `CollectionType`

Specifies the type of collection item.

### `IsAlias`

Specifies, if **TRUE**, that this collection is an [aliased collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections). Otherwise, if **FALSE**, the collection is not aliased.

### `Reserved`

Reserved for internal system use.

### `UserContext`

Pointer to application-specific information.

## Remarks

The [HidP_GetLinkCollectionNodes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getlinkcollectionnodes) routine returns a top-level collection's link collection array. The indices specified in a link collection node are indices in the collection's link collection array.

## See also

[HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)

[HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)

[HidP_GetLinkCollectionNodes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getlinkcollectionnodes)
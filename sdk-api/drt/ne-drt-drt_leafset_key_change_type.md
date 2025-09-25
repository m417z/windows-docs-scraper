# DRT_LEAFSET_KEY_CHANGE_TYPE enumeration

## Description

The **DRT_LEAFSET_KEY_CHANGE_TYPE** enumeration defines the set of changes that can occur on nodes in the leaf set of a locally registered key.

## Constants

### `DRT_LEAFSET_KEY_ADDED:0`

A node was added to the DRT leaf set of the local node.

### `DRT_LEAFSET_KEY_DELETED:1`

A node was deleted from the DRT leaf set of the local node.

## Remarks

This enumeration is used to determine the event type returned by [DrtGetEventData](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgeteventdata), which is called with the event handle passed to [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen).

## See also

[DrtGetEventData](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtgeteventdata)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)
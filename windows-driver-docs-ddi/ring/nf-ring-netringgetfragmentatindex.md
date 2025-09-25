# NetRingGetFragmentAtIndex function

## Description

The **NetRingGetFragmentAtIndex** function retrieves a fragment from a net ring.

## Parameters

### `Ring`

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

### `Index`

The fragment index, within the range **[0, Ring->NumberOfElements)**.

## Return value

Returns a pointer to the [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) at the specified index in the fragment ring.

## Remarks

This function is a convenient wrapper around [**NetRingGetElementAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetelementatindex). Client drivers should call this function when working with a fragment ring instead of calling **NetRingGetElementAtIndex** directly.

## See also

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NetRingGetElementAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetelementatindex)
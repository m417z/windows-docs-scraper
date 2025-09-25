# NetRingGetElementAtIndex function

## Description

The **NetRingGetElementAtIndex** function retrieves an element from a net ring.

## Parameters

### `Ring` [_In_]

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

### `Index` [_In_]

The element index, within the range **[0, Ring->NumberOfElements)**.

## Return value

Returns the element at the specified location.

## Remarks

**NetRingGetElementAtIndex** uses the **ElementStride** member of the net ring to index into the buffer and returns the location of the specified element.

**NetRingGetElementAtIndex** is meant for generic use of net rings. Instead, a NetAdapterCx client driver typically calls either [**NetRingGetPacketAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetpacketatindex) for a packet ring or [**NetRingGetFragmentAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetfragmentatindex) for a fragment ring.

## See also

[**NetRingGetPacketAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetpacketatindex)

[**NetRingGetFragmentAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetfragmentatindex)
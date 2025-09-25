# NetRingIncrementIndex function

## Description

Returns the next index value after the specified index value, wrapping around to the beginning of the ring buffer if necessary.

## Parameters

### `Ring` [in]

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

### `Index` [in]

The index value to increment.

## Return value

Returns the next index value after the specified index value, wrapping around to the beginning of the ring buffer if necessary.

## Remarks

This routine is a convenient equivalent to calling [**NetRingAdvanceIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringadvanceindex) with a **Distance** of **1**.

## See also

[**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring)

[**NetRingAdvanceIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringadvanceindex)
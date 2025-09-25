# NetRingAdvanceIndex function

## Description

The **NetRingAdvanceIndex** function advances the index in a net ring forward, wrapping around if necessary.

## Parameters

### `Ring` [_In_]

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring) to access.

### `Index` [_In_]

The index value to advance.

### `Distance` [_In_]

The distance to advance the index.

## Return value

Returns the new index after advancing **Distance** forward in the net ring.

## Remarks

**NetRingAdvanceIndex** enables client drivers to move forward multiple indices in the net ring. Client drivers can also call the wrapper function [**NetRingIncrementIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringincrementindex) to increment the index by **1**.

## See also

[**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring)

[**NetRingIncrementIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringincrementindex)
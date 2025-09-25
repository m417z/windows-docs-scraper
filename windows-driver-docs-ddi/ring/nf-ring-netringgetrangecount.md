# NetRingGetRangeCount function

## Description

Calculates the number of elements contained in a range of the specified net ring buffer.

## Parameters

### `Ring` [in]

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

### `StartIndex` [in]

The inclusive start of the range to measure.

### `EndIndex` [in]

The exclusive end of the range to measure.

## Return value

The number of elements in the given range.

## Remarks

For example, consider a net ring containing a total of 8 elements. Index values for the elements are **0** through **7**. The number of elements in the range **[1, 4)** is 3. This is because the **EndIndex** value is not included, so the range includes elements at index values **1**, **2**, and **3**.

Similarly, the range **[4, 1)** includes elements at index values **4**, **5**, **6**, **7**, and **0** (looping back to the beginning of the ring), for a total of 5 elements.

Finally, note that an empty range like **[2, 2)** returns zero elements.

## See also
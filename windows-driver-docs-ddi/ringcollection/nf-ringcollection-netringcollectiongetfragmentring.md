# NetRingCollectionGetFragmentRing function

## Description

The **NetRingCollectionGetFragmentRing** gets the fragment ring for a packet queue.

## Parameters

### `Rings`

A pointer to a [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure that describes this packet queue's net rings.

## Return value

Returns a pointer to the fragment [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring) for the packet queue.

## Remarks

Client drivers typically call this function when they need to work with a fragment ring directly, such as when the driver is posting information to hardware. For example, during transmit a driver might use the fragment ring's **ElementIndexMask** to retrieve the correct fragment that is being posted to hardware in order to populate the hardware descriptor.

For examples of using this function, see the [Realtek sample driver](https://github.com/Microsoft/NetAdapter-Cx-Driver-Samples/tree/release_1809/RtEthSample).

## See also

[Introduction to net rings](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-net-rings)
# SdpAddAttributeToTree function

## Description

The Bluetooth
**SdpAddAttributeToTree** function is used to attach an SDP attribute node to the top level of an SDP
record.

## Parameters

### `Tree`

The top level of the SDP record to which the
**SdpAddAttributeToTree** function attaches the SDP attribute node.

### `AttribId` [in]

The identifier of the attribute to attach.

### `AttribValue`

Pointer to the SDP node to be added as an attribute.

### `tag` [in]

Specifies a 4-byte
[pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory
allocation. For more information about pool tags, see
[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

## Return value

Possible return values include:

## Remarks

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface).

For more information about the tree structure, see
[Converting SDP Records to a
Tree Structure](https://learn.microsoft.com/previous-versions/ff536672(v=vs.85)).

## See also

[BTHDDI_SDP_NODE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_node_interface)
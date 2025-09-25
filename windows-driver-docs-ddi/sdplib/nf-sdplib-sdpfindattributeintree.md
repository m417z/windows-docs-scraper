# SdpFindAttributeInTree function

## Description

The Bluetooth
**SdpFindAttributeInTree** function is used to locate the specified attribute node in the tree-based
representation of an SDP record.

## Parameters

### `Tree` [in]

The root node of the tree-based representation of the SDP record to search.

### `AttribId` [in]

The identifier of the attribute node to locate.

### `Attribute`

A pointer to a variable that receives the address of the located attribute node.

## Return value

Possible return values include:

## Remarks

The
**SdpFindAttributeInTree** function returns the address of the requested node in the tree; it does not
perform a copy. This node pointer is valid until the SDP tree that it references is freed.

Bluetooth profile drivers can obtain a pointer to this function through the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) structure.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)
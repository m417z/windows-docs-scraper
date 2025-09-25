# _BDANODE_DESCRIPTOR structure

## Description

The BDANODE_DESCRIPTOR structure describes a BDA node.

## Members

### `ulBdaNodeType`

The node type as the BDA template topology identifies it. The BDA node-type identifier typically corresponds to the index of the element in the zero-based array of node types. This array of node types is an array of KSNODE_DESCRIPTOR structures.

### `guidFunction`

GUID that describes the node's function. See [BDA Node Category GUIDs](https://learn.microsoft.com/windows-hardware/drivers/stream/bda-node-category-guids) for a list of these GUIDs.

### `guidName`

GUID that can be used to store a string containing the name of the node. Applications can search the registry for this GUID to obtain the node's name and then can display the name.

## See also

[BDA Node Category GUIDs](https://learn.microsoft.com/windows-hardware/drivers/stream/bda-node-category-guids)

[KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)
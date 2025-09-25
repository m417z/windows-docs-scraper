# KSNODE_CREATE structure

## Description

The KSNODE_CREATE structure describes the set of information used to create the node handle.

## Members

### `CreateFlags`

Set to zero.

### `Node`

Indicates what node a handle should be created for. This refers to the node identifiers returned when querying topology information. A node identifier of −1 may be used to refer to the collection of nodes as a whole, if the filter supports it.

## See also

[KsCreateTopologyNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatetopologynode)
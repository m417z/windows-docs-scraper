# CLUS_FORCE_QUORUM_INFO structure

## Description

Specifies information about the list of
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) sufficient to establish quorum in a majority-of-nodes
cluster.

## Members

### `dwSize`

The total size of the structure, including the nodes list.

### `dwNodeBitMask`

A bit mask representing the maximum assumed node set.

### `dwMaxNumberofNodes`

The number of bits set in the mask

### `multiszNodeList`

The names of the nodes that are sufficient to establish quorum in a majority-of-nodes cluster. This list should be comma delimited with no spaces.

## See also

[CLUSCTL_RESOURCE_FORCE_QUORUM](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-force-quorum)
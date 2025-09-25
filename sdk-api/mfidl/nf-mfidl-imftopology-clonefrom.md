# IMFTopology::CloneFrom

## Description

Converts this topology into a copy of another topology.

## Parameters

### `pTopology` [in]

A pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the topology to clone.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does the following:

* Removes all of the nodes from this topology.
* Clones the nodes from *pTopology* and adds them to this topology. The cloned nodes have the same node identifiers as the nodes from *pTopology*.
* Connects the cloned nodes to match the connections in *pTopology*.
* Copies the attributes from *pTopology* to this topology.
* Copies the topology identifier from *pTopology* to this topology.

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)
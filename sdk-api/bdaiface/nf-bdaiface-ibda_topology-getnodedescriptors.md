# IBDA_Topology::GetNodeDescriptors

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNodeDescriptors** method retrieves a list of descriptors for the nodes in the topology.

## Parameters

### `ulcNodeDescriptors` [in, out]

Receives a count of the number of node descriptors written to the *rgNodeDescriptors* array.

### `ulcNodeDescriptorsMax` [in]

Specifies the maximum number of node descriptors that the *rgNodeDescriptors* array can hold.

### `rgNodeDescriptors` [in, out]

Pointer to a buffer that receives an array of node descriptors. Each node descriptor is a structure of type [BDANODE_DESCRIPTOR](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bdanode-descriptor).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
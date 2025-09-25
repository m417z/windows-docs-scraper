# IBDA_Topology::GetNodeInterfaces

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNodeInterfaces** method retrieves a list of the interfaces supported by a node type.

## Parameters

### `ulNodeType` [in]

Specifies the node type for which the interface list is being requested.

### `pulcInterfaces` [out]

Pointer that receives the number of interfaces in the list.

### `ulcInterfacesMax` [in]

Specifies the maximum number of interfaces that *rgguidInterfaces* can hold.

### `rgguidInterfaces` [out]

Pointer to a buffer that holds the list of interface GUIDs.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
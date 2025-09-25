# IBDA_Topology::GetNodeTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNodeTypes** method retrieves a list of all the node types in the template topology for this filter and network type.

## Parameters

### `pulcNodeTypes` [out]

Pointer that receives the number of node types in the list.

### `ulcNodeTypesMax` [in]

The maximum number of node types that can be held by the *rgulNodeTypes* buffer.

### `rgulNodeTypes` [out]

Pointer to a buffer that receives the list of node types.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The **IBDA_Topology** interface is implemented by a BDA Device Filter. It is used by a Network Provider to query a BDA Device Filter's possible topologies (template topology) and to configure the device with an appropriate topology for the current tuning request. It is also used to get an **IUnknown** to a control node which may be used to set specific tuning information.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
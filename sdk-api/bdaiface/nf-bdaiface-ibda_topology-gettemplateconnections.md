# IBDA_Topology::GetTemplateConnections

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetTemplateConnections** method retrieves a list of all template connections that appear in the template topology for this filter and network type.

## Parameters

### `pulcConnections` [out]

Pointer to a value to receive the number of connections in the list.

### `ulcConnectionsMax` [in]

The maximum number of connections that can be held by the *rgConnections* buffer.

### `rgConnections` [out]

Pointer to a buffer that receives the list of connections.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
# IBDA_Topology::GetControlNode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetControlNode** method retrieves an **IUnknown** interface pointer for a specified control node.

## Parameters

### `ulInputPinId` [in]

Specifies the identifier of the input pin for which a topology should be created.

### `ulOutputPinId` [in]

Specifies the identifier of the output pin for which a topology should be created.

### `ulNodeType` [in]

The type of node to be opened.

### `ppControlNode` [out]

Pointer to a pointer to the control node's **IUnknown** interface

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
# IBDA_Topology::CreateTopology

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CreateTopology** method associates an instance of an input pin with an instance of an output pin.

## Parameters

### `ulInputPinId` [in]

Specifies the identifier of the input pin for which a topology should be created.

### `ulOutputPinId` [in]

Specifies the identifier of the output pin for which a topology should be created.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
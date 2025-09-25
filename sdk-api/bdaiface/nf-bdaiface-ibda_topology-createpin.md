# IBDA_Topology::CreatePin

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CreatePin** method creates an instance of a specified pin type.

## Parameters

### `ulPinType` [in]

Specifies the type of pin to create. To obtain the available values, call [IBDA_Topology::GetPinTypes](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_topology-getpintypes).

### `pulPinId` [out]

Pointer that receives the identifier for the new pin.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
# IBDA_Topology::GetPinTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPinTypes** method retrieves a list of all the pin types in the template topology for this filter and network type.

## Parameters

### `pulcPinTypes` [out]

Pointer to a value that receives the number of pin types in the list.

### `ulcPinTypesMax` [in]

The maximum number of pin types that can be held by the *rgulPinTypes* buffer.

### `rgulPinTypes` [out]

Pointer to a buffer to receive the list of pin types.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
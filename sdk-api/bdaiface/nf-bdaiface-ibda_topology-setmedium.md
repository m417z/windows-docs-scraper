# IBDA_Topology::SetMedium

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetMedium** method configures the medium on which a particular pin sends data.

## Parameters

### `ulPinId` [in]

Specifies the identifier of the pin on which to set the medium.

### `pMedium` [in]

Pointer to the medium on which the pin will send data.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

A medium is a structure that identifies a hardware data path between two devices on the host system. They can be devices on the same card, such as a crossbar and a tuner on a TV card; devices on separate cards; or external devices. Kernel-mode filters based on the Windows Driver Model can use mediums instead of media types to determine pin connections.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_Topology Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_topology)
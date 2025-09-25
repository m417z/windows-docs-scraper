# IBDA_TIF_REGISTRATION::RegisterTIFEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RegisterTIFEx** method registers a Transport Information Filter (TIF) with the Network Provider.

## Parameters

### `pTIFInputPin` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of the input pin on the TIF.

### `ppvRegistrationContext` [in, out]

Receives a token identifying the connection. Pass this token in the **UnregisterTIF** method when the TIF unregisters itself.

### `ppMpeg2DataControl` [in, out]

Receives a pointer to an **IUnknown** interface, which the TIF queries for the [IMPEG2PIDMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdaiface/nn-bdaiface-impeg2pidmap) interface. It uses the **IMPEG2PIDMap** to map and unmap PID values.

## Return value

The method returns an **HRESULT** value.

## See also

[IBDA_TIF_REGISTRATION Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ibda_tif_registration)
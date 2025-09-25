# IBDA_FDC::GetStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tuning status of the Forward Data Channel (FDC) stream.

## Parameters

### `CurrentBitrate` [out]

Receives the expected bit rate of the FDC stream, in kilobits per second (kbps).

### `CarrierLock` [out]

Receives the carrier lock status.

### `CurrentFrequency` [out]

Receives the current frequency of the FDC tuner, in kHz.

### `CurrentSpectrumInversion` [out]

Receives the expected spectrum inversion status of the FDC stream.

### `CurrentPIDList` [out]

Receives a comma-separated list of packet identifiers (PIDs). The caller must release the string by calling **SysFreeString**.

### `CurrentTIDList` [out]

Receives a comma-separated list of table identifiers (TIDs). The caller must release the string by calling **SysFreeString**.

### `Overflow` [out]

Receives the overflow status.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_FDC](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_fdc)
# IBDA_FDC::RemovePid

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Removes one or more packet identifiers (PIDs) from the MPEG flow.

## Parameters

### `PidsToRemove` [in]

A comma-separated list of PIDs to remove.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This command causes the device to send a delete_flow_req Application Protocol Data Unit (APDU).

## See also

[IBDA_FDC](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_fdc)
# IBDA_FDC::AddTid

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Adds one or more table identifiers (TIDs) to the MPEG flow.

## Parameters

### `TidsToAdd` [in]

A comma-separated list of TIDs.

### `CurrentTidList` [out]

Receives a comma-separated list of the current TIDs. The caller must release the string by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_FDC](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_fdc)
# IBDA_SignalProperties::GetTuningSpace

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetTuningSpace** method retrieves the tuning space for the current tuning request.

## Parameters

### `pguidTuingSpace` [in, out]

Pointer to a variable that receives a GUID identifying the tuning space.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IBDA_SignalProperties Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_signalproperties)

[PutTuningSpace](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_signalproperties-puttuningspace)
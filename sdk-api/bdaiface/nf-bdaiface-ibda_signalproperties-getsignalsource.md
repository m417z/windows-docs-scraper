# IBDA_SignalProperties::GetSignalSource

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetSignalSource** method retrieves the signal source for the current tuning request.

## Parameters

### `pulSignalSource` [in, out]

Receives a value identifying the signal source. The value is an arbitrary identifier set by the network provider. If two tuners share the same signal source, they should have the same identifier.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method returns whatever value was last set by calling [IBDA_SignalProperties::PutSignalSource](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_signalproperties-putsignalsource).

**Note**The *pulSignalSource* parameter is marked in the IDL file as [in, out] but is used as an [out] parameter. To preserve binary compatibility with previous versions, it has not been changed.

## See also

[IBDA_SignalProperties Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_signalproperties)

[PutSignalSource](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_signalproperties-putsignalsource)
# IBDA_DeviceControl::GetChangeState

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetChangeState** method returns a value indicating whether any uncommitted changes are currently pending in the filter.

## Parameters

### `pState` [out]

Receives the current state of the filter. See BDA_CHANGE_STATE in the Windows DDK for possible values.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_devicecontrol)
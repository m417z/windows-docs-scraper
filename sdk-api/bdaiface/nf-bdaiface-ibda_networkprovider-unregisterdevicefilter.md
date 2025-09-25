# IBDA_NetworkProvider::UnRegisterDeviceFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **UnRegisterDeviceFilter** method is called by BDA device filters when they are removed from the filter graph.

## Parameters

### `pvRegistrationContext` [in]

The registration context that the filter received in the call to **RegisterDeviceFilter**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_NetworkProvider Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_networkprovider)
# IBDA_NetworkProvider::RegisterDeviceFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RegisterDeviceFilter** method is called by a BDA device filter to register itself in the filter graph.

## Parameters

### `pUnkFilterControl` [in]

Pointer to the filter's **IUnknown** interface.

### `ppvRegisitrationContext` [out]

Pointer that receives the registration context. The filter should store this value and return it in the call to **UnRegisterDeviceFilter**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_NetworkProvider Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_networkprovider)
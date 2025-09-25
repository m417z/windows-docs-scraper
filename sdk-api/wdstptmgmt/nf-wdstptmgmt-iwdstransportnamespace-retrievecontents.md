# IWdsTransportNamespace::RetrieveContents

## Description

Retrieves a collection of active transport content objects associated with the namespace.

## Parameters

### `ppWdsTransportContents` [out]

A pointer to a [IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection) object that contains a collection of [IWdsTransportContent](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcontent) objects that represent active sessions under this namespace.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection)

[IWdsTransportContent](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcontent)

[IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace)
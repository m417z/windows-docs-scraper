# IIsdbCAContractInformationDescriptor::GetCASystemId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the CA_system_id field from an Integrated Services Digital Broadcasting (ISDB) conditional access (CA) contract information descriptor. This field identifies the conditional access system associated with the contract information.

## Parameters

### `pwVal` [out]

Receives the conditional access system identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCAContractInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcacontractinformationdescriptor)
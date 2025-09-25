# IIsdbCAContractInformationDescriptor::GetContractVerificationInfo

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets data from the contract_verification_info field in an Integrated Services Digital Broadcasting (ISDB) conditional access (CA) contract information descriptor. This field is used to determine allowable uses of the conditional access service.

## Parameters

### `bBufLength` [in]

Specifies the length of the buffer that holds the contract verification data.

### `pbBuf` [out]

Pointer to a buffer that receives the contract verification data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The contract_verification_info field is used to confirm whether the service, or the ES group
that comprises a service, can be reserved for viewing (recording). When the contract_verification_info field appears in the event information table (EIT), it is also used to determine whether the event in question is
a flat-type or tier-type event, an ES group that comprises an event, a pay-per-view (PPV) event, or an ES
group that comprises a PPV event. If the event is a PPV event or ES group that comprises a PPV event, the descriptor is used to determine the viewing fee and recording
request information.

## See also

[IIsdbCAContractInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcacontractinformationdescriptor)
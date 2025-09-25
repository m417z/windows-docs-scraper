# IIsdbCAContractInformationDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies an Integrated Services Digital Broadcasting (ISDB) conditional access (CA)contract information descriptor.

## Parameters

### `pbVal` [out]

Receives the tag value. For ISDB CA contract information descriptors, this value is 0xCB.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCAContractInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcacontractinformationdescriptor)
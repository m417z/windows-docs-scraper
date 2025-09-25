# IIsdbCAContractInformationDescriptor::GetRecordComponentTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the broadcaster-defined tag that identifies a component record from an Integrated Services Digital Broadcasting (ISDB) conditional access (CA) contract information descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the component record that contains the tag. To get the number of components, call [IIsdbCAContractInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcacontractinformationdescriptor-getcountofrecords).

### `pbVal` [out]

Receives the component record ID tag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCAContractInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcacontractinformationdescriptor)
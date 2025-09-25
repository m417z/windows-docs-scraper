# IIsdbEmergencyInformationDescriptor::GetServiceId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the identifier for a broadcasting event from an emergency information descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the emergency information descriptor that contains the event identifiers. To get the number of emergency information descriptors, call [IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)

### `pwVal` [out]

Receives the broadcasting event identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEmergencyInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbemergencyinformationdescriptor)

[IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)
# IIsdbEmergencyInformationDescriptor::GetSignalLevel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a flag that indicates the emergency alarm signal type from an emergency information descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the emergency information descriptor that contains the emergency alarm signal. To get the number of emergency information descriptors, call [IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords).

### `pbVal` [out]

Receives a boolean value that indicates whether the emergency alarm signal is the first (0) or second (1) type of start signal. Annex D of the document titled *SERVICE INFORMATION FOR DIGITAL
BROADCASTING SYSTEM,
ARIB STANDARD,
ARIB STD-B10, Version 4.4* describes the two start signal types.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEmergencyInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbemergencyinformationdescriptor)

[IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)
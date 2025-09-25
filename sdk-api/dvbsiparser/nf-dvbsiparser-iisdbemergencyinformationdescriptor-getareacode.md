# IIsdbEmergencyInformationDescriptor::GetAreaCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the area codes from an emergency information descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the emergency information descriptor that contains the area code records. To get the number of area code records, call [IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords).

### `ppwVal` [out]

Pointer to a buffer allocated to hold the area codes. The caller is responsible for freeing this memory.

### `pbNumAreaCodes` [out]

Receives the number of area codes in the descriptor.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about area codes and their use with emergency broadcast signals, refer to Annex D of the document titled *SERVICE INFORMATION FOR DIGITAL
BROADCASTING SYSTEM,
ARIB STANDARD,
ARIB STD-B10, Version 4.4*.

## See also

[IIsdbEmergencyInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbemergencyinformationdescriptor)

[IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)
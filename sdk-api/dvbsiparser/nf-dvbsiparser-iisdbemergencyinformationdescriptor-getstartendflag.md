# IIsdbEmergencyInformationDescriptor::GetStartEndFlag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the start_end_flag field from an emergency information descriptor. This field indicates whether the emergency alarm signal has started or finished broadcasting.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the service information (SI) descriptor containing the table descriptor. To get the number of SI descriptors, call [IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)

### `pVal` [out]

Gets the start/end flag from the descriptor. If this value is 1, the emergency signal has started or is being broadcast. If it is 0, the emergency signal broadcast has ended.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEmergencyInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbemergencyinformationdescriptor)

[IIsdbEmergencyInformationDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbemergencyinformationdescriptor-getcountofrecords)
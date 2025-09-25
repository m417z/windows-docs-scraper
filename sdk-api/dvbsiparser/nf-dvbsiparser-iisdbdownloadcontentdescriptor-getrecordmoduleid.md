# IIsdbDownloadContentDescriptor::GetRecordModuleId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the identifier from an Integrated Services Digital Broadcasting (ISDB) download content descriptor that specifies the carousel used for downloading.

## Parameters

### `wRecordIndex` [in]

Specifies the module record number,
indexed from zero. Call the [IIsdbDownloadContentDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbdownloadcontentdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `pwVal` [out]

Receives the module ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDownloadContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdownloadcontentdescriptor)

[IIsdbDownloadContentDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbdownloadcontentdescriptor-getcountofrecords)
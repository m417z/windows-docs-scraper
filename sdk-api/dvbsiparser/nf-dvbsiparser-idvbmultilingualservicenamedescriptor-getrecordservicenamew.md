# IDvbMultilingualServiceNameDescriptor::GetRecordServiceNameW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the service name in string format from a Digital Video Broadcast (DVB) multilingual service name descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the service record number,
indexed from zero. Call the [IDvbMultilingualServiceNameDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbmultilingualservicenamedescriptor-getcountofrecords) method to get the number of records in the logical channel descriptor.

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrName` [out]

Pointer to a buffer that receives the service name string. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbMultilingualServiceNameDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbmultilingualservicenamedescriptor)

[IDvbMultilingualServiceNameDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbmultilingualservicenamedescriptor-getcountofrecords)
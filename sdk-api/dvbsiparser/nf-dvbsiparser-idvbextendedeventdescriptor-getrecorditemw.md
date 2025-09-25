# IDvbExtendedEventDescriptor::GetRecordItemW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the item and descriptor from a Digital Videl Broadcast (DVB) extended event descriptor, in Unicode string format.

## Parameters

### `bRecordIndex` [in]

Specifies the item record number,
indexed from zero. Call the [IDvbExtendedEventDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbextendedeventdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrDesc` [out]

Pointer to a buffer that receives the item description. The caller is responsible for freeing this memory.

### `pbstrItem` [out]

Pointer to a buffer that receives the item text. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor)

[IDvbExtendedEventDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbextendedeventdescriptor-getcountofrecords)
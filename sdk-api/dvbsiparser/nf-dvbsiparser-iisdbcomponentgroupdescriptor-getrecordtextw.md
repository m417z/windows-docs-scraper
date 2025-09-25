# IIsdbComponentGroupDescriptor::GetRecordTextW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the text that describes a component group from an Integrated Services Digital Broadcasting (ISDB) component group descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the component group record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrText` [out]

Receives the text that describes the component group, as a **BSTR**. The caller must free the **BSTR** by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcomponentgroupdescriptor)
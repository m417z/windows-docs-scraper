# IIsdbComponentGroupDescriptor::GetRecordNumberOfCAUnit

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the number of conditional access unit records in a component group from an Integrated Services Digital Broadcasting (ISDB) component group descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the component group record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `pbVal` [out]

Receives the number of conditional access unit records.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcomponentgroupdescriptor)
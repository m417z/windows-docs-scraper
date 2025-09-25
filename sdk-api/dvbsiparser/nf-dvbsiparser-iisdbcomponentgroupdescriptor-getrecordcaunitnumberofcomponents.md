# IIsdbComponentGroupDescriptor::GetRecordCAUnitNumberOfComponents

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the number of components corresponding to a conditional access unit from an Integrated Services Digital Broadcasting (ISDB) component group descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the component record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords) method to get the number of component records in the component group descriptor.

### `bCAUnitIndex` [in]

Specifies the conditional access unit record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetRecordNumberOfCAUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordnumberofcaunit) method to get the number of conditional access unit records in the component group descriptor.

### `pbVal` [out]

Receives the number of components.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcomponentgroupdescriptor)

[IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords)

[IIsdbComponentGroupDescriptor::GetRecordNumberOfCAUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordnumberofcaunit)
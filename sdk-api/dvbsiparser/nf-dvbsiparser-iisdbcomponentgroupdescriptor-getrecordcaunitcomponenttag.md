# IIsdbComponentGroupDescriptor::GetRecordCAUnitComponentTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies a component record in an Integrated Services Digital Broadcasting (ISDB) component group descriptor.

## Parameters

### `bRecordIndex` [in]

Specifies the component record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords) method to get the number of records in the extended event descriptor.

### `bCAUnitIndex` [in]

Specifies the conditional access unit number within the component group,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetRecordNumberOfCAUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordnumberofcaunit) method to get the number of records in the extended event descriptor.

### `bComponentIndex` [in]

Specifies the component within the component group,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetRecordCAUnitNumberOfComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordcaunitnumberofcomponents) method to get the number of components for the conditional access unit given by the *bCAUnitIndex* parameter.

### `pbVal` [out]

Receives the component tag value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcomponentgroupdescriptor)
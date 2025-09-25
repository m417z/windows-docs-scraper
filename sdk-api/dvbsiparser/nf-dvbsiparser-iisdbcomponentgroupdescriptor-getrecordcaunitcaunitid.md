# IIsdbComponentGroupDescriptor::GetRecordCAUnitCAUnitId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a conditional access unit identifier from a specified component group record in an Integrated Services Digital Broadcasting (ISDB) component group descriptor. This identifier specifies the type of conditional access unit group to which the component belongs.

## Parameters

### `bRecordIndex` [in]

Specifies the component group record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords) method to get the number of records in the descriptor.

### `bCAUnitIndex` [in]

Specifies the conditional access unit record number,
indexed from zero. Call the [IIsdbComponentGroupDescriptor::GetRecordCAUnitNumberOfComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordcaunitnumberofcomponents) method to get the number of conditional access records in the descriptor.

### `pbVal` [out]

Receives the conditional access unit identifier. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x0 | Non-conditional access unit group. |
| 0x1 | Conditional access unit group that includes the default elementary stream group. |
| 0x2-0xF | Conditional access unit group other than that including the default elementary stream group. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcomponentgroupdescriptor)

[IIsdbComponentGroupDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcountofrecords)

[IIsdbComponentGroupDescriptor::GetRecordCAUnitNumberOfComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getrecordcaunitnumberofcomponents)
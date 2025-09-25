# ITocParser::GetTocByIndex

## Description

The **GetTocByIndex** method retrieves a table of contents, specified by an index, from the TOC Parser object.

## Parameters

### `unnamedParam1` [in]

A member of the [TOC_POS_TYPE](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ne-wmcodecdsp-toc_pos_type) enumeration that specifies the [position type](https://learn.microsoft.com/windows/desktop/medfound/the-position-type-of-a-table-of-contents) of the table of contents to be retrieved.

### `dwTocIndex` [in]

The index of the table of contents to be retrieved.

### `ppToc` [out]

Pointer to a variable that receives a pointer to an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface that represents the retrieved table of contents.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ITocParser Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)
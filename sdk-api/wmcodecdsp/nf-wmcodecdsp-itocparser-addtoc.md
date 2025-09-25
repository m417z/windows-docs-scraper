# ITocParser::AddToc

## Description

The **AddToc** method adds a table of contents to the TOC Parser object and assigns an index to the added table of contents.

## Parameters

### `unnamedParam1` [in]

A member of the [TOC_POS_TYPE](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ne-wmcodecdsp-toc_pos_type) enumeration that specifies the [position type](https://learn.microsoft.com/windows/desktop/medfound/the-position-type-of-a-table-of-contents) of the table of contents to be added.

### `pToc` [in]

Pointer to an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface that represents the table of contents to be added.

### `pdwTocIndex` [out]

Pointer to a **DWORD** that receives the index of the added table of contents.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[GetTocByIndex](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocparser-gettocbyindex)

[ITocParser](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)
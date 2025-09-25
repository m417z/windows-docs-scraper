# ITocParser::GetTocCount

## Description

The **GetTocCount** method retrieves the number of tables of contents, of a specified [position type](https://learn.microsoft.com/windows/desktop/medfound/the-position-type-of-a-table-of-contents), in the TOC Parser object.

## Parameters

### `unnamedParam1` [in]

A member of the [TOC_POS_TYPE](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ne-wmcodecdsp-toc_pos_type) enumeration that specifies the [position type](https://learn.microsoft.com/windows/desktop/medfound/the-position-type-of-a-table-of-contents) of the tables of contents to be counted.

### `pdwTocCount` [out]

Pointer to a **DWORD** that receives the number of tables of contents.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ITocParser](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)
# ITocParser::RemoveTocByType

## Description

The **RemoveTocByType** method removes all tables of contents of a specified type from the TOC Parser object.

## Parameters

### `unnamedParam1` [in]

A member of the [TOC_POS_TYPE](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ne-wmcodecdsp-toc_pos_type) enumeration that specifies the [position type](https://learn.microsoft.com/windows/desktop/medfound/the-position-type-of-a-table-of-contents) of the tables of contents to be removed.

### `guidTocType` [in]

A globally unique identifier (**GUID**) that specifies the type of table of contents to removed. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You might want to design several different type of tables of contents. In that case, you can distinguish between types by creating a **GUID** that represents each type. You can identify a table of contents as a particular type by setting the **guidType** member of a [TOC_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ns-wmcodecdsp-toc_descriptor) structure and then passing the **TOC_DESCRIPTOR** structure to [IToc::SetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-setdescriptor).

## See also

[ITocParser](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocparser)
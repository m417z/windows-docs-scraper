# ITocCollection::AddEntry

## Description

The **AddEntry** method adds an individual table of contents to the collection and assigns an index to the added table of contents.

## Parameters

### `pToc` [in]

Pointer to an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface that represents the table of contents to be added.

### `pdwEntryIndex` [out]

Pointer to a **DWORD** that receives the index of the added table of contents.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In the context of an [ITocCollection](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoccollection) interface, the word *entry* refers to an individual table of contents. That meaning of the word *entry* is in contrast to its meaning in the context of other interfaces in the TOC Parser technology. For example, in the context of an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface, the word *entry* refers to a block of information, in a table of contents, that represents a section of a video file.

## See also

[GetEntryByIndex](https://learn.microsoft.com/previous-versions/ee264253(v=vs.85))

[ITocCollection](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoccollection)
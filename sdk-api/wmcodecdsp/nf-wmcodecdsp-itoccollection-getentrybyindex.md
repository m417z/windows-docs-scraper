# ITocCollection::GetEntryByIndex

## Description

The **GetEntryByIndex** method retrieves a table of contents, specified by an index, from the collection.

## Parameters

### `dwEntryIndex` [in]

Specifies the index of the table of contents to retrieve.

### `ppToc` [out]

Pointer to a variable that receives a pointer to an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface that represents the table of contents.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In the context of an [ITocCollection](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoccollection) interface, the word *entry* refers to an individual table of contents. That meaning of the word *entry* is in contrast to its meaning in the context of other interfaces in the TOC Parser technology. For example, in the context of an [IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc) interface, the word *entry* refers to a block of information, in a table of contents, that represents a section of a video file.

## See also

[ITocCollection](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoccollection)
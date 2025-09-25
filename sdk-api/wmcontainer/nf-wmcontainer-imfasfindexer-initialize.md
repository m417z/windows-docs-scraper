# IMFASFIndexer::Initialize

## Description

Initializes the indexer object. This method reads information in a ContentInfo object about the configuration of the content and the properties of the existing index, if present. Use this method before using the indexer for either writing or reading an index. You must make this call before using any of the other methods of the [IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer) interface.

## Parameters

### `pIContentInfo` [in]

Pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of the ContentInfo object describing the content with which to use the indexer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ASF_INVALIDDATA** | Invalid ASF data. |
| **MF_E_UNEXPECTED** | Unexpected error. |

## Remarks

The indexer needs to examine the data in the ContentInfo object to properly write or read the index for the content. The indexer will not make changes to the content information and will not hold any references to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface.

In the ASF header, the maximum data-packet size must equal the minimum data-packet size. Otherwise, the method returns **MF_E_UNEXPECTED**.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)
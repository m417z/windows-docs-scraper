# MFGetTopoNodeCurrentType function

## Description

Gets the media type for a stream associated with a topology node.

## Parameters

### `pNode`

A pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface.

### `dwStreamIndex`

The identifier of the stream to query. This parameter is interpreted as follows:

* Transform nodes: The value is the zero-based index of the input or output stream.
* All other node types: The value must be zero.

### `fOutput`

**If TRUE**, the function gets an output type**. If FALSE**, the function gets an input type. This parameter is interpreted as follows:

* Output nodes: The value must be **TRUE**.
* Source nodes: The value must be **FALSE**.
* Tee nodes: The value is ignored.
* Transform nodes: If the value is **TRUE**, the *dwStreamIndex* parameter is the index for an output stream. Otherwise, *dwStreamIndex* is the index for an input stream.

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream index is invalid. |

## Remarks

This function gets the actual media type from the object that is associated with the topology node. The *pNode* parameter should specify a node that belongs to a fully resolved topology. If the node belongs to a partial topology, the function will probably fail.

Tee nodes do not have an associated object to query. For tee nodes, the function gets the node's input type, if available. Otherwise, if no input type is available, the function gets the media type of the node's primary output stream. The primary output stream is identified by the [MF_TOPONODE_PRIMARYOUTPUT](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-primaryoutput-attribute) attribute.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
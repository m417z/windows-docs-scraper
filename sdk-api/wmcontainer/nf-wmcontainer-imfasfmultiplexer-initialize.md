# IMFASFMultiplexer::Initialize

## Description

Initializes the multiplexer with the data from an ASF ContentInfo object.

## Parameters

### `pIContentInfo` [in]

Pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of the **MFASFContentInfo** object that contains the header information of the new ASF file. The multiplexer will generate data packets for this file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This call must be made once at the beginning of encoding, with *pIContentInfo* pointing to the ASF ContentInfo object that describes the content to be encoded. This enables the ASF multiplexer to see, among other things, which streams will be present in the encoding session. This call typically does not affect the data in the ASF ContentInfo object.

## See also

[Creating the Multiplexer Object](https://learn.microsoft.com/windows/desktop/medfound/creating-the-multiplexer-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)
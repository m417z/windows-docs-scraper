# IMFASFMultiplexer::End

## Description

Collects data from the multiplexer and updates the ASF ContentInfo object to include that information in the ASF Header Object.

## Parameters

### `pIContentInfo` [in]

Pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of the ContentInfo object. This must be the same object that was used to initialize the multiplexer. The ContentInfo object represents the ASF Header Object of the file for which the multiplexer generated data packets.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_FLUSH_NEEDED** | There are pending output media samples waiting in the multiplexer. Call [IMFASFMultiplexer::Flush](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-flush) to force the media samples to be packetized. |

## Remarks

For non-live encoding scenarios (such as encoding to a file), the user should call **End** to update the specified ContentInfo object, adding data that the multiplexer has collected during the packet generation process. The user should then call [IMFASFContentInfo::GenerateHeader](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-generateheader) and write the output header at the beginning of the ASF file (overwriting the header obtained at the beginning of the encoding session). For more information, see [Writing an ASF Header Object for a New File](https://learn.microsoft.com/windows/desktop/medfound/writing-an-asf-header-object-for-a-new-file).

During live encoding, it is usually not possible to rewrite the header, so this call is not required for live encoding. (The header in those cases will simply lack some of the information that was not available until the end of the encoding session.)

## See also

[Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)
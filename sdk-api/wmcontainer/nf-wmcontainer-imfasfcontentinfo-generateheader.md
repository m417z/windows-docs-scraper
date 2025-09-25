# IMFASFContentInfo::GenerateHeader

## Description

Encodes the data in the **MFASFContentInfo** object into a binary Advanced Systems Format (ASF) header.

## Parameters

### `pIHeader` [in, out]

A pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of the buffer object that will receive the encoded header. Set to **NULL** to retrieve the size of the header.

### `pcbHeader` [out]

Size of the encoded ASF header in bytes. If *pIHeader* is **NULL**, this value is set to the buffer size required to hold the encoded header.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The ASF Header Objects do not exist for the media that the ContentInfo object holds reference to. |
| **MF_E_ASF_INVALIDDATA** | The ASF Header Object size exceeds 10 MB. |
| **MF_E_BUFFERTOOSMALL** | The buffer passed in *pIHeader* is not large enough to hold the ASF Header Object information. |

## Remarks

The size received in the *pcbHeader* parameter includes the padding size. The content information shrinks or expands the padding data depending on the size of the ASF Header Objects.

During this call, the stream properties are set based on the encoding properties of the profile. These properties are available through the [IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata) interface.

## See also

[ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object)

[Generating a New ASF Header Object](https://learn.microsoft.com/windows/desktop/medfound/generating-a-new-asf-header-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)
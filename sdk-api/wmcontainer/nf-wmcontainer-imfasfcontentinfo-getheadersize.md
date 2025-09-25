# IMFASFContentInfo::GetHeaderSize

## Description

Retrieves the size of the header section of an Advanced Systems Format (ASF) file.

## Parameters

### `pIStartOfContent` [in]

The [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of a buffer object containing the beginning of ASF content. The size of the valid data in the buffer must be at least MFASF_MIN_HEADER_BYTES in bytes.

### `cbHeaderSize` [out]

Receives the size, in bytes, of the header section of the content. The value includes the size of the ASF Header Object plus the size of the header section of the Data Object. Therefore, the resulting value is the offset to the start of the data packets in the ASF Data Object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ASF_INVALIDDATA** | The buffer does not contain valid ASF data. |
| **MF_E_BUFFERTOOSMALL** | The buffer does not contain enough valid data. |

## Remarks

The header of an ASF file or stream can be passed to the [IMFASFContentInfo::ParseHeader](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-parseheader) method to populate the ContentInfo object with the header information.

## See also

[ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[Initializing the ContentInfo Object of a New ASF File](https://learn.microsoft.com/windows/desktop/medfound/initializing-the-contentinfo-object-of-a-new-asf-file)
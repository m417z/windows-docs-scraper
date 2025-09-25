# IMFASFContentInfo::ParseHeader

## Description

Parses the information in an ASF header and uses that information to set values in the ContentInfo object. You can pass the entire header in a single buffer or send it in several pieces.

## Parameters

### `pIHeaderBuffer` [in]

Pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of a buffer object containing some or all of the header. The buffer must contain at least 30 bytes, which is the size of the Header Object, not including the objects contained in the Header Object (that is, everything up to and including the Reserved2 field in the Header Object).

### `cbOffsetWithinHeader` [in]

Offset, in bytes, of the first byte in the buffer relative to the beginning of the header.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The header is completely parsed and validated. |
| **MF_E_ASF_INVALIDDATA** | The input buffer does not contain valid ASF data. |
| **MF_E_BUFFERTOOSMALL** | The input buffer is too small. |
| **MF_S_ASF_PARSEINPROGRESS** | The method succeeded, but the header passed was incomplete. This is the successful return code for all calls but the last one when passing the header in pieces. |

## Remarks

If you pass the header in pieces, the ContentInfo object will keep references to the buffer objects until the entire header is parsed. Therefore, do not write over the buffers passed into this method.

The start of the Header object has the following layout in memory:

| Field Name | Size in bytes |
| --- | --- |
| Object ID | 16 |
| Object Size | 8 |
| Number of Header Objects | 4 |
| Reserved1 | 1 |
| Reserved2 | 1 |

The first call to **ParseHeader** reads everything up to and including Rerserved2, so it requires a minimum of 30 bytes. (Note that the [IMFASFContentInfo::GetHeaderSize](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-getheadersize) method reads only the Object ID and Object Size fields, so that method requires a minimum of 24 bytes.)

## See also

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[Initializing the ContentInfo Object of a New ASF File](https://learn.microsoft.com/windows/desktop/medfound/initializing-the-contentinfo-object-of-a-new-asf-file)
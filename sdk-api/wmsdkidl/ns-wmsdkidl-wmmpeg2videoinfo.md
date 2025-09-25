# WMMPEG2VIDEOINFO structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMMPEG2VIDEOINFO** structure describes an MPEG-2 video stream.

## Members

### `hdr`

[WMVIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmvideoinfoheader2) structure giving header information.

### `dwStartTimeCode`

25-bit group-of-pictures (GOP) time code at start of data. This field is not used for DVD.

### `cbSequenceHeader`

Length of the sequence header, in bytes. For DVD, set this field to zero. The sequence header is given in the **dwSequenceHeader** field.

### `dwProfile`

**AM_MPEG2Profile** enumeration type that specifies the MPEG-2 profile.

### `dwLevel`

**AM_MPEG2Level** enumeration type that specifies the MPEG-2 level.

### `dwFlags`

Flag indicating preferences. Flags are defined in Dvdmedia.h.

Set undefined bits to zero or the connection will be rejected.

### `dwSequenceHeader`

Address of a buffer that contains the sequence header, including quantization matrices and the sequence extension, if required. This field is typed as a **DWORD** array to preserve the 32-bit alignment.

## Remarks

This structure is identical to the **MPEG2VIDEOINFO** structure defined in Dvdmedia.h. For more information, see the DirectShow documentation in the DirectX SDK.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)
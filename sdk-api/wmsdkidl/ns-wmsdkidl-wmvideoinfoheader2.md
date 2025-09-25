# WMVIDEOINFOHEADER2 structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMVIDEOINFOHEADER2** structure describes the bitmap and color information for a video image, including [interlace](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary), copy protection, and aspect ratio.

## Members

### `rcSource`

**RECT** structure that specifies what part of the source stream should be used to fill the destination buffer. Renderers can use this field to ask the decoders to stretch or clip.

### `rcTarget`

**RECT** structure that specifies that specifies what part of the destination buffer should be used

### `dwBitRate`

Approximate data rate of the video stream, in bits per second.

### `dwBitErrorRate`

Data error rate of the video stream, in bits per second.

### `AvgTimePerFrame`

The video frame's average display time, in 100-nanosecond units.

### `dwInterlaceFlags`

Bit-wise combination of zero or more flags that describe interlacing behavior. The flags are defined in Dvdmedia.h in the DirectX SDK. Undefined bits must be set to zero or else the connection will be rejected.

### `dwCopyProtectFlags`

Flag set with the AMCOPYPROTECT_RestrictDuplication value (0x00000001) to indicate that the duplication of the stream should be restricted. Undefined bits must be set to zero or else the connection will be rejected.

### `dwPictAspectRatioX`

The X dimension of the video rectangle's aspect ratio. For example, 16 for a 16:9 rectangle.

### `dwPictAspectRatioY`

The Y dimension of the video rectangle's aspect ratio. For example, 9 for a 16:9 rectangle.

### `dwReserved1`

Reserved for future use. Must be zero. (Note: this is different from the corresponding member of the **VIDEOINFOHEADER2** structure used in DirectShow.

### `dwReserved2`

Reserved for future use. Must be zero.

### `bmiHeader`

**BITMAPINFOHEADER** structure that contains color and dimension information for the video image bitmap.

## Remarks

This structure is identical to the **VIDEOINFOHEADER2** structure defined in Dvdmedia.h. For more information, see the DirectShow documentation in the DirectX SDK.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)
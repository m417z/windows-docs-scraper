# WMVIDEOINFOHEADER structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMVIDEOINFOHEADER** structure describes the bitmap and color information for a video image.

## Members

### `rcSource`

**RECT** structure that specifies the source video window.

### `rcTarget`

**RECT** structure that specifies the destination video window.

### `dwBitRate`

**DWORD** containing the approximate bit rate, in bits per second.

### `dwBitErrorRate`

**DWORD** containing the error rate for this stream, in bits per second.

### `AvgTimePerFrame`

When writing an ASF file, this member specifies the desired average time per frame in 100-nanosecond units. When reading an ASF file, this member is always zero.

### `bmiHeader`

**BITMAPINFOHEADER** structure that contains color and dimension information for the video image bitmap. **BITMAPINFOHEADER** is a Windows GDI structure.

## Remarks

This structure is identical to the DirectShow **VIDEOINFOHEADER** structure.

For uncompressed video of 16 or fewer bits per pixel (bpp), additional information is required. You must specify bit fields for 16 bpp and palette information for 8 or fewer bpp video. To convey this information, allocate enough consecutive memory to hold the additional information and copy the data to the memory directly following this structure. When you specify the address and size of this structure in the [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type) structure for a stream, include the size of the palette or bit field data.
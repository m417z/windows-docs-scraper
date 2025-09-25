# VIDEOINFOHEADER2 structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VIDEOINFOHEADER2** structure describes the bitmap and color information for a video image, including interlace, copy protection, and pixel aspect ratio information.

## Members

### `rcSource`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies what part of the source stream should be used to fill the destination buffer. Renderers can use this field to ask the decoders to stretch or clip. For more information, see [Source and Target Rectangles in Video Renderers](https://learn.microsoft.com/windows/desktop/DirectShow/source-and-target-rectangles-in-video-renderers).

### `rcTarget`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies that specifies what part of the destination buffer should be used

### `dwBitRate`

The approximate data rate of the video stream, in bits per second.

### `dwBitErrorRate`

The data error rate of the video stream, in bits per second.

### `AvgTimePerFrame`

The video frame's average display time, in 100-nanosecond units. For more information, see the Remarks section for the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure.

### `dwInterlaceFlags`

Flags that specify how the video is interlaced. This member is a bit-wise combination of zero or more of the following flags. The flags in Group 2 are mutually exclusive, and so are the flags in Group 3. (The flags in Group 2 are not recommended.) The flags in Group 1 may be combined with each other, and with one flag each from Group 2 and Group 3. See the table at the bottom of this page for more information about flag combinations.

| Group 1 | Description |
| --- | --- |
| **AMINTERLACE_IsInterlaced** | The stream is interlaced. If this flag is absent, the video is progressive and the other bits are irrelevant. |
| **AMINTERLACE_1FieldPerSample** | Each media sample contains one field. If this flag is absent, each media sample contains two fields. |
| **AMINTERLACE_Field1First** | Field 1 is first. If this flag is absent, field 2 is first. (The top field in PAL is field 1, and the top field in NTSC is field 2.) |

| Group 2 | Description |
| --- | --- |
| **AMINTERLACE_FieldPatField1Only** | The stream never contains a field 2. |
| **AMINTERLACE_FieldPatField2Only** | The stream never contains a field 1. |
| **AMINTERLACE_FieldPatBothRegular** | There is one field 2 for every field 1. |
| **AMINTERLACE_FieldPatBothIrregular** | The stream contains an irregular pattern of field 1 and field 2. |

| Group 3 | Description |
| --- | --- |
| **AMINTERLACE_DisplayModeBobOnly** | Bob display mode only. |
| **AMINTERLACE_DisplayModeWeaveOnly** | Weave display mode only. |
| **AMINTERLACE_DisplayModeBobOrWeave** | Either bob or weave mode. |

Set undefined flags to zero, or the connection will be rejected.

### `dwCopyProtectFlags`

Flag set with the AMCOPYPROTECT_RestrictDuplication value (0x00000001) to indicate that the duplication of the stream should be restricted. If undefined, specify zero or else the connection will be rejected.

### `dwPictAspectRatioX`

The X dimension of picture aspect ratio. For example, 16 for a 16-inch x 9-inch display.

### `dwPictAspectRatioY`

The Y dimension of picture aspect ratio. For example, 9 for a 16-inch x 9-inch display.

### `dwControlFlags`

This field was originally named **dwReserved**, and was required to be zero. The field was renamed to **dwControlFlags**, and must contain a bitwise OR of zero or more of the following flags:

| Value | Meaning |
| --- | --- |
| **AMCONTROL_USED** | Indicates the dwControlFlags flags are used. |
| **AMCONTROL_PAD_TO_4x3** | The image should be padded and displayed in a 4 x 3 area. |
| **AMCONTROL_PAD_TO_16x9** | The image should be padded and displayed in a 16 x 9 area. |
| **AMCONTROL_COLORINFO_PRESENT** | Additional color information is contained in the upper 24 bits of the **dwControlFlags** field. |

The AMCONTROL_USED flag provides backward compatibility with older filters. If the AMCONTROL_USED flag is not set, the remaining bits in this field should be ignored. If a filter uses any of the other flags, it should set the AMCONTROL_USED flag.

The two AMCONTROL_PAD_xxx flags are used by decoders to determine the aspect ratio of the output rectangle. The source filter sets the AMCONTROL_USED flag and one of the padding flags and calls [QueryAccept](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryaccept) on the downstream pin. If the decoder rejects the type, the source filter should set the dwControlFlags field to zero. For more information on the use of these flags, see MPEG Decoder Preprocessing Transformations.

If the AMCONTROL_COLORINFO_PRESENT flag is set, it means the upper 24 bits of the dwControlFlags field are treated as a **DXVA_ExtendedFormat** structure. See Remarks for more information.

If this field contains any combination of flags that the filter does not support, the filter should reject the media type.

### `dwReserved1`

See description of **dwControlFlags**.

### `dwReserved2`

Reserved for future use. Must be zero.

### `bmiHeader`

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains color and dimension information for the video image bitmap.

When used inside a **VIDEOINFOHEADER2** structure, the semantics of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure differ slightly from how the structure is used in GDI. For more information, refer to the topic [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader).

## Remarks

The picture aspect ratio is given by **dwPictAspectRatioX** and **dwPictAspectRatioY**. These specify the intended shape of the video image when it is displayed. The pixel aspect ratio is calculated from the **rcSource** rectangle and the picture aspect ratio.

The **dwInterlaceFlags** field indicates whether the video is interlaced, and if so, the format of the fields within the media samples. The following table shows the valid interlace modes for the Overlay Mixer and Video Mixing Renderer filters.

| Display Mode | Interlace Flags | Description |
| --- | --- | --- |
| Progressive frames | None | The video stream is not interlaced. |
| Non-interleaved bob | AMINTERLACE_IsInterlaced |AMINTERLACE_1FieldPerSample |<br><br>AMINTERLACE_DisplayModeBobOnly | The entire video stream is interlaced, and each media sample contains a single video field. |
| Interleaved bob | AMINTERLACE_IsInterlaced |AMINTERLACE_DisplayModeBobOnly | The entire video stream is interlaced. Each media sample contains two video fields. Flags on the media sample indicate which field to display first. |
| Weave | AMINTERLACE_IsInterlaced |AMINTERLACE_FieldPatBothRegular |<br><br>AMINTERLACE_DisplayModeWeaveOnly | The video stream is interlaced, and each sample contains two video fields. The fields should not be deinterlaced. |
| Bob or weave | AMINTERLACE_IsInterlaced |AMINTERLACE_DisplayModeBobOrWeave | The video stream varies between progressive and interlaced content. Each media sample contains either a progressive frame or two video fields. Flags on the media sample indicate the correct way to display the contents. |

If the video is interlaced, the media samples may carry flags that describe the contents of the sample (such as field 1 or field 2), along with the rendering requirements. These are specified by setting the **dwTypeSpecificFlags** member of each media sample's [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure. The following table shows the valid media sample flags for each of the display modes listed in the previous table. To set these flags, call [IMediaSample2::SetProperties](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample2-setproperties) on the media sample.

| Display Mode | | Media Sample Properties |
| --- | --- | --- |
| Progressive frames | | None |
| Non-interleaved bob | | AM_VIDEO_FLAG_FIELD1 or AM_VIDEO_FLAG_FIELD2 |
| Interleaved bob | Field 1 first | AM_VIDEO_FLAG_FIELD1FIRST |
| Field 2 first | None |
| Weave | | AM_VIDEO_FLAG_WEAVE |
| Bob or weave | Bob, field 1 first | AM_VIDEO_FLAG_FIELD1FIRST |
| Bob, field 2 first | None |
| Weave | AM_VIDEO_FLAG_WEAVE |

Use the bit mask AMINTERLACE_FieldPatternMask to check the field pattern flags in **dwInterlaceFlags**:

```cpp

switch (dwInterlaceFlags & AMINTERLACE_FieldPatternMask)
{
case AMINTERLACE_FieldPatField1Only:
    // Stream never contains a Field 2.

case AMINTERLACE_FieldPatField2Only:
    // Stream never contains a Field 1.

case AMINTERLACE_FieldPatBothRegular:
    // One Field 2 for every Field 1.

case AMINTERLACE_FieldPatBothIrregular:
    // Random pattern of Field 1 and Field 2.
}

```

Use the bit mask AMINTERLACE_DisplayModeMask to check the display mode flags in **dwInterlaceFlags**:

```cpp

switch (dwInterlaceFlags & AMINTERLACE_DisplayModeMask)
{
case AMINTERLACE_DisplayModeBobOnly:
    // Bob display mode only.

case AMINTERLACE_DisplayModeWeaveOnly:
    // Weave display mode only.

case AMINTERLACE_DisplayModeBobOrWeave:
    // Either bob or weave mode.
}

```

Interlaced video samples must have valid time stamps. Otherwise, it is not guaranteed that the display driver can deinterlace the video. If you need to display an interlaced video frame with no time stamp, set the AM_VIDEO_FLAG_WEAVE flag on the sample as follows:

```cpp

IMediaSample2* pSample2 = NULL;
hr = pSample->QueryInterface(IID_IMediaSample2, (void**)&pSample2);
if (SUCCEEDED(hr))
{
    AM_SAMPLE2_PROPERTIES Prop;
    hr = pSample2->GetProperties(sizeof(Prop), (BYTE*)&Prop);
    if (SUCCEEDED(hr))
    {
        Prop.dwTypeSpecificFlags = AM_VIDEO_FLAG_WEAVE;
        hr = pSample2->SetProperties(sizeof(Prop), (BYTE*)&Prop);
    }
    pSample2->Release();
}

```

This causes the driver to display the two fields as one frame, using weave mode, without deinterlacing.

### Extended Color Information

If the AMCONTROL_COLORINFO_PRESENT flag is set in the **dwControlFlags** member, you can cast the **dwControlFlags** value to a **DXVA_ExtendedFormat** structure to access the extended color information, as shown in the following code.

```cpp

VIDEOINFOHEADER2 *pVIH2;
DXVA_ExtendedFormat& flags = (DXVA_ExtendedFormat&)pVIH2->dwControlFlags;

```

Ignore the **SampleFormat** member of the **DXVA_ExtendedFormat** structure, because it corresponds to the lower 8 bits of **dwControlFlags**, which are reserved for the AMCONTROL_xxx flags. The **DXVA_ExtendedFormat** structure is documented in the Windows DDK documentation.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types)
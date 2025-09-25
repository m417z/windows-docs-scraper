# DrawDibProfileDisplay function

## Description

The **DrawDibProfileDisplay** function determines settings for the display system when using DrawDib functions.

## Parameters

### `lpbi`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains bitmap information. You can also specify **NULL** to verify that the profile information is current. If the profile information is not current, DrawDib will rerun the profile tests to obtain a current set of information. When you call **DrawDibProfileDisplay** with this parameter set to **NULL**, the return value is meaningless.

## Return value

Returns a value that indicates the fastest drawing and stretching capabilities of the display system. This value can be zero if the bitmap format is not supported or one or more of the following values.

| Return code | Description |
| --- | --- |
| **PD_CAN_DRAW_DIB** | DrawDib can draw images using this format. Stretching might or might not also be supported. |
| **PD_CAN_STRETCHDIB** | DrawDib can stretch and draw images using this format. |
| **PD_STRETCHDIB_1_1_OK** | [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) draws unstretched images using this format faster than an alternative method. |
| **PD_STRETCHDIB_1_2_OK** | [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) draws stretched images (in a 1:2 ratio) using this format faster than an alternative method. |
| **PD_STRETCHDIB_1_N_OK** | [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) draws stretched images (in a 1:N ratio) using this format faster than an alternative method. |

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)
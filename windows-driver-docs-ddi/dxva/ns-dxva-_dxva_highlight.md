# _DXVA_Highlight structure

## Description

The DXVA_Highlight structure is sent by the host decoder to the accelerator to specify a highlighted rectangular area of a subpicture, and to create an alpha-blending surface with DCCMD data and a DPXD surface.

## Members

### `wHighlightActive`

Indicates whether a rectangular highlight area is active. Zero indicates inactive and 1 indicates active. If inactive, the highlight data must have no effect on the content of the blended picture.

### `wHighlightIndices`

Contains four palette indexes. Each palette index consists of 4 bits. Each 2-bit index in the highlighted rectangular area of the DXPD is used to select among these four palette indexes. The 4 most significant bits are for index 3, the next 4 bits are for index 2, the next 4 bits are for index 1, and the 4 least significant bits are for index 0.

### `wHighlightAlphas`

Contains four opacity values. Each opacity value consists of 4 bits. Each 2-bit index in the highlighted rectangular area of the DXPD is used to select among these four opacity values. The 4 most significant bits are for index 3, the next 4 bits are for index 2, the next 4 bits are for index 1, and the 4 least significant bits are for index 0.

These 4-bit opacity values are each referred to as a *SampleAlpha4* variable and are interpreted as follows:

* The value zero indicates that the graphic content at the corresponding location is transparent (so that the palette entry indexed by the corresponding bits of **wHighlightIndices** has no effect on the resulting blended picture). For a zero value, the blend specified is to use the video picture content without alteration.
* The value 15 indicates that the graphic content at the corresponding location is opaque (so that the palette entry indexed by the corresponding bits of **wHighlightIndices** completely determines the resulting blended picture).
* For nonzero values, the specified blend is found using the following expression:
* ( ( ( (*SampleAlpha4* + 1) x (graphic value) ) + ( ( (15 - *SampleAlpha4*) x (picture value) ) + 8 ) >> 4

### `HighlightRect`

Specifies a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the area of the highlight rectangle.

The following restrictions apply to the RECT dimensions:

* **left** and **top** must be greater than or equal to zero.
* **right** and **bottom** must be greater than **left** and **top**, respectively.
* **right** must not exceed 720, and **bottom** must not exceed 576.

## Remarks

The DXVA_Highlight structure is formulated in a manner compatible with the DVD video specification as specified by the DVD Forum.

**Note** There is a difference between the way the DVD specification defines a subpicture rectangular area and the convention used by Microsoft. This section follows the Microsoft convention so a rectangle of width 10 and height 10 in the upper-left corner of the picture is defined by **top** = 0, **left** = 0, **right** = 10, **bottom** = 10. The DVD specification defines **right** = 9 and **bottom** = 9.

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)
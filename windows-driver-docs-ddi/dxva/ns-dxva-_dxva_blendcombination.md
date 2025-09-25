# _DXVA_BlendCombination structure

## Description

The DXVA_BlendCombination structure is sent by the host decoder to the accelerator to specify how a blended picture is created from a source picture and a graphic image with accompanying alpha-blending information.

## Members

### `wPictureSourceIndex`

Specifies the uncompressed surface index, as defined by the contents of the DWORD pointed to by the **lpInputData** member of [DD_BEGINMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_beginmocompframedata) in a prior call to [DdMoCompBeginFrame](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe), of the picture to be combined with the graphic. This value is 0xFFFF if back-end hardware alpha blending is in use (when the **bConfigBlendType** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is 1).

### `wBlendedDestinationIndex`

Specifies the uncompressed surface index, as defined by the contents of the DWORD pointed to by the **lpInputData** member of DD_BEGINMOCOMPFRAMEDATA in a prior call to **DdMoCompBeginFrame**, of the combined picture to be created. This value is 0xFFFF if back-end hardware alpha blending is in use (when the **bConfigBlendType** member of DXVA_ConfigAlphaCombine is 1).

This value cannot be equal to **wPictureSourceIndex** unless back-end hardware alpha blending is in use.

### `PictureSourceRect16thPel`

Specifies the area of the source picture to be combined with the graphic image as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. Dimensions are specified in units of one-sixteenth of the distance between sample values of the luminance component. (In other words, the members in the RECT structure are fixed-point representations that have 28 bits before the binary point and 4 bits after the binary point.) This one-sixteenth sample accuracy allows **PictureSourceRect16thPel** to contain the same accuracy as the *frame_centre_horizontal_offset* and *frame_centre_vertical_offset* pan-scan variables in MPEG-2 video.

If the **bConfigPictureResizing** member of DXVA_ConfigAlphaCombine is zero, all dimensions in **PictureSourceRect16thPel** must be integer multiples of 16.

### `PictureDestinationRect`

Specifies the area of the destination picture as a RECT structure. This will contain the area defined for the source picture by **PictureSourceRect16thPel**.

If the **bConfigPictureResizing** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is zero, the area specified by **PictureDestinationRect** must have the same width and height as the area specified by **PictureSourceRect16thPel**. If **PictureDestinationRect** differs in size from **PictureSourceRect16thPel**, the resampling method to be applied is not specified, but must have a quality that is at least equivalent to that of bilinear resampling.

### `GraphicSourceRect`

Specifies the area of the source graphic image as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure. This area is combined with the part of the source picture specified by **PictureSourceRect16thPel** to create the alpha-blended picture.

### `GraphicDestinationRect`

Specifies the area of the destination graphic image as a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure.

If the **bConfigGraphicResizing** member of DXVA_ConfigAlphaCombine is zero, the destination picture must have the same width and height as the area specified by **GraphicSourceRect**. If **GraphicDestinationRect** differs in size from **GraphicSourceRect**, the resampling method to be applied to the graphic image is not specified. However, the resampling method used should have a quality that is at least equivalent to a bilinear resampling of an AYUV surface that represents the blending information.

### `wBlendDelay`

Specifies the number of milliseconds of delay prior to the blending combination going into effect. If back-end hardware blending is in use (for example, if the **bConfigBlendType** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is 1), **wBlendDelay** contains the number of milliseconds of delay prior to the blending combination going into effect. If front-end blending is in use, this member has no meaning and must be zero.

### `bBlendOn`

Specifies when a blending combination operation starts and stops. If back-end hardware blending is in use, blending is applied from the time specified in a blending combination operation (with **bBlendOn** equal to 1) until the execution time of a new blending combination (with **bBlendOn** equal to 1), or until the blending is disabled by a blending combination operation (with **bBlendOn** equal to zero). If back-end hardware blending is in use and **bBlendOn** is zero, the only other value in the alpha-blend combination buffer that has meaning is **wBlendDelay**. If front-end blending is in use, this member has no meaning and must be zero .

### `bWholePlaneAlpha`

Contains an opacity multiplier for the alpha channel of the graphic image. The value zero indicates that the graphic image is transparent (so that the graphic content has no effect on the resulting blended picture). The value 255 indicates that the graphic image uses its full sample opacity. If **bWholePlaneAlpha** is not equal to zero, the blend specified is to multiply the opacity of each location in the graphic content by (**bWholePlaneAlpha**+1)/256. For a zero value of **bWholePlaneAlpha**, the blend to use is the opacity specified in the graphic image without alteration. This must be equal to 255 if the **bConfigWholePlaneAlpha** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is zero.

### `OutsideYUVcolor`

Indicates whether areas outside of the **PictureDestinationRect** use a constant color for blending. If so, this member specifies that color constant. The **OutsideYUVcolor** member is defined as a [DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2) structure. See the **Remarks** section for more information.

## Remarks

In the event that the source and destination pictures are not in 4:4:4 format, every second sample of the graphic blending information (for example, the first, third, or fifth) is applied to the subsampled source chrominance information in the vertical or horizontal direction as needed to produce the blended result.

The following sections show the restrictions placed on the **left**, **right**, **top**, and **bottom** members of the RECT structure.

###

### RECT Structure Restrictions for PictureSourceRect16thPel

The following restrictions apply to the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) dimensions of **PictureSourceRect16thPel**:

* **left** and **top** must be greater than or equal to zero.
* **right** and **bottom** must be greater than or equal to **left** and **top**, respectively.
* If **right** is equal to **left** or **top** is equal to **bottom**, all the RECT members must have the value zero indicating that the source picture is not used. This case is allowed only if the **bConfigOnlyUsePicDestRectArea** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is zero.
* **right** and **bottom** must not exceed 16 times the allocated width and height, respectively, of the uncompressed source picture surface.

For example, if **PictureSourceRect16thPel** is used to select an entire MPEG-2 decoded picture, the **PictureSourceRect16thPel** values can be computed as follows:

* **left** = 0
* **top** = 0
* **right** = 16 X *horizontal_size*
* **bottom** = 16 X *vertical_size*

### RECT Structure Restrictions for PictureDestinationRect

The following restrictions apply to the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) dimensions for **PictureDestinationRect**:

* **left** and **top** must be greater than or equal to zero.
* **right** and **bottom** must be greater than or equal to **left** and **top**, respectively.
* If **right** is equal to **left** or **top** is equal to **bottom** (only allowed if the **bConfigOnlyUsePicDestRectArea** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) is zero), all of the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) members must have the value zero and **PictureSourceRect16thPel** must also specify all values having the value zero.
* If the **bConfigBlendType** member of DXVA_ConfigAlphaCombine is zero, **right** and **bottom** must not exceed the allocated width and height, respectively, of the uncompressed destination picture surface.
* If the **bConfigBlendType** member of DXVA_ConfigAlphaCombine is 1, **right** and **bottom** must not exceed the allocated width and height, respectively, of the source graphic surface.

### RECT Structure Restrictions for GraphicSourceRect

If alpha-blend data loading uses the **bConfigDataType** member of [DXVA_ConfigAlphaLoad](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphaload) with a value of 2, the following restrictions apply to the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) dimensions of **GraphicSourceRect**:

* **top** and **left** must be zero.
* **right** must be equal to the End X-coordinate minus the Start X-coordinate of the last preceding DVD SET_DAREA DCCMD, plus 1, to adjust for the differing rectangle interpretations as described in the following note in the RECT Structure Restrictions for **GraphicDestinationRect** section.
* **bottom** must be equal to the End Y-coordinate minus the Start Y-coordinate of the last preceding DVD SET_DAREA DCCMD, plus 1, to adjust for the differing rectangle interpretations.

If alpha-blend data loading does not use the **bConfigDataType** member of DXVA_ConfigAlphaLoad with a value of 2, the following restrictions apply to the RECT dimensions of **GraphicSourceRect**:

* **left** and **top** must be greater than or equal to zero.
* **right** and **bottom** must be greater than or equal to **left** and **top**, respectively.
* If **right** is equal to **left** or **top** is equal to **bottom**, all the RECT members must have the value zero, indicating no use of the graphic picture.
* **right** and **bottom** must not exceed the allocated width and height, respectively, of the graphic source image. The allocated width and height are defined as 720 and 576 samples, respectively, when the **bConfigDataType** member of DXVA_ConfigAlphaLoad equals 2.

### RECT Structure Restrictions for GraphicDestinationRect

The following restrictions apply to the [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) dimensions of **GraphicDestinationRect**:

* **left** and **top** must be greater than or equal to zero, unless this requirement conflicts with the need to offset the graphic by eight samples. This is the case in the following scenarios:
  + Alpha-blend data loading uses the **bConfigDataType** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) with a value of 2 and the **bConfigGraphicResizing** member of DXVA_ConfigAlphaCombine with a value of zero.
  + Operation is set for DVD 704-Wide Non-Pan-Scan (see [DVD 704-Wide Non-Pan-Scan Example](https://learn.microsoft.com/windows-hardware/drivers/display/dvd-704-wide-non-pan-scan-example)).
  + Operation is set for DVD 352-wide (see [DVD 352-Wide Example](https://learn.microsoft.com/windows-hardware/drivers/display/dvd-352-wide-example)).
* **right** and **bottom** must be greater than or equal to **left** and **top**, respectively. If **right** is equal to **left** or **top** is equal to **bottom**, then all these members of the RECT structure must have the value zero and **GraphicSourceRect** must also specify that all its members have the value zero.
* If the **bConfigBlendType** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) equals zero, **right** and **bottom** must not exceed the allocated width and height, respectively, of the uncompressed destination picture surface.
* If the **bConfigBlendType** member of DXVA_ConfigAlphaCombine equals 1, **right** and **bottom** must not exceed the allocated width and height, respectively, of the source graphic image.

If alpha-blend data loading uses the **bConfigDataType** member of DXVA_ConfigAlphaCombine with a value of 2 and the **bConfigGraphicResizing** member of DXVA_ConfigAlphaCombine with a value of zero, the following additional restrictions on **GraphicDestinationRect** dimensions apply:

* **top** must be equal to the Start Y-coordinate of the last preceding DVD SET_DAREA DCCMD.
* **left** must be equal to either the Start X-coordinate of the last preceding DVD SET_DAREA DCCMD or to that value minus 8. For more information, see [DVD 704-Wide Non-Pan-Scan Example](https://learn.microsoft.com/windows-hardware/drivers/display/dvd-704-wide-non-pan-scan-example) and [DVD 352-Wide Example](https://learn.microsoft.com/windows-hardware/drivers/display/dvd-352-wide-example).
* **right** must be equal to the value of **left**, plus the End X-coordinate minus the Start X-coordinate of the last preceding DVD SET_DAREA DCCMD, plus 1, to adjust for the differing rectangle interpretations described in the following note.
* **bottom** must be equal to the value of **top** plus the End Y-coordinate minus the Start Y-coordinate of the last preceding DVD SET_DAREA DCCMD, plus 1, to adjust for the differing rectangle interpretations described in the following note.

**Note** There is a difference between the way the DVD video specification defines a subpicture rectangular area and the convention used by Microsoft. This reference follows the Microsoft convention so a rectangle of width 10 and height 10 in the upper-left corner of the picture is defined by **top** = 0, **left** = 0, **right** = 10, and **bottom** = 10. The DVD video specification uses an equivalent of **right** = 9 and **bottom** = 9.

### Setting OutsideYUVcolor Values

The values for the **OutsideYUVcolor** structure are as follows:

* The value of **OutsideYUVcolor.bSampleAlpha8** must be 255 if the areas outside of the **PictureDestinationRect** are generated as a constant color to use for blending.
* The value of **OutsideYUVcolor.bSampleAlpha8** must be zero if either of the following two cases applies:
  + The areas outside of the **PictureDestinationRect** are unaffected by the blend.
  + The areas outside of the **PictureDestinationRect** cannot be used (as indicated by the **bConfigStayInPicDestRectArea** member of [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) having a value of 1).

All other values for **OutsideYUVcolor.bSampleAlpha8** are reserved for future use.

The value of **OutsideYUVcolor.bSampleAlpha8** must be zero if the **bConfigStayInPicDestRectArea** member of the DXVA_ConfigAlphaCombine structure equals 1.

If **OutsideYUVcolor.bSampleAlpha8** is zero, the only area of the destination surface that is affected by the blend is the part within the **PictureDestinationRect**.

If **OutsideYUVcolor.bSampleAlpha8** is 255, any area of the destination surface that is outside of **PictureDestinationRect** but within **GraphicDestinationRect**, is generated by blending the graphic with the color specified in the nonalpha members of **OutsideYUVcolor**. In this case, the entire allocated area of the destination surface that falls outside of both **PictureDestinationRect** and **GraphicDestinationRect** is set to the color specified in the nonalpha members of **OutsideYUVcolor**. If the **bConfigBlendType** member of the [DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine) structure is 1, the **OutsideYUVcolor** members are set to indicate blending with black by specifying **bSampleAlpha8** = 255, **bY_Value** = 16, and **bCbValue** = **bCrValue** = 128.

When the **bConfigBlendType** member of the DXVA_ConfigAlphaCombine structure is 1 (back-end hardware blend), blending operations may differ somewhat from those described in this reference. Some resizing parameters used to map a video picture from a source picture to a destination picture size may be applied in a modified manner to map the graphic image to its proper location relative to the source picture. However, the blended result will be equivalent to the blended result obtained by the alpha-blend combination commands in this reference.

## See also

[DD_BEGINMOCOMPFRAMEDATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_beginmocompframedata)

[DXVA_AYUVsample2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_ayuvsample2)

[DXVA_ConfigAlphaCombine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configalphacombine)

[DdMoCompBeginFrame](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)
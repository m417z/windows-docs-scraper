## Description

The **EmfPlusRecordType** enumeration identifies metafile record types used in Windows Metafile Format (WMF), Enhanced Metafile (EMF), and EMF+ files. The elements of the **EmfPlusRecordType** enumeration come in three groups.

* Elements in the first group have the prefix WmfRecordType and identity WMF records.
* Elements in the second group have the prefix EmfRecordType and identify EMF records.
* Elements in the third group have the prefix EmfPlusRecordType and identify EMF+ records.

WMF and EMF records can be displayed by Windows GDI+ and by Windows Graphics Device Interface (GDI). EMF+ records can be displayed by GDI+ but not by GDI.

Elements that have the WmfRecordType prefix are analogous to constants (defined in Wingdi.h) that have the prefix META_. For example, the element ****WmfRecordTypeSetBkColor**** is analogous to the constant META_SETBKCOLOR. For more information about WMF files, see [Windows-Format Metafiles](https://learn.microsoft.com/windows/desktop/gdi/windows-format-metafiles).

Elements that have the EmfRecordType prefix are analogous to constants (defined in Wingdi.h) that have the prefix EMR_. For example, the element ****EmfRecordTypePolygon**** is analogous to the constant EMR_POLYGON. For more information about EMR constants, see [EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr).

Elements that have the EmfPlusRecordType prefix are specific to GDI+. Most of those elements correspond to methods of the [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class. The remaining elements identify the header, the end of the file, and other sections of the metafile. The Constants section of this topic shows the correspondence between the EMF+ record types and the methods of the **Graphics** class.

## Constants

### `WmfRecordTypeSetBkColor`
TBD

### `WmfRecordTypeSetBkMode`
TBD

### `WmfRecordTypeSetMapMode`
TBD

### `WmfRecordTypeSetROP2`
TBD

### `WmfRecordTypeSetRelAbs`
TBD

### `WmfRecordTypeSetPolyFillMode`
TBD

### `WmfRecordTypeSetStretchBltMode`
TBD

### `WmfRecordTypeSetTextCharExtra`
TBD

### `WmfRecordTypeSetTextColor`
TBD

### `WmfRecordTypeSetTextJustification`
TBD

### `WmfRecordTypeSetWindowOrg`
TBD

### `WmfRecordTypeSetWindowExt`
TBD

### `WmfRecordTypeSetViewportOrg`
TBD

### `WmfRecordTypeSetViewportExt`
TBD

### `WmfRecordTypeOffsetWindowOrg`
TBD

### `WmfRecordTypeScaleWindowExt`
TBD

### `WmfRecordTypeOffsetViewportOrg`
TBD

### `WmfRecordTypeScaleViewportExt`
TBD

### `WmfRecordTypeLineTo`
TBD

### `WmfRecordTypeMoveTo`
TBD

### `WmfRecordTypeExcludeClipRect`
TBD

### `WmfRecordTypeIntersectClipRect`
TBD

### `WmfRecordTypeArc`
TBD

### `WmfRecordTypeEllipse`
TBD

### `WmfRecordTypeFloodFill`
TBD

### `WmfRecordTypePie`
TBD

### `WmfRecordTypeRectangle`
TBD

### `WmfRecordTypeRoundRect`
TBD

### `WmfRecordTypePatBlt`
TBD

### `WmfRecordTypeSaveDC`
TBD

### `WmfRecordTypeSetPixel`
TBD

### `WmfRecordTypeOffsetClipRgn`
TBD

### `WmfRecordTypeTextOut`
TBD

### `WmfRecordTypeBitBlt`
TBD

### `WmfRecordTypeStretchBlt`
TBD

### `WmfRecordTypePolygon`
TBD

### `WmfRecordTypePolyline`
TBD

### `WmfRecordTypeEscape`
TBD

### `WmfRecordTypeRestoreDC`
TBD

### `WmfRecordTypeFillRegion`
TBD

### `WmfRecordTypeFrameRegion`
TBD

### `WmfRecordTypeInvertRegion`
TBD

### `WmfRecordTypePaintRegion`
TBD

### `WmfRecordTypeSelectClipRegion`
TBD

### `WmfRecordTypeSelectObject`
TBD

### `WmfRecordTypeSetTextAlign`
TBD

### `WmfRecordTypeDrawText`
TBD

### `WmfRecordTypeChord`
TBD

### `WmfRecordTypeSetMapperFlags`
TBD

### `WmfRecordTypeExtTextOut`
TBD

### `WmfRecordTypeSetDIBToDev`
TBD

### `WmfRecordTypeSelectPalette`
TBD

### `WmfRecordTypeRealizePalette`
TBD

### `WmfRecordTypeAnimatePalette`
TBD

### `WmfRecordTypeSetPalEntries`
TBD

### `WmfRecordTypePolyPolygon`
TBD

### `WmfRecordTypeResizePalette`
TBD

### `WmfRecordTypeDIBBitBlt`
TBD

### `WmfRecordTypeDIBStretchBlt`
TBD

### `WmfRecordTypeDIBCreatePatternBrush`
TBD

### `WmfRecordTypeStretchDIB`
TBD

### `WmfRecordTypeExtFloodFill`
TBD

### `WmfRecordTypeSetLayout`
TBD

### `WmfRecordTypeResetDC`
TBD

### `WmfRecordTypeStartDoc`
TBD

### `WmfRecordTypeStartPage`
TBD

### `WmfRecordTypeEndPage`
TBD

### `WmfRecordTypeAbortDoc`
TBD

### `WmfRecordTypeEndDoc`
TBD

### `WmfRecordTypeDeleteObject`
TBD

### `WmfRecordTypeCreatePalette`
TBD

### `WmfRecordTypeCreateBrush`
TBD

### `WmfRecordTypeCreatePatternBrush`
TBD

### `WmfRecordTypeCreatePenIndirect`
TBD

### `WmfRecordTypeCreateFontIndirect`
TBD

### `WmfRecordTypeCreateBrushIndirect`
TBD

### `WmfRecordTypeCreateBitmapIndirect`
TBD

### `WmfRecordTypeCreateBitmap`
TBD

### `WmfRecordTypeCreateRegion`
TBD

### `EmfRecordTypeHeader:EMR_HEADER`
TBD

### `EmfRecordTypePolyBezier`
TBD

### `EmfRecordTypePolygon`
TBD

### `EmfRecordTypePolyline`
TBD

### `EmfRecordTypePolyBezierTo`
TBD

### `EmfRecordTypePolyLineTo`
TBD

### `EmfRecordTypePolyPolyline`
TBD

### `EmfRecordTypePolyPolygon`
TBD

### `EmfRecordTypeSetWindowExtEx`
TBD

### `EmfRecordTypeSetWindowOrgEx`
TBD

### `EmfRecordTypeSetViewportExtEx`
TBD

### `EmfRecordTypeSetViewportOrgEx`
TBD

### `EmfRecordTypeSetBrushOrgEx`
TBD

### `EmfRecordTypeEOF:EMR_EOF`
TBD

### `EmfRecordTypeSetPixelV`
TBD

### `EmfRecordTypeSetMapperFlags`
TBD

### `EmfRecordTypeSetMapMode`
TBD

### `EmfRecordTypeSetBkMode`
TBD

### `EmfRecordTypeSetPolyFillMode`
TBD

### `EmfRecordTypeSetROP2`
TBD

### `EmfRecordTypeSetStretchBltMode`
TBD

### `EmfRecordTypeSetTextAlign`
TBD

### `EmfRecordTypeSetColorAdjustment`
TBD

### `EmfRecordTypeSetTextColor`
TBD

### `EmfRecordTypeSetBkColor`
TBD

### `EmfRecordTypeOffsetClipRgn`
TBD

### `EmfRecordTypeMoveToEx`
TBD

### `EmfRecordTypeSetMetaRgn`
TBD

### `EmfRecordTypeExcludeClipRect`
TBD

### `EmfRecordTypeIntersectClipRect`
TBD

### `EmfRecordTypeScaleViewportExtEx`
TBD

### `EmfRecordTypeScaleWindowExtEx`
TBD

### `EmfRecordTypeSaveDC:EMR_SAVEDC`
TBD

### `EmfRecordTypeRestoreDC`
TBD

### `EmfRecordTypeSetWorldTransform`
TBD

### `EmfRecordTypeModifyWorldTransform`
TBD

### `EmfRecordTypeSelectObject`
TBD

### `EmfRecordTypeCreatePen`
TBD

### `EmfRecordTypeCreateBrushIndirect`
TBD

### `EmfRecordTypeDeleteObject`
TBD

### `EmfRecordTypeAngleArc`
TBD

### `EmfRecordTypeEllipse`
TBD

### `EmfRecordTypeRectangle`
TBD

### `EmfRecordTypeRoundRect`
TBD

### `EmfRecordTypeArc:EMR_ARC`
TBD

### `EmfRecordTypeChord:EMR_CHORD`
TBD

### `EmfRecordTypePie:EMR_PIE`
TBD

### `EmfRecordTypeSelectPalette`
TBD

### `EmfRecordTypeCreatePalette`
TBD

### `EmfRecordTypeSetPaletteEntries`
TBD

### `EmfRecordTypeResizePalette`
TBD

### `EmfRecordTypeRealizePalette`
TBD

### `EmfRecordTypeExtFloodFill`
TBD

### `EmfRecordTypeLineTo:EMR_LINETO`
TBD

### `EmfRecordTypeArcTo:EMR_ARCTO`
TBD

### `EmfRecordTypePolyDraw`
TBD

### `EmfRecordTypeSetArcDirection`
TBD

### `EmfRecordTypeSetMiterLimit`
TBD

### `EmfRecordTypeBeginPath`
TBD

### `EmfRecordTypeEndPath`
TBD

### `EmfRecordTypeCloseFigure`
TBD

### `EmfRecordTypeFillPath`
TBD

### `EmfRecordTypeStrokeAndFillPath`
TBD

### `EmfRecordTypeStrokePath`
TBD

### `EmfRecordTypeFlattenPath`
TBD

### `EmfRecordTypeWidenPath`
TBD

### `EmfRecordTypeSelectClipPath`
TBD

### `EmfRecordTypeAbortPath`
TBD

### `EmfRecordTypeReserved_069:69`
TBD

### `EmfRecordTypeGdiComment`
TBD

### `EmfRecordTypeFillRgn`
TBD

### `EmfRecordTypeFrameRgn`
TBD

### `EmfRecordTypeInvertRgn`
TBD

### `EmfRecordTypePaintRgn`
TBD

### `EmfRecordTypeExtSelectClipRgn`
TBD

### `EmfRecordTypeBitBlt:EMR_BITBLT`
TBD

### `EmfRecordTypeStretchBlt`
TBD

### `EmfRecordTypeMaskBlt`
TBD

### `EmfRecordTypePlgBlt:EMR_PLGBLT`
TBD

### `EmfRecordTypeSetDIBitsToDevice`
TBD

### `EmfRecordTypeStretchDIBits`
TBD

### `EmfRecordTypeExtCreateFontIndirect`
TBD

### `EmfRecordTypeExtTextOutA`
TBD

### `EmfRecordTypeExtTextOutW`
TBD

### `EmfRecordTypePolyBezier16`
TBD

### `EmfRecordTypePolygon16`
TBD

### `EmfRecordTypePolyline16`
TBD

### `EmfRecordTypePolyBezierTo16`
TBD

### `EmfRecordTypePolylineTo16`
TBD

### `EmfRecordTypePolyPolyline16`
TBD

### `EmfRecordTypePolyPolygon16`
TBD

### `EmfRecordTypePolyDraw16`
TBD

### `EmfRecordTypeCreateMonoBrush`
TBD

### `EmfRecordTypeCreateDIBPatternBrushPt`
TBD

### `EmfRecordTypeExtCreatePen`
TBD

### `EmfRecordTypePolyTextOutA`
TBD

### `EmfRecordTypePolyTextOutW`
TBD

### `EmfRecordTypeSetICMMode:98`
TBD

### `EmfRecordTypeCreateColorSpace:99`
TBD

### `EmfRecordTypeSetColorSpace:100`
TBD

### `EmfRecordTypeDeleteColorSpace:101`
TBD

### `EmfRecordTypeGLSRecord:102`
TBD

### `EmfRecordTypeGLSBoundedRecord:103`
TBD

### `EmfRecordTypePixelFormat:104`
TBD

### `EmfRecordTypeDrawEscape:105`
TBD

### `EmfRecordTypeExtEscape:106`
TBD

### `EmfRecordTypeStartDoc:107`
TBD

### `EmfRecordTypeSmallTextOut:108`
TBD

### `EmfRecordTypeForceUFIMapping:109`
TBD

### `EmfRecordTypeNamedEscape:110`
TBD

### `EmfRecordTypeColorCorrectPalette:111`
TBD

### `EmfRecordTypeSetICMProfileA:112`
TBD

### `EmfRecordTypeSetICMProfileW:113`
TBD

### `EmfRecordTypeAlphaBlend:114`
TBD

### `EmfRecordTypeSetLayout:115`
TBD

### `EmfRecordTypeTransparentBlt:116`
TBD

### `EmfRecordTypeReserved_117:117`
TBD

### `EmfRecordTypeGradientFill:118`
TBD

### `EmfRecordTypeSetLinkedUFIs:119`
TBD

### `EmfRecordTypeSetTextJustification:120`
TBD

### `EmfRecordTypeColorMatchToTargetW:121`
TBD

### `EmfRecordTypeCreateColorSpaceW:122`
TBD

### `EmfRecordTypeMax:122`
TBD

### `EmfRecordTypeMin:1`
TBD

### `EmfPlusRecordTypeInvalid`
TBD

### `EmfPlusRecordTypeHeader`

Identifies a record that is the EMF+ header.

### `EmfPlusRecordTypeEndOfFile`

Identifies a record that marks the last EMF+ record of a metafile.

### `EmfPlusRecordTypeComment`

[Graphics::AddMetafileComment](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-addmetafilecomment)

### `EmfPlusRecordTypeGetDC`

[Graphics::GetHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gethdc)

### `EmfPlusRecordTypeMultiFormatStart`

Identifies the start of a multiple-format block.

### `EmfPlusRecordTypeMultiFormatSection`

Identifies a section in a multiple-format block. Multiple-format records allow the same set of records to be represented in several formats.

### `EmfPlusRecordTypeMultiFormatEnd`

Identifies the end of a multiple-format block.

### `EmfPlusRecordTypeObject`
TBD

### `EmfPlusRecordTypeClear`

[Graphics::Clear](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-clear)

### `EmfPlusRecordTypeFillRects`

[FillRectangles Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangles(inconstbrush_inconstrect_inint))

### `EmfPlusRecordTypeDrawRects`

[DrawRectangles Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawrectangles(inconstpen_inconstrect_inint))

### `EmfPlusRecordTypeFillPolygon`

[FillPolygon Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpolygon(inconstbrush_inconstpointf_inint_infillmode))

### `EmfPlusRecordTypeDrawLines`

[DrawLines Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawlines(inconstpen_inconstpoint_inint))

### `EmfPlusRecordTypeFillEllipse`

[FillEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillellipse(inconstbrush_inconstrect_))

### `EmfPlusRecordTypeDrawEllipse`

[DrawEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawellipse(inconstpen_inconstrect_))

### `EmfPlusRecordTypeFillPie`

[FillPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpie(inconstbrush_inconstrect__inreal_inreal))

### `EmfPlusRecordTypeDrawPie`

[DrawPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpie(inconstpen_inconstrect__inreal_inreal))

### `EmfPlusRecordTypeDrawArc`

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

### `EmfPlusRecordTypeFillRegion`

[Graphics::FillRegion](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillregion)

### `EmfPlusRecordTypeFillPath`

[Graphics::FillPath](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpath)

### `EmfPlusRecordTypeDrawPath`

[Graphics::DrawPath](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpath)

### `EmfPlusRecordTypeFillClosedCurve`

[FillClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillclosedcurve(inconstbrush_inconstpointf_inint_infillmode_inreal))

### `EmfPlusRecordTypeDrawClosedCurve`

[DrawClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawclosedcurve(inconstpen_inconstpointf_inint_inreal))

### `EmfPlusRecordTypeDrawCurve`

[DrawCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawcurve(inconstpen_inconstpointf_inint_inint_inint_inreal))

### `EmfPlusRecordTypeDrawBeziers`

[DrawBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbeziers(inconstpen_inconstpoint_inint))

### `EmfPlusRecordTypeDrawImage`

[DrawImage Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(inimage_inconstpointf_inint)) (all methods that do not receive an array of destination points)

### `EmfPlusRecordTypeDrawImagePoints`

[DrawImage Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(inimage_inconstpointf_inint)) (all methods that receive an array of destination points)

### `EmfPlusRecordTypeDrawString`

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

### `EmfPlusRecordTypeSetRenderingOrigin`

[Graphics::SetRenderingOrigin](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setrenderingorigin)

### `EmfPlusRecordTypeSetAntiAliasMode`

[Graphics::SetSmoothingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setsmoothingmode)

### `EmfPlusRecordTypeSetTextRenderingHint`

[Graphics::SetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settextrenderinghint)

### `EmfPlusRecordTypeSetTextContrast`

[Graphics::SetTextContrast](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settextcontrast)

### `EmfPlusRecordTypeSetInterpolationMode`

[Graphics::SetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setinterpolationmode)

### `EmfPlusRecordTypeSetPixelOffsetMode`

[Graphics::SetPixelOffsetMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setpixeloffsetmode)

### `EmfPlusRecordTypeSetCompositingMode`

[Graphics::SetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingmode)

### `EmfPlusRecordTypeSetCompositingQuality`

[Graphics::SetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingquality)

### `EmfPlusRecordTypeSave`

[Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save)

### `EmfPlusRecordTypeRestore`

[Graphics::Restore](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-restore)

### `EmfPlusRecordTypeBeginContainer`

[Graphics::BeginContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-begincontainer(inconstrect__inconstrect__inunit))

### `EmfPlusRecordTypeBeginContainerNoParams`

[Graphics::BeginContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-begincontainer(inconstrect__inconstrect__inunit))

### `EmfPlusRecordTypeEndContainer`

[Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer)

### `EmfPlusRecordTypeSetWorldTransform`

[Graphics::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settransform)

### `EmfPlusRecordTypeResetWorldTransform`

[Graphics::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resettransform)

### `EmfPlusRecordTypeMultiplyWorldTransform`

[Graphics::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-multiplytransform)

### `EmfPlusRecordTypeTranslateWorldTransform`

[Graphics::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translatetransform)

### `EmfPlusRecordTypeScaleWorldTransform`

[Graphics::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-scaletransform)

### `EmfPlusRecordTypeRotateWorldTransform`

[Graphics::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-rotatetransform)

### `EmfPlusRecordTypeSetPageTransform`

[Graphics::SetPageScale](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setpagescale) and [Graphics::SetPageUnit](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setpageunit)

### `EmfPlusRecordTypeResetClip`

[Graphics::ResetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resetclip)

### `EmfPlusRecordTypeSetClipRect`

[Graphics::SetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstrect__incombinemode)) and [Graphics::SetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inconstrectf__incombinemode))

### `EmfPlusRecordTypeSetClipPath`

[Graphics::SetClip](https://learn.microsoft.com/previous-versions/ms535824(v=vs.85))

### `EmfPlusRecordTypeSetClipRegion`

[Graphics::SetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setclip(inhrgn_incombinemode))

### `EmfPlusRecordTypeOffsetClip`

[TranslateClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translateclip(inint_inint))

### `EmfPlusRecordTypeDrawDriverString`

[Graphics::DrawDriverString](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawdriverstring)

### `EmfPlusRecordTypeStrokeFillPath`
TBD

### `EmfPlusRecordTypeSerializableObject`
TBD

### `EmfPlusRecordTypeSetTSGraphics`
TBD

### `EmfPlusRecordTypeSetTSClip`
TBD

### `EmfPlusRecordTotal`
TBD

### `EmfPlusRecordTypeMax`
TBD

### `EmfPlusRecordTypeMin`
TBD
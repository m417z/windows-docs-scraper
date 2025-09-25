# IExtendPropertySheet2::GetWatermarks

## Description

The **IExtendPropertySheet2::GetWatermarks** method gets the watermark bitmap and header bitmap for wizard sheets implemented as Wizard 97-style wizards.

## Parameters

### `lpIDataObject` [in]

A pointer to the
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the object that contains context information about the scope or result item.

### `lphWatermark` [out]

A pointer to the handle to a bitmap that serves as the watermark for Wizard 97 pages. If the handle to the bitmap is **NULL**, no watermark is displayed for the wizard. If this value is not **NULL**, then the snap-in, for compatibility, should manage the lifetime of the watermark resource. The snap-in is responsible for freeing the watermark resource.

### `lphHeader` [out]

A pointer to the handle to a bitmap that serves as the header for Wizard 97 pages. If the handle to the bitmap is **NULL**, no bitmap will be displayed in the header for wizard pages. If this value is not **NULL**, then the snap-in, for compatibility, should manage the lifetime of the header resource. The snap-in is responsible for freeing the header resource.

### `lphPalette` [out]

A pointer to the handle to a palette that should be used for the bitmaps specified by lphWatermark and lphHeader. The palette is **NULL** by default. If a palette is not returned, the palette is **NULL**. If this value is not **NULL**, then the snap-in, for compatibility, should manage the lifetime of the palette resource. The snap-in is responsible for freeing the palette resource.

### `bStretch` [out]

A value that specifies whether the watermark and header bitmaps should be stretched — instead of tiled — to fit the background or header area of the property sheet. **TRUE** specifies that the watermark and header bitmaps should be stretched; **FALSE** specifies that the watermark and header bitmaps should maintain their size and be tiled. This parameter is **FALSE** by default. If a *bStretch* value is not returned, *bStretch* is **FALSE**.

## Return value

This method can return one of these values.

## Remarks

MMC calls this method only when:

1. The type parameter of
   [IPropertySheetProvider::CreatePropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-createpropertysheet) is set to **FALSE** (for wizard sheet) and that the *dwOptions* parameter is set to **MMC_PSO_NEWWIZARDTYPE** (for Wizard 97 style).
2. The snap-in passes a pointer to its
   [IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) or
   [IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) interface as the first parameter in calls to the
   [IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) method.

If the snap-in's implementation of this method returns a failure value (such as **E_NOTIMPL**), MMC reverts the wizard sheet requested by the snap-in in the call to [IPropertySheetProvider::CreatePropertySheet](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-createpropertysheet) to the non-Wizard 97 style. This is to maintain compatibility with MMC 1.1.

To prevent distortion of the image, it is recommended that the watermark and header bitmaps have the following dimensions (in pixels) with *bStretch* set to **FALSE**.

| Bitmap | Dimensions |
| --- | --- |
| *lphWatermark* | 164w x 628h |
| *lphHeader* | 49w x 49h |

## See also

[Adding Property Pages and Wizard Pages](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-property-pages-and-wizard-pages)

[Adding Wizard Pages: Implementation Details](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-wizard-pages-implementation-details)

[IExtendPropertySheet2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendpropertysheet2)
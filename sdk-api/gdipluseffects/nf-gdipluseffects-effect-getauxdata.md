# Effect::GetAuxData

## Description

The **Effect::GetAuxData** gets a pointer to a set of lookup tables created by a previous call to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Return value

This method returns a pointer to a set of lookup tables created by a previous call to [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)). If no lookup tables are available, the return value is **NULL**.

## Remarks

You can apply an effect to a bitmap by creating an instance of one of the descendants of the [Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect) class and passing the address of that descendant to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method. For certain descendants of **Effect**, ApplyEffect creates lookup tables and returns the address of those tables to the descendant object. For example, you can retrieve the lookup tables for a [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object as follows:

1. Create a [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object and call its [SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-brightnesscontrast-setparameters) method.
2. Pass **TRUE** to the [Effect::UseAuxData](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-effect-useauxdata) method of the [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object.
3. Pass the address of the [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.
4. Call the **Effect::GetAuxData** method of the [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object to obtain a pointer to the lookup tables created by [ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)). The buffer for the lookup tables is allocated by ApplyEffect; you are not responsible for freeing the buffer.

[ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) can return the address of lookup tables for the following descendants of the [Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect) class.

* [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast)
* [HueSaturationLightness](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-huesaturationlightness)
* [Levels](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-levels)
* [ColorBalance](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorbalance)
* [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve)

For the classes in the preceding list, [ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) creates four lookup tables: one each for the blue, green, red, and alpha channels. Each lookup table is an array of 256 bytes so the size of the entire set of tables is 1024 bytes. The tables are stored in the order blue, green, red, alpha.

#### Examples

The following code passes the address of a [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method. Then the code prints the blue-channel lookup table created by ApplyEffect.

```cpp
Bitmap bm(L"Picture.bmp");

BrightnessContrastParams briConParams;
briConParams.brightnessLevel = 0;
briConParams.contrastLevel = 25;

BrightnessContrast briCon;
briCon.SetParameters(&briConParams);
briCon.UseAuxData(TRUE);
	
bm.ApplyEffect(&briCon, NULL);

VOID* data = briCon.GetAuxData();

// You know the size is 1024, but check to make sure.
INT size = briCon.GetAuxDataSize();

if(1024 != size || NULL == data)
   return;

// Cast the data pointer as a ColorLUTParams pointer so that it
// will be easy to examine the individual tables.
ColorLUTParams* tables = (ColorLUTParams*)data;

// Print the lookup table for the blue channel.
for(UINT j = 0; j < 256; ++j)
{
   printf("%u, %u\n", j, tables->lutB[j]);
}
```

## See also

[ColorLUTParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorlutparams)

[Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect)

[Effect::GetAuxDataSize](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-effect-getauxdatasize)

[Effect::UseAuxData](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-effect-useauxdata)
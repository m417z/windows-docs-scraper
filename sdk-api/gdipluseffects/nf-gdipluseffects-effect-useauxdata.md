# Effect::UseAuxData

## Description

The **Effect::UseAuxData** method sets or clears a flag that specifies whether the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method should return a pointer to the auxiliary data that it creates.

## Parameters

### `useAuxDataFlag` [in]

Type: **const BOOL**

Set to **TRUE** to specify that [ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) should return a pointer to its auxiliary data; **FALSE** otherwise.

## See also

[Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect)

[Effect::GetAuxData](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-effect-getauxdata)

[Effect::GetAuxDataSize](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-effect-getauxdatasize)
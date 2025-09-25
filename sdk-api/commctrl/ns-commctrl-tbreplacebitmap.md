# TBREPLACEBITMAP structure

## Description

Used with the [TB_REPLACEBITMAP](https://learn.microsoft.com/windows/desktop/Controls/tb-replacebitmap) message to replace one toolbar bitmap with another.

## Members

### `hInstOld`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Module instance handle to the bitmap resource being replaced. Set this member to **NULL** to instead use a bitmap handle.

### `nIDOld`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If
**hInstOld** is **NULL**, set this member to the bitmap handle of the bitmap that is being replaced. Otherwise, set it to the resource identifier of the bitmap being replaced.

### `hInstNew`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Module instance handle that contains the new bitmap resource. Set this member to **NULL** to instead use a bitmap handle.

### `nIDNew`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If
**hInstNew** is **NULL**, set this member to the bitmap handle of the bitmap with the new button images. Otherwise, set it to the resource identifier of the bitmap with the new button images.

### `nButtons`

Type: **int**

Number of button images contained in the new bitmap. The number of new images should be the same as the number of replaced images.

## Remarks

If
**nIDNew** holds a bitmap handle, rather than a resource ID, do not destroy the bitmap until it has been replaced with [TB_REPLACEBITMAP](https://learn.microsoft.com/windows/desktop/Controls/tb-replacebitmap), or the toolbar is destroyed.
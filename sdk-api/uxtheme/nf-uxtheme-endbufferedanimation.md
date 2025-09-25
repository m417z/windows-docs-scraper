# EndBufferedAnimation function

## Description

Renders the first frame of a buffered animation operation and starts the animation timer.

## Parameters

### `hbpAnimation`

Type: **HANIMATIONBUFFER**

The handle to the buffered animation context that was returned by [BeginBufferedAnimation](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedanimation).

### `fUpdateTarget`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, updates the target DC with the animation. If **FALSE**, the animation is not started, the target DC is not updated, and the *hbpAnimation* parameter is freed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
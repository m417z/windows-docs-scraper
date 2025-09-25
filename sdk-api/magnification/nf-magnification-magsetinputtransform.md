# MagSetInputTransform function

## Description

Sets the current active input transformation for pen and touch input, represented as a source rectangle and a destination rectangle.

## Parameters

### `fEnabled` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

TRUE to enable input transformation, or FALSE to disable it.

### `pRectSource` [in]

Type: **const [LPRECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)**

 The new source rectangle, in unmagnified screen coordinates, that defines the area of the screen to magnify. This parameter is ignored if *bEnabled* is FALSE.

### `pRectDest` [in]

Type: **const [LPRECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)**

 The new destination rectangle, in unmagnified screen coordinates, that defines the area of the screen where the magnified screen content is displayed. Pen and touch input in this rectangle is mapped to the source rectangle. This parameter is ignored if *bEnabled* is FALSE.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

The input transformation maps the coordinate space of the magnified screen content to the actual (unmagnified) screen coordinate space. This enables the system to pass pen and touch input that is entered in magnified screen content, to the correct UI element on the screen. For example, without input transformation, input is passed to the element located at the unmagnified screen coordinates, not to the item that appears in the magnified screen content.

This function requires the calling process to have UIAccess privileges. If the caller does not have UIAccess privileges, the call to **MagSetInputTransform** fails, and the [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns ERROR_ACCESS_DENIED. For more information, see [UI Automation Security Considerations](https://learn.microsoft.com/windows/win32/WinAuto/uiauto-securityoverview) and [/MANIFESTUAC (Embeds UAC information in manifest)](https://learn.microsoft.com/cpp/build/reference/manifestuac-embeds-uac-information-in-manifest).

Beginning with Windows 10 Creators Update (version 1703), you must use the [MagSetInputTransform function](https://learn.microsoft.com/windows/win32/api/magnification/nf-magnification-magsetinputtransform) for mouse input to route to the magnified element (in addition to pen and touch input).

## Examples

The following example sets the input transformation for the full-screen magnifier.

```cpp
// Description:
//   Applies an input transformation to adjust pen and touch input to account
//   for the current magnification factor.
//
BOOL SetInputTranform()
{
    // Get the current magnification settings.
    float magLevel;
    int xOffset, yOffset;

    BOOL fResult = MagGetFullscreenTransform(&magLevel, &xOffset, &yOffset);
    if (fResult)
    {
        // Assume that pen or touch input occurs only in the primary monitor.
        RECT rcDest;
        rcDest.left   = 0;
        rcDest.top    = 0;
        rcDest.right  = GetSystemMetrics(SM_CXSCREEN);
        rcDest.bottom = GetSystemMetrics(SM_CYSCREEN);

        // Calculate the portion of the screen that is visible in the magnified
        // view.
        RECT rcSource;
        rcSource.left   = xOffset;
        rcSource.top    = yOffset;
        rcSource.right  = rcSource.left + (int)(rcDest.right / magLevel);
        rcSource.bottom = rcSource.top  + (int)(rcDest.bottom / magLevel);

        fResult = MagSetInputTransform(TRUE, &rcSource, &rcDest);
    }

    return fResult;
}

```

## See also

[MagGetFullscreenTransform](https://learn.microsoft.com/windows/win32/api/magnification/nf-magnification-maggetfullscreentransform)
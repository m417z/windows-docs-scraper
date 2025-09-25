# MagGetInputTransform function

## Description

Retrieves the current input transformation for pen and touch input, represented as a source rectangle and a destination rectangle.

## Parameters

### `pfEnabled` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

TRUE if input translation is enabled, or FALSE if not.

### `pRectSource` [out]

Type: **[LPRECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The source rectangle, in unmagnified screen coordinates, that defines the area of the screen that is magnified.

### `pRectDest` [out]

Type: **[LPRECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The destination rectangle, in screen coordinates, that defines the area of the screen where the magnified screen content is displayed. Pen and touch input in this rectangle is mapped to the source rectangle.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

The input transformation maps the coordinate space of the magnified screen content to the actual (unmagnified) screen coordinate space. This enables the system to pass touch and pen input that is entered in magnified screen content, to the correct UI element on the screen. For example, without input transformation, input is passed to the element located at the unmagnified screen coordinates, not to the item that appears in the magnified screen content.

#### Examples

The following example retrieves the current input translation settings.

```cpp
// Description:
//   Retrieves the current input transform.
//
BOOL GetInputTranform()
{
    BOOL fInputTransformEnabled;
    RECT rcSource;
    RECT rcTarget;

    BOOL fResult = MagGetInputTransform(&fInputTransformEnabled,
                                        &rcSource, &rcTarget);
    if (fResult)
    {
        //
        // Do something with the input transform data.
        //
    }

    return fResult;
}

```

## See also

[MagSetInputTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetinputtransform)
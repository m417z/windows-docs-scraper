# ITextFont::GetAnimation

## Description

Gets the animation type.

## Parameters

### `pValue`

Type: **long***

One of the following animation types.

[tomNoAnimation](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomLasVegasLights](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomBlinkingBackground](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomSparkleText](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMarchingBlackAnts](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomMarchingRedAnts](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomShimmer](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomWipeDown](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomWipeRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetAnimation](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setanimation)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)
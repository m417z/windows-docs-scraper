# ITextFont::SetAnimation

## Description

Sets the animation type.

## Parameters

### `Value` [in]

Type: **long**

The animation type. It can be one of the following values.

| Animation type | Value |
| --- | --- |
| **tomNoAnimation** | 0 |
| **tomLasVegasLights** | 1 |
| **tomBlinkingBackground** | 2 |
| **tomSparkleText** | 3 |
| **tomMarchingBlackAnts** | 4 |
| **tomMarchingRedAnts** | 5 |
| **tomShimmer** | 6 |
| **tomWipeDown** | 7 |
| **tomWipeRight** | 8 |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## See also

**Conceptual**

[GetAnimation](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getanimation)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)
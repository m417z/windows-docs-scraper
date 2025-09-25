# ITextFont::GetUnderline

## Description

Gets the type of underlining for the characters in a range.

## Parameters

### `pValue`

Type: **long***

The type of underlining. It can be one of the following values.

#### tomNone

#### tomSingle

#### tomWords

#### tomDouble

#### tomDotted

#### tomDash

#### tomDashDot

#### tomDashDotDot

#### tomWave

#### tomThick

#### tomHair

#### tomDoubleWave

#### tomHeavyWave

#### tomLongDash

#### tomThickDash

#### tomThickDashDot

#### tomThickDashDotDot

#### tomThickDotted

#### tomThickLongDash

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

[SetUnderline](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setunderline)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)
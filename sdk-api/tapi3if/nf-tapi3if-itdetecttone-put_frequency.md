# ITDetectTone::put_Frequency

## Description

The
**put_Frequency** method sets the frequency of the tone for which the TAPI Server should generate a tone event.

## Parameters

### `Index` [in]

Specifies the index of the tone to set.

### `lFrequency` [in]

Specifies the frequency, in hertz, of the tone. For more information, see the following Remarks section.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## Remarks

You can set up to three frequencies that make up the components of a tone. If fewer than three frequencies are required, specify a value of zero for the unused frequencies. A tone with all three frequencies set to zero is interpreted as silence and can be used for silence detection.

## See also

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[get_Frequency](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itdetecttone-get_frequency)
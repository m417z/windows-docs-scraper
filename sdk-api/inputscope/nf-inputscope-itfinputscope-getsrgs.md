# ITfInputScope::GetSRGS

## Description

Gets the Speech Recognition Grammar Specification (SRGS) string to be recognized.

## Parameters

### `pbstrSRGS` [out]

The xml string. The calling function must call **SysFreeString()** to free the buffer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

[http://www.w3.org/TR/speech-grammar](https://www.w3.org/tr/speech-grammar)
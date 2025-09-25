# ITfSpeechUIServer::UpdateBalloon

## Description

Sets the style and text of the speech balloon on the TSF language bar.

## Parameters

### `style` [in]

Contains a [TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle) element that specifies the balloon style.

### `pch` [in]

Pointer to a zero-terminated Unicode string that contains the text to show in the balloon.

### `cch` [in]

Specifies the number of characters in the string of the *pch* parameter.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfSpeechUIServer](https://learn.microsoft.com/windows/desktop/api/ctfspui/nn-ctfspui-itfspeechuiserver)

[TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle)
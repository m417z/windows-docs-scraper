# ITfSpeechUIServer::Initialize

## Description

Initializes the speech-related user interface elements on the TSF language bar.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The standard speech text service usually initializes the speech-related user interface on the TSF language bar. When a TSF-enabled application, that does not use the speech text service, requires use of the [ITfSpeechUIServer](https://learn.microsoft.com/windows/desktop/api/ctfspui/nn-ctfspui-itfspeechuiserver) interface, it initializes the user interface with this method.

## See also

[ITfSpeechUIServer](https://learn.microsoft.com/windows/desktop/api/ctfspui/nn-ctfspui-itfspeechuiserver)
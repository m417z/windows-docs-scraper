# ITfIntegratableCandidateListUIElement::SetIntegrationStyle

## Description

Sets the integration style.

## Parameters

### `guidIntegrationStyle` [in]

The desired type of keyboard integration experience.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The text service supports the integration style. |
| **E_NOTIMPL** | The text service does not support the integration style. |

## Remarks

If an app needs a keyboard-integrated experience, it can set a **GUID** for the desired type of
integration experience. If the text service supports the integration style, it should return **S_OK**.
If it's not supported, it should return **E_NOTIMPL**. When called, the text service may adjust its respond to
keyboard interaction for the lifetime of the [ITfCandidateListUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcandidatelistuielement) object, for example, until [ITfUIElementSink::EndUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfuielementsink-enduielement) is called.

## See also

[ITfIntegratableCandidateListUIElement](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfintegratablecandidatelistuielement)

[ITfUIElementSink::EndUIElement](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfuielementsink-enduielement)
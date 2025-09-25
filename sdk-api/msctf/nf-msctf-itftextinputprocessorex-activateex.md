# ITfTextInputProcessorEx::ActivateEx

## Description

The **ITfTextInputProcessorEx::ActivateEx** method activates a text service when a user session starts. If the text service implements **ITfTextInputProcessorEx** and **ActivateEx** is called, [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate) will not be called.

## Parameters

### `ptim` [in]

[in] Pointer to the ITfThreadMgr interface for the thread manager that owns the text service.

### `tid` [in]

[in] Specifies the client identifier for the text service.

### `dwFlags` [in]

[in] The combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_TMAE_SECUREMODE** | A text service is activated as secure mode. A text service may not want to show the setting dialog box. |
| **TF_TMAE_COMLESS** | A text service is activated as com less mode. TSF was activated without COM. COM may not be initialized or COM may be initialized as MTA. |
| **TF_TMAE_WOW16** | The current thread is 16 bit task. |
| **TF_TMAE_CONSOLE** | A text service is activated for console usage. |

## Return value

The TSF manager ignores the return value of this method.
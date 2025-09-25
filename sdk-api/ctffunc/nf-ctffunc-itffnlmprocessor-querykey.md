# ITfFnLMProcessor::QueryKey

## Description

Called to determine if the language model text service handles a key event.

## Parameters

### `fUp` [in]

Contains a **BOOL** that specifies if this is a key-down or a key-up event. Contains zero if this is a key-down event or nonzero otherwise.

### `vKey` [in]

Contains the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `lparamKeydata` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `pfInterested` [out]

Pointer to a **BOOL** that receives nonzero if the language model text service will handle the key event or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfFnLMProcessor](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnlmprocessor)

[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)

[WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
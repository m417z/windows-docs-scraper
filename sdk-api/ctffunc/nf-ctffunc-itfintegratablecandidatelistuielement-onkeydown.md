# ITfIntegratableCandidateListUIElement::OnKeyDown

## Description

Processes a key press.

## Parameters

### `wParam` [in]

Specifies the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `lParam` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `pfEaten` [out]

**TRUE** if the key event was handled; otherwise, **FALSE**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The [OnKeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextkeyeventsink-onkeydown) method enables an app to ask query the text service if it wants to process a given key in an integration style. The behavior of the **OnKeyDown** method can depend on the integration style. If the text service returns **pfEaten*=**TRUE**, then the app should do
no processing of the key. If **FALSE** is returned, the app can perform its own action in response to the key.

**GUID_INTEGRATIONSTYLE_SEARCHBOX** ({E6D1BD11-82F7-4903-AE21-1A6397CDE2EB}) enables an implementation of a keyboarding experience in which the user can move perceived keyboard focus
from the search box to the candidate list to search suggestions. The text service can process keys like **VK_UP** and **VK_DOWN** before Search handles them to change its internal state.

## See also

[ITfIntegratableCandidateListUIElement](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfintegratablecandidatelistuielement)
# IMenuBand::TranslateMenuMessage

## Description

Translates a message for a Component Object Model (COM) object.

## Parameters

### `pmsg` [in, out]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the incoming message.

### `plRet` [out]

Type: **LRESULT***

A pointer to the translated message.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The message was handled and should be deleted. |
| **S_FALSE** | The message was not handled. In this case, *plRet is **NULL**. |

## Remarks

Typically, [IMenuBand::IsMenuMessage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imenuband-ismenumessage) is called before this method. The parent window proc, not the message pump, must call **IMenuBand::TranslateMenuMessage** for every message.

This method can change the values of *pmsg*. If so, the changes should be forwarded on.

This method is required because some modal message pumps do not allow a call to a custom translation method.
# IMenuBand::IsMenuMessage

## Description

A message pump calls this method to see if any messages should be redirected to the Component Object Model (COM) object.

## Parameters

### `pmsg` [in]

Type: **[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | A message should be redirected to the COM object. The application should call [IMenuBand::TranslateMenuMessage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imenuband-translatemenumessage) with this message. |
| **E_FAIL** | The menu has exited the menu mode and can be destroyed. |

## Remarks

If this method returns **S_OK**, the message loop should not call [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) or [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage).
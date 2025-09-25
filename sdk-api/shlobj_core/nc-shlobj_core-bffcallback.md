# BFFCALLBACK callback function

## Description

The **BFFCallBack** function is an application-defined callback function that receives event notifications from the Active Directory Domain Services container browser dialog box. A pointer to this function is supplied to the container browser dialog box in the **pfnCallback** member of the [DSBROWSEINFO](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbrowseinfoa) structure when the [DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera) function is called. **BFFCallBack** is a placeholder for the application-defined function name.

## Parameters

### `hwnd` [in]

Contains the window handle of the browse dialog box. This handle is used to send messages to the browse dialog box using the [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage) function.

The container browser dialog box handles the following messages.

#### BFFM_ENABLEOK

This message enables or disables the **OK** command button in the dialog box.

The *wParam* of this message contains a Boolean value that, if zero, disables the **OK** command button. If the *wParam* is nonzero, the **OK** command button is enabled. By default, the **OK** command button is enabled.

The return value for this message is not used.

#### BFFM_SETSELECTION

This message selects an item in the dialog box.

The *lParam* of this message is a pointer to a **TCHAR** string that contains the ADsPath of the item to be selected. Even though there are ANSI and Unicode versions of this message, both versions take a pointer to a Unicode string.

The return value for this message is not used.

### `uMsg` [in]

Specifies one of the following browse messages.

#### BFFM_INITIALIZED

This notification is sent after the dialog box is initialized.

*lParam* is not used.

The return value from this notification is ignored.

#### BFFM_SELCHANGED

This notification is sent after the selection in the dialog box is changed.

*lParam* is a pointer to a Unicode string that contains the ADsPath of the newly selected item.

The return value from this notification is ignored.

#### DSBM_CHANGEIMAGESTATE

Reserved.

#### DSBM_CONTEXTMENU

This notification is sent when the dialog box receives a [WM_CONTEXTMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-contextmenu) message.

*lParam* is the *wParam* value passed with the [WM_CONTEXTMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-contextmenu) message.

The return value from this notification is ignored.

#### DSBM_HELP

This notification is sent when the dialog box receives a [WM_HELP](https://learn.microsoft.com/windows/desktop/shell/wm-help) message.

*lParam* is the *lParam* value passed with the [WM_HELP](https://learn.microsoft.com/windows/desktop/shell/wm-help) message.

The return value from this notification is ignored.

#### DSBM_QUERYINSERT

This notification is sent prior to each container object being inserted into the tree. The application can use this notification to modify the contents of the dialog box.

*lParam* is a pointer to a [DSBITEM](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbitema) structure that contains data about the item inserted. Some members of this structure, such as **szDisplayName**, can be modified during this notification to change the way items are displayed.

Return a nonzero value from this notification if data in the [DSBITEM](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbitema) structure changes. Return zero if the time should be inserted unchanged.

**Note** Only the Unicode version of this message, **DSBM_QUERYINSERTW**, is supported. **DSBM_QUERYINSERTA** is not supported.

### `lParam` [in]

The value and meaning of this parameter is determined by the notification received. For more information, see the notification message descriptions under the *uMsg* parameter.

### `lpData` [in]

Contains a pointer to the [DSBROWSEINFO](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbrowseinfoa) structure passed to the [DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera) function. This is true for all notification messages.

## Remarks

The **DSBM_*** message values are defined in Dsclient.h.

## See also

[DSBITEM](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbitema)

[DSBROWSEINFO](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsbrowseinfoa)

[DsBrowseForContainer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-dsbrowseforcontainera)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)

[WM_CONTEXTMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-contextmenu)

[WM_HELP](https://learn.microsoft.com/windows/desktop/shell/wm-help)
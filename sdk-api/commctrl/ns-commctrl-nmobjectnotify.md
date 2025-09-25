# NMOBJECTNOTIFY structure

## Description

Contains information used with the [TBN_GETOBJECT](https://learn.microsoft.com/windows/desktop/Controls/tbn-getobject), [TCN_GETOBJECT](https://learn.microsoft.com/windows/desktop/Controls/tcn-getobject), and [PSN_GETOBJECT](https://learn.microsoft.com/windows/desktop/Controls/psn-getobject) notification codes.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about this notification.

### `iItem`

Type: **int**

A control-specific item identifier. This value will comply to item identification standards for the control sending the notification. However, this member is not used with the [PSN_GETOBJECT](https://learn.microsoft.com/windows/desktop/Controls/psn-getobject) notification code.

### `piid`

Type: **IID***

A pointer to an interface identifier of the requested object.

### `pObject`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an object provided by the window processing the notification code. The application processing the notification code sets this member.

### `hResult`

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

COM success or failure flags. The application processing the notification code sets this member.

### `dwFlags`
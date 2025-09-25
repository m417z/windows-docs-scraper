# LPCQPAGEPROC callback function

## Description

The **CQPageProc** callback function is called by the query dialog box to notify the query form extension of events that occur in a query page. A pointer to this function is supplied to the query dialog box in the *pPageProc* member of the [CQPAGE](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqpage) structure. **CQPageProc** is a placeholder for the query form extension-defined function name.

## Parameters

### `pPage`

Pointer to a [CQPAGE](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqpage) structure that contains data about a query page.

### `hwnd`

Contains the window handle of the query page.

### `uMsg`

Contains a value that identifies the event that this function is called for. This can be one of the [Common Query Page Messages](https://learn.microsoft.com/windows/desktop/AD/messages-communicated-through-user-interfaces).

### `wParam`

Contains additional message data. The contents of this parameter depend on the value of the *uMsg* parameter.

### `lParam`

Contains additional message data. The content of this parameter depends on the value of the *uMsg* parameter.

## Return value

The return value is the result of the message and depends on the value of the *uMsg* parameter.

## See also

[CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc)

[CQPAGE](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqpage)

[Common Query Page Messages](https://learn.microsoft.com/windows/desktop/AD/messages-communicated-through-user-interfaces)

[IQueryForm::AddPages](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addpages)
# UiaEventCallback callback function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

A client-implemented function that is called by UI Automation when an event is raised that the client has subscribed to.

## Parameters

### `pArgs` [in]

Type: **[UiaEventArgs](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiaeventargs)***

The address of a [UiaEventArgs](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiaeventargs) structure that contains the event arguments.

### `pRequestedData` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

A [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) that contains data associated with the event.

### `pTreeStructure` [in]

Type: **BSTR**

A string that contains the structure of the tree associated with the event, if the event is associated with a set of nodes. See Remarks.

## Remarks

This function is passed to [UiaAddEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaaddevent) and [UiaRemoveEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaremoveevent).

The tree structure is described by a string where every character is either "p" or ")". The first character in the string always represents the root node. The string is **NULL** if no elements are returned by the function.

A "p" represents a node (UI Automation element). When one "p" directly follows another, the second node is a child of the first. A ")" represents a step back up the tree. For example, "pp)p" represents a node followed by two child nodes that are siblings of one another. In "pp))p", the last node is a sibling of the first one.
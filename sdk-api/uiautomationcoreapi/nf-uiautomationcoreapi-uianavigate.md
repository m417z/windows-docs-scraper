# UiaNavigate function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Navigates in the UI Automation tree, optionally retrieving cached information.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The element on which the navigation begins.

### `direction` [in]

Type: **[NavigateDirection](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-navigatedirection)**

A value from the [NavigateDirection](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-navigatedirection) enumerated type indicating the direction to navigate from *hnode*.

### `pCondition` [in]

Type: **[UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition)***

The address of a [UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition) structure that specifies the condition that the element being navigated to must match. Use this parameter to skip elements that are not of interest.

### `pRequest` [in]

Type: **[UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest)***

The address of a [UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest) structure that contains a description of the information to be cached.

### `ppRequestedData` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

The address of a variable that receives a pointer to a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) that contains the requested data. This parameter is passed uninitialized. See Remarks.

### `ppTreeStructure` [out]

Type: **BSTR***

The address of a variable that receives the description of the tree structure.
This parameter is passed uninitialized. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The tree structure is described by a string where every character is either "p" or ")".
The first character in the string always represents the root node.
The string is **NULL** if no elements are returned by the function.

A "p" represents a node
(UI Automation element). When one "p" directly follows another, the second node is a child of the first.
A ")" represents a step back up the tree. For example, "pp)p" represents a node followed
by two child nodes that are siblings of one another. In "pp))p", the last node is a sibling of the first one.
# UiaFind function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves one or more UI Automation nodes that match the search criteria.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The node to use as starting-point of the search.

### `pParams` [in]

Type: **[UiaFindParams](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiafindparams)***

The address of a [UiaFindParams](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiafindparams) structure that contains the search parameters.

### `pRequest` [in]

Type: **[UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest)***

The address of a [UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest) structure that specifies what information is to be cached.

### `ppRequestedData` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

The address of a variable that receives a pointer to a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) containing the requested data. This parameter is passed uninitialized. See Remarks.

### `ppOffsets` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

The address of a variable that receives a pointer to a SAFEARRAY containing the indexes to the requested data array for where the element subtree starts. This parameter is passed uninitialized.

### `ppTreeStructures` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

The address of a variable that receives a pointer to a SAFEARRAY containing the description of the tree structure. This parameter is passed uninitialized. See Remarks.

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
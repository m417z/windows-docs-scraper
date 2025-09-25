# UiaFindParams structure

## Description

**Note** This structure is deprecated.

Contains parameters used in the [UiaFind](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiafind) function.

## Members

### `MaxDepth`

Type: **int**

The maximum depth to which to search the tree for matching elements.

### `FindFirst`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to return only the first matching element; **FALSE** to return all matching elements.

### `ExcludeRoot`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to exclude the root element; otherwise **FALSE**.

### `pFindCondition`

Type: **[UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition)***

Pointer to a [UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition) structure that contains information about a condition that returned elements must match.
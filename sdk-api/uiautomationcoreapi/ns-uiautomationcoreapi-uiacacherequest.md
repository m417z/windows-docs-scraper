# UiaCacheRequest structure

## Description

**Note** This structure is deprecated.

Contains information about a request to cache data about UI Automation elements.

## Members

### `pViewCondition`

Type: **UiaCondition ***

The address of a [UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition) structure that specifies the condition that cached elements must match.

### `Scope`

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

A value from the [TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) enumerated type indicating the scope of the cache request; for example, whether it includes children of the root element.

### `pProperties`

Type: **PROPERTYID***

The address of an array of identifiers for properties to cache. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `cProperties`

Type: **int**

The count of elements in the **pProperties** array.

### `pPatterns`

Type: **PATTERNID***

The address of an array of identifiers for control patterns to cache. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `cPatterns`

Type: **int**

The count of elements in the **pPatterns** array.

### `automationElementMode`

Type: **[AutomationElementMode](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-automationelementmode)**

A value from the [AutomationElementMode](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-automationelementmode) enumerated type indicating the type of reference to cached UI Automation elements that is to be returned.
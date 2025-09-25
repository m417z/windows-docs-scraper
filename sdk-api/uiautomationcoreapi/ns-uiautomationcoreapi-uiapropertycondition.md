# UiaPropertyCondition structure

## Description

**Note** This structure is deprecated.

Contains information about a condition used to find UI Automation elements that have a matching property.

## Members

### `ConditionType`

Type: **[ConditionType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-conditiontype)**

A value indicating the type of the condition.

### `PropertyId`

Type: **PROPERTYID**

The identifier of the property to match. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `Value`

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The value that the property must have.

### `Flags`

Type: **[PropertyConditionFlags](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-propertyconditionflags)**

A value indicating how the condition is applied.
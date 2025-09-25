# UiaAndOrCondition structure

## Description

**Note** This structure is deprecated.

Contains information about a complex condition.

## Members

### `ConditionType`

Type: **[ConditionType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-conditiontype)**

A value from the [ConditionType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-conditiontype) enumerated type indicating the type of the condition.

### `ppConditions`

Type: **[UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition)****

The address of an array of pointers to [UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition) structures containing information about the complex condition.

### `cConditions`

Type: **int**

The count of elements in the **ppConditions** array.
# ConditionType enumeration

## Description

Contains values that specify a type of [UiaCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacondition).

## Constants

### `ConditionType_True:0`

A condition that is true.

### `ConditionType_False:1`

A condition that is false.

### `ConditionType_Property:2`

A property condition.

### `ConditionType_And:3`

A complex condition where all the contained conditions must be true.

### `ConditionType_Or:4`

A complex condition where at least one of the contained conditions must be true.

### `ConditionType_Not:5`

A condition that is true if the specified conditions are not met.
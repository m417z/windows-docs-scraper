# ExtKnownStruct structure

## Description

The **ExtKnownStruct** structure is used to specify how a target's structure can be formatted for output.

## Members

### `TypeName`

The name of the structure type.

### `Method`

The [ExtKnownStructMethod](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff543989(v=vs.85)) callback function that can be called to format an instance of the structure specified in **TypeName**.

### `SuppressesTypeName`

A Boolean flag that specifies whether the formatted output includes the name of the structure's type. If **FALSE**, the name is included in the formatted output; otherwise, the name is not included.

## See also

[ExtKnownStructMethod](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff543989(v=vs.85))
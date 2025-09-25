# DWRITE_BREAK_CONDITION enumeration

## Description

Indicates the condition at the edges of inline object or text used to determine line-breaking behavior.

## Constants

### `DWRITE_BREAK_CONDITION_NEUTRAL`

Indicates whether a break is allowed by determining the condition of the neighboring text span or inline object.

### `DWRITE_BREAK_CONDITION_CAN_BREAK`

Indicates that a line break is allowed, unless overruled by the condition of the
neighboring text span or inline object, either prohibited by a
"may not break" condition or forced by a "must break" condition.

### `DWRITE_BREAK_CONDITION_MAY_NOT_BREAK`

Indicates that there should be no line break, unless overruled by a "must break" condition from
the neighboring text span or inline object.

### `DWRITE_BREAK_CONDITION_MUST_BREAK`

Indicates that the line break must happen, regardless of the condition of the adjacent
text span or inline object.
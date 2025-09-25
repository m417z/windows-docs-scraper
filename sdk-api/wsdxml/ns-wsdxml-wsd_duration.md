# WSD_DURATION structure

## Description

Represents a length of time.

## Members

### `isPositive`

This parameter is **TRUE** if the entire duration is positive.

### `year`

The year value. This number is a value between 0 and max(ULONG).

### `month`

The month value. This number is a value between 0 and max(ULONG).

### `day`

The day value. This number is a value between 0 and max(ULONG).

### `hour`

The hour value. This number is a value between 0 and max(ULONG).

### `minute`

The minute value. This number is a value between 0 and max(ULONG).

### `second`

The second value. This number is a value between 0 and max(ULONG).

### `millisecond`

The millisecond value (0-999).

## Remarks

If any numeric member has a value of 0, then the member and its value is not included in the XML output when the structure is converted to XML.
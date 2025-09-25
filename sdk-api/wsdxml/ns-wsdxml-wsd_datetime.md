# WSD_DATETIME structure

## Description

Represents a timestamp.

## Members

### `isPositive`

**TRUE** if *year* value is positive.

### `year`

Year value (for example, 2005). This number is a value between 0 and max(ULONG).

### `month`

One-based month value (1 = January, through 12 = December).

### `day`

One-based day of the month value (1-31).

### `hour`

Zero-based hour value (0 through 23). *hour*=24 is only allowed if both *minute* and *second* are 0.

### `minute`

Zero-based minute value (0 through 59).

### `second`

Zero-based second value (0 through 59).

### `millisecond`

Millisecond value (0-999). When this structure is converted to XML, the millisecond value is expressed as a fraction of a second in decimal form. For example, if **millisecond** has a value of 9, then the XML output will be 0.009.

### `TZIsLocal`

**TRUE** if date and time are based on the local time zone, **FALSE** if UTC + offset.

### `TZIsPositive`

**TRUE** if time zone offset specified by *TZHour* and *TZMinute* is positive relative to UTC, **FALSE** if offset is negative. Not valid if *TZIsLocal* is **TRUE**.

### `TZHour`

Time zone offset relative to UTC (0-13). *TZhour*=14 is allowed if *TZMinute* is 0. Not valid if *TZIsLocal* is **TRUE**.

### `TZMinute`

Time zone offset relative to UTC (0-59). Not valid if *TZIsLocal* is **TRUE**.
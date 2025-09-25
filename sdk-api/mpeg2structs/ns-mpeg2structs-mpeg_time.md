# MPEG_TIME structure

## Description

The **MPEG_TIME** structure represents a time of day, or a duration.

## Members

### `Hours`

Specifies the hours. The value can range from 0 to 23, inclusive.

### `Minutes`

Specifies the minutes. The value can range from 0 to 59, inclusive.

### `Seconds`

Specifies the seconds. The value can range from 0 to 59, inclusive.

## Remarks

The **MPEG_DURATION** structure is a `typedef` for the **MPEG_TIME** structure.

```
typedef MPEG_TIME MPEG_DURATION;
```

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)
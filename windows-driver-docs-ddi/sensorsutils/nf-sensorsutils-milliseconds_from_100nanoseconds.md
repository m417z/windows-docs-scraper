# MILLISECONDS_FROM_100NANOSECONDS macro

## Description

This macro converts time in 100 nanosecond units, to milliseconds.

## Syntax

```cpp
#define MILLISECONDS_FROM_100NANOSECONDS(durationNanoS) ((durationNanoS) / (1000 * 10))
```

## Parameters

### `durationNanoS`

The duration in 100 nanosecond units to convert to milliseconds.

## Remarks

Gets a LONGLONG that represents a time length in milliseconds.

## See also

- [MILLISECONDS_TO_100NANOSECONDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-milliseconds_to_100nanoseconds)
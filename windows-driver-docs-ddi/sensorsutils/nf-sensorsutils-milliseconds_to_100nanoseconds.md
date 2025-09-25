# MILLISECONDS_TO_100NANOSECONDS macro

## Description

This macro converts time, in milliseconds, to 100 nanosecond units.

## Syntax

```cpp
#define MILLISECONDS_TO_100NANOSECONDS(durationMs) ((durationMs) * 1000 * 10)
```

## Parameters

### `durationMs`

The duration in milliseconds to convert to 100 nanosecond units.

## Remarks

Gets a ULONGLONG that represents a time length in nanoseconds.

## See also

- [MILLISECONDS_FROM_100NANOSECONDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-milliseconds_from_100nanoseconds)
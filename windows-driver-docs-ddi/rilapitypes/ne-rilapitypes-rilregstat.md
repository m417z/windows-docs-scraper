# RILREGSTAT enumeration (rilapitypes.h)

## Description

This topic supports the Windows driver infrastructure and is not intended to be used directly from your code.

## Constants

### `RIL_REGSTAT_UNKNOWN`

### `RIL_REGSTAT_UNREGISTERED`

### `RIL_REGSTAT_HOME`

### `RIL_REGSTAT_ATTEMPTING`

### `RIL_REGSTAT_DENIED`

### `RIL_REGSTAT_ROAMING`

### `RIL_REGSTAT_ROAMING_DOMESTIC`

### `RIL_REGSTAT_MAX`

## Syntax

```cpp
typedef enum _RILREGSTAT {
  RIL_REGSTAT_UNREGISTERED,
  RIL_REGSTAT_HOME,
  RIL_REGSTAT_ATTEMPTING,
  RIL_REGSTAT_DENIED,
  RIL_REGSTAT_ROAMING,
  RIL_REGSTAT_ROAMING_DOMESTIC,
  RIL_REGSTAT_MAX
} RILREGSTAT;
```
# SYSTEM_POWER_CONDITION enumeration

## Description

Used by the **GUID_ACDC_POWER_SOURCE** power event to indicate the current
power source.

## Constants

### `PoAc`

The computer is powered by an AC power source (or similar, such as a laptop powered by a 12V automotive
adapter).

### `PoDc`

The system is receiving power from built-in batteries.

### `PoHot`

The computer is powered by a short-term power source such as a UPS device.

### `PoConditionMaximum`

Values equal to or greater than this value indicate an out of range value.

## See also

[Power Management Enumeration Types](https://learn.microsoft.com/windows/desktop/Power/power-management-enumeration-types)
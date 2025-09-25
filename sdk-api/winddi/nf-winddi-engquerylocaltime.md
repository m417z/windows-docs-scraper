# EngQueryLocalTime function

## Description

The **EngQueryLocalTime** function queries the local time.

## Parameters

### `unnamedParam1` [out]

Pointer to an [ENG_TIME_FIELDS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-eng_time_fields) structure that receives the local time.

## Return value

None

## Remarks

**EngQueryLocalTime** returns the time at the current locale in the ENG_TIME_FIELDS structure.

## See also

[ENG_TIME_FIELDS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-eng_time_fields)
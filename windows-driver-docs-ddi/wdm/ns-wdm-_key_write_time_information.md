# _KEY_WRITE_TIME_INFORMATION structure

## Description

The **KEY_WRITE_TIME_INFORMATION** structure is used by the system to set the last write time for a registry key.

## Members

### `LastWriteTime`

Specifies the last time that the key was changed. This time value is expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

## See also

[KEY_SET_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_set_information_class)
# RT_PARAMETER_DATA structure (storport.h)

## Description

The **RT_PARAMETER_DATA** structure contains the parameter data for the report timestamp command.

## Members

### `ParameterDataLength`

Indicates the number of bytes that follow in the parameter data.

### `Origin`

Indicates the most recent event that initialized the returned device clock.

| Value | Meaning |
|--|--|
| 0 | Device clock initialized to zero at power on or as the result of a hard reset. |
| 1 | Reserved for future use. |
| 2 | Device clock initialized by the SET TIMESTAMP command. |
| 3 | Device clock initialized by an unknown method. |
| 4 to 7 | Reserved for future use. |

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

### `Timestamp`

Contains the current value of a device clock.

### `Reserved3`

Reserved for future use.

## See also

[**ST_PARAMETER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-st_parameter_data)
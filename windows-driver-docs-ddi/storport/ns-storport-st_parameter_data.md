# ST_PARAMETER_DATA structure (storport.h)

## Description

The **ST_PARAMETER_DATA** structure contains the parameter list for the set timestamp command.

## Members

### `Reserved1`

Reserved for future use.

### `Timestamp`

Specifies the value to which a device clock shall be initialized. The timestamp
should be the number of milliseconds that have elapsed since midnight, 1 January 1970 UT.

### `Reserved2`

Reserved for future use.

## See also

[**RT_PARAMETER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-rt_parameter_data)
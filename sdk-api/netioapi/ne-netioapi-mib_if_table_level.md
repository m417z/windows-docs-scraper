# MIB_IF_TABLE_LEVEL enumeration

## Description

The MIB_IF_TABLE_LEVEL enumeration type defines the level of interface information to
retrieve.

## Constants

### `MibIfTableNormal`

The values of statistics and state that are returned in members of the
[MIB_IF_ROW2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559214(v=vs.85)) structure in the
[MIB_IF_TABLE2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559224(v=vs.85)) structure that the
*Table* parameter points to in the
[GetIfTable2Ex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552528(v=vs.85)) function are returned from
the top of the filter stack.

### `MibIfTableRaw`

The values of statistics and state that are returned in members of the
[MIB_IF_ROW2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559214(v=vs.85)) structure in the
[MIB_IF_TABLE2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559224(v=vs.85)) structure that the
*Table* parameter points to in the
[GetIfTable2Ex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552528(v=vs.85)) function are returned
directly for the interface that is being queried.

### `MibIfTableNormalWithoutStatistics`

**Note** This value is available starting with Windows 10, version 1703.

The values returned are the same as for the **MibIfTableNormal**  value, but without the statistics.

## Remarks

The MIB_IF_TABLE_LEVEL enumeration type is used with the
[GetIfTable2Ex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552528(v=vs.85)) function to specify the level
of interface information to retrieve.

## See also

[GetIfTable2Ex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552528(v=vs.85))

[MIB_IF_ROW2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559214(v=vs.85))

[MIB_IF_TABLE2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff559224(v=vs.85))
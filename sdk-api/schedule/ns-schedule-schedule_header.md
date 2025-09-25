# SCHEDULE_HEADER structure

## Description

The **SCHEDULE_HEADER** structure is used to contain the replication schedule data for a replication source. The [SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule) structure contains an array of **SCHEDULE_HEADER** structures.

## Members

### `Type`

Contains one of the following values that defines the type of schedule data that is contained in this structure.

#### SCHEDULE_INTERVAL

The schedule contains a set of intervals. The **Offset** member contains the offset to an array of bytes with **SCHEDULE_DATA_ENTRIES** elements. Each byte in the array represents an hour of the week. The first hour is 00:00 on Sunday morning GMT.

Each bit of the lower four bits of each byte represents a 15 minute block within the hour that the source is available for replication. The following list lists the binary values and describes each bit of the lower four bits of the hour value.

| Binary value | Description |
| --- | --- |
| 1000 | The source is available for replication from 0 to 14 minutes after the hour. |
| 0100 | The source is available for replication from 15 to 29 minutes after the hour. |
| 0010 | The source is available for replication from 30 to 44 minutes after the hour. |
| 0001 | The source is available for replication from 45 to 59 minutes after the hour. |

These bits can be combined to create multiple 15 minute blocks that the source is available. For example, a binary value of 0111 indicates that the source is available from 0 to 44 minutes after the hour.

The upper fours bits of each byte are not used.

#### SCHEDULE_BANDWIDTH

Not supported.

#### SCHEDULE_PRIORITY

Not supported.

### `Offset`

Contains the offset, in bytes, from the beginning of the [SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule) structure to the data for this schedule. The size and form of this data depends on the schedule type defined by the **Type** member.

## See also

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[SCHEDULE](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule)
# SCHEDULE structure

## Description

The **SCHEDULE** structure is a variable-length structure used with the [DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda) and [DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya) functions to contain replication schedule data for a replication source.

## Members

### `Size`

Contains the size, in bytes, of the **SCHEDULE** structure, including the size of all of the elements and data of the **Schedules** array.

### `Bandwidth`

Not used.

### `NumberOfSchedules`

Contains the number of elements in the **Schedules** array.

### `Schedules`

Contains an array of [SCHEDULE_HEADER](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule_header) structures that contain the replication schedule data for the replication source. The **NumberOfSchedules** member contains the number of elements in this array. Currently, this array can only contain one element.

## See also

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[SCHEDULE_HEADER](https://learn.microsoft.com/windows/desktop/api/schedule/ns-schedule-schedule_header)
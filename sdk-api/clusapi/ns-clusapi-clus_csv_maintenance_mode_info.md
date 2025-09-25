# CLUS_CSV_MAINTENANCE_MODE_INFO structure

## Description

Used with the
[CLUSCTL_RESOURCE_SET_CSV_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-csv-maintenance-mode)
control code to enables or disables the maintenance mode on a cluster shared volume (CSV).

## Members

### `InMaintenance`

Specifies the maintenance mode for the CSV. **TRUE** enables maintenance mode,
**FALSE** disables it.

### `VolumeName`

The volume **GUID** path of the CSV.

## See also

[CLUSCTL_RESOURCE_SET_CSV_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-csv-maintenance-mode)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)
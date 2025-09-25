# CLUSTER_VALIDATE_CSV_FILENAME structure

## Description

Represents a cluster shared volume (CSV) during a validation operation.

## Members

### `szFileName`

A Unicode string that contains the volume name of the CSV. The string ends with a terminating null character. The name provided can be either the cluster-assigned friendly name or the volume **GUID** path of the form "\\?\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\".

## See also

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)
# CLUS_NETNAME_PWD_INFO structure

## Description

Provides information for resetting the security principal associated with a computer name.

## Members

### `Flags`

Indicates if other fields in the structure have valid data.

### `Password`

Contains the new password for the alternate computer name's associated security principal.

### `CreatingDC`

Contains the name of a directory server where the associated security principal object is stored. The total length includes the '\\' prefix.

### `ObjectGuid`

Contains the ID of a security principal object on a directory server.

## See also

[Failover Cluster Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-structures)
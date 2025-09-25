# ADS_REPLICAPOINTER structure

## Description

The **ADS_REPLICAPOINTER** structure represents an ADSI representation of the Replica Pointer attribute syntax.

## Members

### `ServerName`

The null-terminated Unicode string that contains the name of the name server that holds the replica.

### `ReplicaType`

Type of replica: master, secondary, or read-only.

### `ReplicaNumber`

Replica identification number.

### `Count`

The number of existing replicas.

### `ReplicaAddressHints`

A network address that is a likely reference to a node leading to the name server.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)
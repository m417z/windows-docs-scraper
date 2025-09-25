# RPC_IF_ID structure

## Description

The
**RPC_IF_ID** structure contains the interface UUID and major and minor version numbers of an interface.

## Members

### `Uuid`

Specifies the interface
[UUID](https://msdn.microsoft.com/).

### `VersMajor`

Major version number, an integer from 0 to 65535, inclusive.

### `VersMinor`

Minor version number, an integer from 0 to 65535, inclusive.

## Remarks

An interface identification is a subset of the data contained in the interface-specification structure. Routines that require an interface identification structure show a data type of
**RPC_IF_ID**. In those routines, the application is responsible for providing memory for the structure.

## See also

[RpcIfInqId](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcifinqid)
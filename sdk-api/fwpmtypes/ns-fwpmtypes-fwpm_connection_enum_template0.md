# FWPM_CONNECTION_ENUM_TEMPLATE0 structure

## Description

The **FWPM_CONNECTION_ENUM_TEMPLATE0** structure is used for limiting connection object enumerations.

## Members

### `connectionId`

Uniquely identifies a connection object.

### `flags`

| Value | Meaning |
| --- | --- |
| **FWPM_CONNECTION_ENUM_FLAG_QUERY_BYTES_TRANSFERRED**<br><br>0x00000001 | If set, the IPsec driver will be queried for the current bytes transferred via this connection (allowing monitoring tools to collect accurate data without requiring that querying capabilities remain constantly on). |
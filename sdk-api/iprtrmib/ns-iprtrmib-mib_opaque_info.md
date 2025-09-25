# MIB_OPAQUE_INFO structure

## Description

The
**MIB_OPAQUE_INFO** structure contains information returned from a MIB opaque query.

## Members

### `dwId`

The type of information returned.

### `ullAlign`

The number of bytes that align the information returned.

### `rgbyData`

A pointer to the information returned from the opaque query.

## See also

[MIB_OPAQUE_QUERY](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_opaque_query)
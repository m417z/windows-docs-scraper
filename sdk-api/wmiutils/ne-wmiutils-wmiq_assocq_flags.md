# WMIQ_ASSOCQ_FLAGS enumeration

## Description

Contains flags that indicate the features in a query.

## Constants

### `WMIQ_ASSOCQ_ASSOCIATORS:0x1`

Associators exist in the query.

### `WMIQ_ASSOCQ_REFERENCES:0x2`

References exist in the query.

### `WMIQ_ASSOCQ_RESULTCLASS:0x4`

A result class is specified in the query.

### `WMIQ_ASSOCQ_ASSOCCLASS:0x8`

An association class is specified in the query.

### `WMIQ_ASSOCQ_ROLE:0x10`

A role is specified in the query.

### `WMIQ_ASSOCQ_RESULTROLE:0x20`

A result role is specified in the query.

### `WMIQ_ASSOCQ_REQUIREDQUALIFIER:0x40`

Required qualifiers are specified in the query.

### `WMIQ_ASSOCQ_REQUIREDASSOCQUALIFIER:0x80`

Required association qualifiers are specified in the query.

### `WMIQ_ASSOCQ_CLASSDEFSONLY:0x100`

The query specifies class definitions only.

### `WMIQ_ASSOCQ_KEYSONLY:0x200`

The query contains the **KEYSONLY** keyword.

### `WMIQ_ASSOCQ_SCHEMAONLY:0x400`

The query returns only the schema.

### `WMIQ_ASSOCQ_CLASSREFSONLY:0x800`

The query returns only the class references.
# _NDIS_OBJECT_HEADER structure

## Description

The NDIS_OBJECT_HEADER structure packages the object type, version, and size information that is
required in many NDIS 6.0 structures.

## Members

### `Type`

The type of NDIS object that a structure describes. Use this member to identify the type of
structure in a memory dump.

### `Revision`

The revision number of the structure. Every NDIS structure that has an NDIS_OBJECT_HEADER member
has a revision number that applies to the NDIS structure exclusively. This allows NDIS drivers to
support multiple versions of the same structure. For example, a driver can check the
**Revision** member value at run time and use the appropriate version of the structure.

### `Size`

The total size, in bytes, of the NDIS object structure that includes the NDIS_OBJECT_HEADER
member. This size includes the size of the NDIS_OBJECT_HEADER member and the other members of the
structure.

## Remarks

The reference page for every structure, that has an NDIS_OBJECT_HEADER structure as a member, defines
values for the
**Type**,
**Revision**, and
**Size** members for that structure.
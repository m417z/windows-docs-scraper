# WcmNamespaceEnumerationFlags enumeration

## Description

Describes the types of enumeration flags.

## Constants

### `SharedEnumeration:1`

Describes a shared enumeration. It enumerates all namespaces that have been compiled for the machine space.

### `UserEnumeration:2`

Describes a user-specific enumeration. It enumerates the namespaces that have been compiled for a specific user.

### `AllEnumeration`

A logical "OR" of shared and user enumeration.

## Remarks

**Note** UserEnumeration should not be used. No namespaces are compiled for a particular user, they are all compiled for the machine as an entity.
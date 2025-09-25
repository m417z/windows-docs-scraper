# CENTRAL_ACCESS_POLICY_ENTRY structure

## Description

Represents a central access policy entry containing a list of security descriptors and staged security descriptors.

## Members

### `Name`

The name of the central access policy entry.

### `Description`

The description of the central access policy entry.

### `ChangeId`

An identifier that can be used to version the central access policy entry.

### `LengthAppliesTo`

The length of the buffer pointed to by the *AppliesTo* field.

### `AppliesTo`

A resource condition in binary form.

### `LengthSD`

The length of the buffer pointed to by the *SD* field.

### `SD`

A buffer of security descriptors associated with the entry.

### `LengthStagedSD`

The length of the buffer pointed to by the *StagedSD* field.

### `StagedSD`

A buffer of staged security descriptors associated with the entry.

### `Flags`

This field is reserved.
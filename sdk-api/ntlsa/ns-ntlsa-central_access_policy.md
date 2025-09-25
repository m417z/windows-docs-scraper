# CENTRAL_ACCESS_POLICY structure

## Description

Represents a central access policy that contains a set of central access policy entries.

## Members

### `CAPID`

The identifier of the central access policy.

### `Name`

The name of the central access policy.

### `Description`

The description of the central access policy.

### `ChangeId`

An identifier that can be used to version the central access policy.

### `Flags`

Reserved.

### `CAPECount`

The length of the buffer pointed to by the *CAPEs* field.

### `CAPEs`

Pointer to a buffer of [CENTRAL_ACCESS_POLICY_ENTRY](https://learn.microsoft.com/windows/desktop/api/ntlsa/ns-ntlsa-central_access_policy_entry) pointers.
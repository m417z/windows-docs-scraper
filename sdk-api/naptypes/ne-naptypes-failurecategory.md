# FailureCategory enumeration

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **FailureCategory** enumeration indicates the source of a failure.

## Constants

### `failureCategoryNone:0`

No failure.

### `failureCategoryOther:1`

A failure which is not due to client or server components or communications.

### `failureCategoryClientComponent:2`

Failure due to client component.

### `failureCategoryClientCommunication:3`

Failure due to client communication.

### `failureCategoryServerComponent:4`

Failure due to server component.

### `failureCategoryServerCommunication:5`

Failure due to server communication.

## See also

[FailureCategoryMapping](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-failurecategorymapping)
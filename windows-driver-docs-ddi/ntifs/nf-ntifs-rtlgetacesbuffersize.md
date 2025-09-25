## Description

**RtlGetAcesBufferSize** computes the size of the access control entries (ACEs) for the specified access control list (ACL).

## Parameters

### `Acl`

[in] Pointer to the ACL to be queried.

### `AcesBufferSize`

[out] Receives the size of the buffer used to store the ACEs in the ACL.

## Return value

**RtlGetAcesBufferSize** returns STATUS_SUCCESS upon success. It returns STATUS_INVALID_PARAMETER if **Acl** or **AcesBufferSize** are NULL.
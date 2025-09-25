# RtmGetOpaqueInformationPointer function

## Description

The
**RtmGetOpaqueInformationPointer** function returns a pointer to the opaque information field in a destination that is reserved for this client. The pointer enables the client to store client-specific information with the destination in the routing table.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination.

### `OpaqueInfoPointer` [out]

On input, *OpaqueInfoPointer* is a pointer to **NULL**.

On output, *OpaqueInfoPointer* receives a pointer to the opaque information pointer. If a client has not reserved an opaque pointer during registration, this parameter remains unchanged.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_NOT_FOUND** | No opaque pointer was reserved by the client. |

## Remarks

For sample code using this function, see
[Access the Opaque Pointer in a Destination](https://learn.microsoft.com/windows/desktop/RRAS/access-the-opaque-pointer-in-a-destination).

## See also

[RtmLockDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmlockdestination)
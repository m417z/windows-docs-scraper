# RtmGetEntityMethods function

## Description

The
**RtmGetEntityMethods** function queries the specified client to determine which methods are available for another client to invoke.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EntityHandle` [in]

Handle to the client for which to obtain methods.

### `NumMethods` [in, out]

On input, *NumMethods* specifies a valid pointer to a **UINT** value. Specify zero to return the number of methods available to be exported.

On output, *NumMethods* receives the number of methods exported by the client.

### `ExptMethods` [out]

Receives a pointer to an
[RTM_ENTITY_EXPORT_METHOD](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_entity_method) structure that contains the set of method identifiers requested by the calling client.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer supplied is not large enough to hold all the requested information. |

## Remarks

Do not call another client's method directly, always use
[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod). The routing table manager performs error checking when using
**RtmInvokeMethod** to ensure that the client is not unregistering or already unregistered.

If ERROR_INSUFFICIENT_BUFFER is returned, there may be some data in *ExptMethods*; *NumMethods* specifies how many methods actually fit in the buffer.

When the entity handle is no longer required, release it by calling
[RtmReleaseEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentities).

For sample code using this function, see
[Obtain and Call the Exported Methods for a Client](https://learn.microsoft.com/windows/desktop/RRAS/obtain-and-call-the-exported-methods-for-a-client).

## See also

[RtmBlockMethods](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmblockmethods)

[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod)
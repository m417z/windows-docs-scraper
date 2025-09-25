# PONLINE_ROUTINE callback function

## Description

Marks a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as available for use. The
**PONLINE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier for the resource to be made available.

### `EventHandle` [in, out]

On input, *EventHandle* is **NULL**. On output,
*EventHandle* contains a handle to a nonsignaled
[synchronization object](https://learn.microsoft.com/windows/desktop/Sync/synchronization-objects). The
[resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) can signal this handle at any time to report
a resource failure to the [Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor).
*EventHandle* can also be set to **NULL** on output, indicating
that the resource does not support asynchronous event notification.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful, and the resource is now [online](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly). |
| **ERROR_RESOURCE_NOT_AVAILABLE**<br><br>5006 (0x138E) | The resource was arbitrated with some other systems, and one of the other systems won the arbitration. Only [quorum-capable resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/q-gly) return this value. |
| **ERROR_IO_PENDING**<br><br>997 (0x3E5) | The request is pending, and a thread has been activated to process the online request. |

If the operation was not successful for other reasons,
*Online* should return one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the **Online** entry-point function returns an error code
other than **ERROR_IO_PENDING**, the Resource Monitor logs an event and calls
[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine).

Returning a valid *EventHandle* yields the following benefits:

* The Resource Monitor will not perform [LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plooks_alive_routine)
  polling. Avoiding this overhead is often useful, particularly when your DLL supports multiple resource
  instances.
* You can report resource failure at any time by signaling the handle. The Resource Monitor will immediately
  call [IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pis_alive_routine) to verify that the resource has failed.

For effective implementation strategies of the *Online*
entry-point function, see [Implementing Online](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-online).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)
# POFFLINE_ROUTINE callback function

## Description

Marks a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as unavailable for use after cleanup
processing is complete. The **POFFLINE_ROUTINE** type defines a pointer to
this function.

## Parameters

### `Resource` [in]

Resource identifier for the resource to be taken offline.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The request completed successfully, and the resource is offline. |
| **ERROR_IO_PENDING**<br><br>997 (0x3E5) | The request is still pending, and a thread has been activated to process the offline request. |

If the operation was not successful for other reasons,
*Offline* should return one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If *Offline* returns an error code other than
**ERROR_IO_PENDING**, the
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) logs an event and calls
[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine).

For effective implementation strategies of the *Offline*
entry-point function, see [Implementing Offline](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-offline).

#### Examples

See [Resource DLL Examples](https://learn.microsoft.com/previous-versions/aa372246(v=vs.85)).

## See also

[NetShareDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedel)

[Resource DLL Entry Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)
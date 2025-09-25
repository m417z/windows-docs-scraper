# CoIncrementMTAUsage function

## Description

Keeps MTA support active when no MTA threads are running.

## Parameters

### `pCookie` [out]

Address of a **PVOID** variable that receives the cookie for the [CoDecrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecrementmtausage) function, or **NULL** if the call fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **CoIncrementMTAUsage** function enables clients to create MTA workers and wait on them for completion before exiting the process.

The **CoIncrementMTAUsage** function ensures that the system doesn't free resources related to MTA support., even if the MTA thread count goes to 0.

On success, call the [CoDecrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecrementmtausage) once only. On failure, don't call the **CoDecrementMTAUsage** function.

Don't call **CoIncrementMTAUsage** during process shutdown or inside dllmain. You can call **CoIncrementMTAUsage** before the call to start the shutdown process.

You can call **CoIncrementMTAUsage** from one thread and [CoDecrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecrementmtausage) from another as long as a cookie previously returned by **CoIncrementMTAUsage** is passed to **CoDecrementMTAUsage**.

**CoIncrementMTAUsage** creates the MTA, if the MTA does not already exist. **CoIncrementMTAUsage** puts the current thread into the MTA, if the current thread is not already in an apartment

You can use **CoIncrementMTAUsage** when:

* You want a server to keep the MTA alive even when all worker threads are idle.
* Your API implementation requires COM to be initialized, but has no information about whether the current thread is already in an apartment, and does not need the current thread to go into a particular apartment.

## See also

[CoDecrementMTAUsage](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecrementmtausage)
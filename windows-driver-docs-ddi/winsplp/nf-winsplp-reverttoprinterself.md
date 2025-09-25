# RevertToPrinterSelf function

## Description

When `RevertToPrinterSelf` is called on an impersonating thread, it returns the token for the thread that is being impersonated.

## Return value

If the operation succeeds, the function returns the token of the impersonated thread. If the current thread is not impersonating another thread, this function returns **NULL**.

## Remarks

`RevertToPrinterSelf` should be called when a component needs access to resources from the local system context, such as the registry. The local system context is the security context (the collection of settings that define the security behavior of a process or thread) of the system process. The system process is the process that runs in the logon session that is created for the local system account when the operating system boots.

If `RevertToPrinterSelf` returns a non-**NULL** value, [ImpersonatePrinterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-impersonateprinterclient) must be called with the return value to complete the operation and clean up the thread handle.

## See also

[ImpersonatePrinterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-impersonateprinterclient)
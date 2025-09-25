# ImpersonatePrinterClient function

## Description

ImpersonatePrinterClient resumes impersonation of the client, completing the operation begun by [RevertToPrinterSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-reverttoprinterself).

## Parameters

### `hToken` [in]

Caller-supplied handle to a thread. This parameter must have been previously returned by a call to [RevertToPrinterSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-reverttoprinterself).

## Return value

If the operation succeeds, the function returns **TRUE**. Otherwise the function returns **FALSE**. The caller can obtain an error code by calling GetLastError (described in the Microsoft Windows SDK documentation).

## Remarks

This function must be called after a successful call to [RevertToPrinterSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-reverttoprinterself). It resumes impersonation of the client and cleans up the thread handle.

## See also

[RevertToPrinterSelf](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-reverttoprinterself)
# MFAllocateWorkQueue function

## Description

Creates a new work queue.

## Parameters

### `pdwWorkQueue` [out]

Receives an identifier for the work queue.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_FAIL** | The application exceeded the maximum number of work queues. |
| **MF_E_SHUTDOWN** | The application did not call [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup), or the application has already called [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown). |

## Remarks

When you are done using the work queue, call [MFUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockworkqueue).

## See also

[MFPutWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem)

[MFPutWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitemex)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)
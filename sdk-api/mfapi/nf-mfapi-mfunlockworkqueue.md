# MFUnlockWorkQueue function

## Description

Unlocks a work queue.

## Parameters

### `dwWorkQueue` [in]

Identifier for the work queue to be unlocked. The identifier is returned by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

The application must call **MFUnlockWorkQueue** once for every call to [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) and then once for every call to [MFLockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mflockworkqueue).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)
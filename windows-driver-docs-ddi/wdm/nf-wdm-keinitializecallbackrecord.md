## Description

The **KeInitializeCallbackRecord** macro initializes a [**KBUGCHECK_CALLBACK_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [**KBUGCHECK_REASON_CALLBACK_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure.

## Parameters

### `CallbackRecord` [in]

Pointer to either a **KBUGCHECK_CALLBACK_RECORD** or a **KBUGCHECK_REASON_CALLBACK_RECORD** structure. The structure must be in resident memory, such as nonpaged pool.

## Remarks
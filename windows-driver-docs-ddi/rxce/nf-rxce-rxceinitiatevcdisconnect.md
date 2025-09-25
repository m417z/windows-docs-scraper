# RxCeInitiateVCDisconnect function

## Description

**RxCeInitiateVCDisconnect** initiates a disconnect on the virtual circuit.

## Parameters

### `pVc` [in]

A pointer to the virtual circuit structure to be disconnected.

## Return value

**RxCeInitiateVCDisconnect** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | The *pVc* parameter passed to this routine was invalid. |

## Remarks

**RxCeInitiateVCDisconnect** must be called in the context of a system worker thread.

## See also

[RxCeBuildVC](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildvc)

[RxCeTearDownVC](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownvc)
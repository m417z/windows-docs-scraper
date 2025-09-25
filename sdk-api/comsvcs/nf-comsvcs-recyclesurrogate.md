# RecycleSurrogate function

## Description

Recycles the calling process.

For similar functionality, see [IMTxAS::RecycleSurrogate](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms679243(v=vs.85)).

## Parameters

### `lReasonCode` [in]

The reason code that explains why a process was recycled. The following codes are defined.

| Value | Meaning |
| --- | --- |
| **CRR_NO_REASON_SUPPLIED**<br><br>0x00000000 | The reason is not specified. |
| **CRR_LIFETIME_LIMIT**<br><br>xFFFFFFFF | The specified number of minutes that an application runs before recycling was reached. |
| **CRR_ACTIVATION_LIMIT**<br><br>0xFFFFFFFE | The specified number of activations was reached. |
| **CRR_CALL_LIMIT**<br><br>0xFFFFFFFD | The specified number of calls to configured objects in the application was reached. |
| **CRR_MEMORY_LIMIT**<br><br>0xFFFFFFFC | The specified memory usage that a process cannot exceed was reached. |
| **CRR_RECYCLED_FROM_UI**<br><br>xFFFFFFFB | An administrator decided to recycle the process through the Component Services administration tool. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2::RecycleApplicationInstances](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-recycleapplicationinstances)
## Description

Contains dynamic exception handling continuation targets. The [SetProcessDynamicEHContinuationTargets](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessdynamicehcontinuationtargets) function uses this structure.

## Members

### `TargetAddress`

The address of a dynamic exception handling continuation target.

### `Flags`

Flags that apply to the dynamic exception handling continuation target in *TargetAddress*.

| Value | Meaning |
| --- | --- |
| **DYNAMIC_EH_CONTINUATION_TARGET_ADD**<br><br>0x00000001UL | Dynamic exception handling continuation target should be added. If this flag is not set, the target is removed. This is an input flag. |
| **DYNAMIC_EH_CONTINUATION_TARGET_PROCESSED**<br><br>0x00000002UL | Dynamic exception handling continuation target has been successfully processed (either added or removed). This is an output flag used to report which targets were successfully processed when processing an array of multiple targets. |

## Remarks

## See also
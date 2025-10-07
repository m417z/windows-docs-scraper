# CounterCleanup function

Removes the provider's registration.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Remarks

Your provider calls this function. The function calls the [**PerfStopProvider**](https://learn.microsoft.com/windows/desktop/api/Perflib/nf-perflib-perfstopprovider) function to remove the provider's registration.

The [**CTRPP**](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp) tool generates this inline function when you specify the **-o** argument. The function's name includes a *prefix* string if you specify the **-prefix** argument (for example, ***prefix*CounterCleanup**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |


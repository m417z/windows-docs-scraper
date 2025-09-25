# ImmEnumInputContext function

## Description

Retrieves the input context for the specified thread.

## Parameters

### `idThread` [in]

Identifier for the thread. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Current thread. |
| **1** | Current process. |
| **Thread ID** | Identifier of the thread for which to enumerate the context. This thread identifier can belong to another process. |

### `lpfn` [in]

Pointer to the enumeration callback function. For more information, see [EnumInputContext](https://learn.microsoft.com/windows/desktop/api/imm/nc-imm-imcenumproc).

### `lParam` [in]

Application-supplied data. The function passes this data to the callback function.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

This function calls the application callback function for each enumerated input context, and passes the specified *lParam* value.

## See also

[EnumInputContext](https://learn.microsoft.com/windows/desktop/api/imm/nc-imm-imcenumproc)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)
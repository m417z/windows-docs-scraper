# _KBUGCHECK_DATA structure

## Description

The **KBUGCHECK_DATA** structure contains bug check parameters.

## Members

### `BugCheckDataSize`

The size, in bytes, of the **KBUGCHECK_DATA** structure. Callers of [AuxKlibGetBugCheckData](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetbugcheckdata) must supply this value.

### `BugCheckCode`

The bug check code. This value identifies that type of bug check that has occurred.

### `Parameter1`

Bug check parameter 1. For more information about this parameter, see specific [bug check codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

### `Parameter2`

Bug check parameter 2. For more information about this parameter, see specific [bug check codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

### `Parameter3`

Bug check parameter 3. For more information about this parameter, see specific [bug check codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

### `Parameter4`

Bug check parameter 4. For more information about this parameter, see specific [bug check codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

## Remarks

The **KBUGCHECK_DATA** structure is used as a parameter to [AuxKlibGetBugCheckData](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetbugcheckdata).

## See also

[AuxKlibGetBugCheckData](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetbugcheckdata)
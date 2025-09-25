# RECONVERTSTRING structure

## Description

Defines the strings for IME reconversion. It is the first item in a memory block that contains the strings for reconversion.

## Members

### `dwSize`

Size of this structure and the memory block it heads.

### `dwVersion`

Version number. Must be 0.

### `dwStrLen`

Length of the string that contains the composition string.

### `dwStrOffset`

Offset from the start position of this structure.

### `dwCompStrLen`

Length of the string that will be the composition string.

### `dwCompStrOffset`

Offset of the string that will be the composition string.

### `dwTargetStrLen`

Length of the string that is related to the target clause in the composition string.

### `dwTargetStrOffset`

Offset of the target string.

## Remarks

The **dwCompStrOffset** and **dwTargetOffset** members are the relative positions in **dwStrOffset**. For a Unicode IME, **dwStrLen**, **dwCompStrLen**, and **dwTargetStrLen** are TCHAR values, that is, character counts. The members **dwStrOffset**, **dwCompStrOffset**, and **dwTargetStrOffset** specify byte counts.

If an application starts the reconversion process by calling [ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa) with SCS_SETRECONVERTSTRING and SCS_QUERYRECONVERTSTRING, the application must allocate the necessary memory for the **RECONVERTSTRING** structure as well as the composition string buffer. IME should not use this memory later. If IME starts the process, IME should allocate necessary memory for the structure and the composition string buffer.

## See also

[IMR_CONFIRMRECONVERTSTRING](https://learn.microsoft.com/windows/desktop/Intl/imr-confirmreconvertstring)

[IMR_RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/Intl/imr-reconvertstring)

[ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)
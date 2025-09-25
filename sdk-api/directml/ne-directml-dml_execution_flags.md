## Description

Supplies options to DirectML to control execution of operators. These flags can be bitwise OR'd together to specify multiple flags at once.

## Constants

### `DML_EXECUTION_FLAG_NONE:0`

No execution flags are specified.

### `DML_EXECUTION_FLAG_ALLOW_HALF_PRECISION_COMPUTATION:0x1`

Allows DirectML to perform computation using half-precision floating-point (FP16), if supported by the hardware device.

### `DML_EXECUTION_FLAG_DISABLE_META_COMMANDS:0x2`

Forces DirectML execute the operator using DirectCompute instead of meta commands. DirectML uses meta commands by default, if available.

### `DML_EXECUTION_FLAG_DESCRIPTORS_VOLATILE:0x4`

Allows changes to bindings after an operator's execution has been recorded in a command list, but before it has been submitted to the command queue. By default, without this flag set, you must set all bindings on the binding table before you record an operator into a command list.

This flag allows you to perform late binding—that is, to set (or to change) bindings on operators that you've already recorded into a command list. However, this may result in a performance penalty on some hardware, as it prohibits drivers from promoting static descriptor accesses to root descriptor accesses.

For more info, see [DESCRIPTORS_VOLATILE](https://learn.microsoft.com/windows/win32/direct3d12/root-signature-version-1-1#descriptors_volatile).

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)
## Description

Specifies additional options in a tensor description. Values can be bitwise OR'd together.

## Constants

### `DML_TENSOR_FLAG_NONE:0x0`

No options are specified.

### `DML_TENSOR_FLAG_OWNED_BY_DML:0x1`

Indicates that the tensor data should be owned and managed by DirectML. The effect of this flag is that DirectML makes a copy of the tensor data during initialization of an operator, storing it in the persistent resource. This allows DirectML to perform reformatting of the tensor data into other, more efficient forms. Setting this flag may increase performance, but is typically only useful for tensors whose data doesn't change for the lifetime of the operator (for example, weight tensors).
This flag can only be used on input tensors.

When this flag is set on a particular tensor description, the corresponding tensor must be bound to the binding table during operator initialization, and not during execution. Attempting to bind the tensor during execution while this flag is set results in an error. This is the opposite of the default behavior (the behavior without the **DML_TENSOR_FLAG_OWNED_BY_DML** flag), where the tensor is expected to be bound during execution, and not during initialization.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)
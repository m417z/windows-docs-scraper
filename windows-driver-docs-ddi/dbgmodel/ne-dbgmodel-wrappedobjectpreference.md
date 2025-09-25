## Description
The **WrappedObjectPreference** enum indicates a preference for how the wrapper and the wrapped object should be treated.
## Constants
### `WrappedObjectNameResolution`
Indicates that the wrapped object should be used for name resolution and not interpreted to be a generalized proxy for the object. In essence, things like "." and "->" should work in an expression evaluator; however, other operations should not.
### `WrappedObjectGeneralProxy`
Indicates that the wrapper should be considered a general proxy for the wrapped object.
## Remarks
These enums serve to guide the handling of wrapper and wrapped objects, with two distinct modes available. These preferences can affect how functions and operations interact with these objects.

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)
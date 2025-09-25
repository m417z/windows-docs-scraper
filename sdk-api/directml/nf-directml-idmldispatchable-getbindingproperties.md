# IDMLDispatchable::GetBindingProperties

## Description

Retrieves the binding properties for a dispatchable object (an operator initializer, or a compiled operator). The binding properties
value contains the required size of the binding table in descriptors, as well as the required size in bytes of the
temporary and persistent resources required to execute this object.

When called on an operator initializer, the binding properties of the object may be different if retrieved both before and after a call
to [IDMLOperatorInitializer::Reset](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmloperatorinitializer-reset).

## Return value

Type: [**DML_BINDING_PROPERTIES**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_properties)

A [DML_BINDING_PROPERTIES](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_properties) value containing binding properties.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLDispatchable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldispatchable)
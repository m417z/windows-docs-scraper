# Location structure

## Description

Defines the location for an object. This particular variant of Location is the C-COM access struct.

Note that a location only has meaning in conjunction with a host context. It is a location within a context. When performing an operation on the location (reading bytes, writing bytes, etc...), a valid host context must be supplied.

## Members

### `HostDefined`

The HostDefined field has two states that are "Non-Opaque" at the API layer.

0: Indicates that the offset is a pointer into virtual address space of the target.

Non-Zero: The defined value is proprietary to the host. Clients can propagate and change offset. They cannot legally change the value.
This can be determined by the IsVirtualAddress() method if this structure is built from C++ code.

### `Offset`

The location’s offset into the address space defined by the host context and the HostDefined field of this structure. If the HostDefined field is zero, this is the virtual address of the location. If the HostDefined field is non-zero, this is the offset into some other address space. It may, for example, indicate where a particular field of a registered structure is located within the containing register.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)
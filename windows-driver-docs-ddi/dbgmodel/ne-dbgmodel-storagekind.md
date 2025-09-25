## Description
The **StorageKind** enum defines where a local is stored.
## Constants
### `StorageUnknown`
The storage location of the local is unknown.
### `StorageRegister`
The local is stored in a register.
### `StorageRegisterRelative`
The local is stored at an address relative to a register.
### `StorageRegisterRelativeIndirect`
The local is stored indirectly through a register-relative address.
## Remarks
This enums help to clarify the storage location of the local, providing information about how and where it is stored within the system.

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)
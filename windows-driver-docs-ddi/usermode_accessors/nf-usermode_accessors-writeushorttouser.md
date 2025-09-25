## Description

The **WriteUShortToUser** function safely writes a USHORT value to user-mode memory.

## Parameters

### `Destination`

[out] A pointer to the user-mode memory location where the USHORT value will be written.

### `Value`

[in] The USHORT value to write to the destination memory location.

## Remarks

This function provides a safe way to write a USHORT value to user-mode memory. It ensures the provided address is a user-mode address before writing to it.

This function doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the destination address isn't a user-mode address or is inaccessible.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**ReadUShortFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readushortfromuser)

[**WriteUShortToUserMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writeushorttomode)
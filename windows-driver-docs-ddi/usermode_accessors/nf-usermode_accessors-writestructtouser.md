## Description

The **WriteStructToUser** macro safely writes a structure to user-mode memory.

## Parameters

### `Destination`

[out] A pointer to the user-mode memory location where the structure will be written.

### `Source`

[in] A pointer to the structure to write to the destination memory location.

## Remarks

This macro provides a safe way to write a structure to user-mode memory. It ensures the provided address is a user-mode address before writing to it.

The macro validates that **Source** and **Destination** point to compatible types and automatically determines the structure size for the copy operation.

This macro doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the destination address isn't a user-mode address or is inaccessible.

This macro will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the macro is called or after the macro returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This macro works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the macro declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**ReadStructFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuser)

[**WriteStructToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomode)

[**WriteStructToUserHelper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtouserhelper)
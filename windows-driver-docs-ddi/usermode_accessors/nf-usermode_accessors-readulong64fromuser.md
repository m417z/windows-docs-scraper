## Description

The **ReadULong64FromUser** function safely reads a ULONG64 value from user-mode memory.

## Parameters

### `Source`

[in] A pointer to the user-mode memory location from which to read the ULONG64 value.

## Return value

**ReadULong64FromUser** returns the ULONG64 value read from the specified user-mode memory address.

## Remarks

This function provides a safe way to read a ULONG64 value from user-mode memory. It ensures the provided address is a user-mode address before reading it.

This function doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the source address isn't a user-mode address or is inaccessible.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**ReadULong64FromMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readulong64frommode)

[**WriteULong64ToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writeulong64touser)
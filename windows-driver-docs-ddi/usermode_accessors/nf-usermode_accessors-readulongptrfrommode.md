## Description

The **ReadULongPtrFromMode** function safely reads a ULONG_PTR value from memory based on the specified processor mode.

## Parameters

### `Source`

[in] A pointer to the memory location from which to read the ULONG_PTR value.

### `Mode`

[in] The processor mode that determines how the memory access is performed. **Mode** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KernelMode** | **Source** points to kernel-mode memory. The function performs a read from the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |
| **UserMode** | **Source** points to user-mode memory. The function raises an exception if **Source** doesn't point to user-mode memory; otherwise it performs a read from the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |

## Return value

**ReadULongPtrFromMode** returns the ULONG_PTR value read from the specified memory address.

## Remarks

This function provides a safe way to read a ULONG_PTR value from memory, with extra safety checks when accessing user-mode memory. It ensures that the provided address is valid and accessible based on the specified processor mode.

This function doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the source address is inaccessible or is invalid for the specified mode.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**ReadULongPtrFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readulongptrfromuser)

[**WriteULongPtrToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writeulongptrtomode)
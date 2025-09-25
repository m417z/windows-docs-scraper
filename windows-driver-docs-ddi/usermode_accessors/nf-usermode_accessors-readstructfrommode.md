## Description

The **ReadStructFromMode** macro safely reads a structure from memory based on the specified processor mode.

## Parameters

### `Destination`

[out] A pointer to the structure that receives the data read from memory.

### `Source`

[in] A pointer to the memory location from which to read the structure.

### `Mode`

[in] The processor mode that determines how the memory access is performed. **Mode** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KernelMode** | **Source** points to kernel-mode memory. The macro performs a read from the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |
| **UserMode** | **Source** points to user-mode memory. The macro raises an exception if **Source** doesn't point to user-mode memory; otherwise it performs a read from the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |

## Remarks

This macro provides a safe way to read a structure from memory, with extra safety checks when accessing user-mode memory. It ensures that the provided address is valid and accessible based on the specified processor mode.

The macro validates that **Source** and **Destination** point to compatible types and automatically determines the structure size for the copy operation.

This macro doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the source address isn't valid or is inaccessible for the specified processor mode.

This macro will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the macro is called or after the macro returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This macro works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the macro declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**ReadStructFromModeHelper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfrommodehelper)

[**ReadStructFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuser)

[**WriteStructToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomode)
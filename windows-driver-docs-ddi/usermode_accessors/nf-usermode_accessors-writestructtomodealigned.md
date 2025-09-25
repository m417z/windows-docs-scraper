## Description

The **WriteStructToModeAligned** macro safely writes a structure to memory based on the specified processor mode with alignment validation.

## Parameters

### `Destination`

[out] A pointer to the memory location where the structure will be written.

### `Source`

[in] A pointer to the structure to write to the destination memory location.

### `Mode`

[in] The processor mode that determines how the memory access is performed. **Mode** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KernelMode** | **Destination** points to kernel-mode memory. The macro performs a write to the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |
| **UserMode** | **Destination** points to user-mode memory. The macro raises an exception if **Destination** doesn't point to user-mode memory; otherwise it performs a write to the specified address with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum). See Remarks for more details. |

### `Alignment`

[in] The required alignment for the destination address, in bytes.

## Remarks

This macro provides a safe way to write a structure to memory, with extra safety checks when accessing user-mode memory and alignment enforcement. It ensures that the provided address is valid and accessible based on the specified processor mode, and meets the specified alignment requirements when accessing user-mode memory.

The macro validates that **Source** and **Destination** point to compatible types and automatically determines the structure size for the copy operation.

This macro enforces alignment by verifying that the destination address meets the specified alignment requirement when accessing user-mode memory. This helps prevent performance penalties and potential hardware faults that can occur when accessing misaligned data structures.

It raises a structured exception if the memory access fails, such as when the destination address isn't valid or is inaccessible for the specified processor mode, or doesn't meet the alignment requirements.

This macro will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the macro is called or after the macro returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This macro works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the macro declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**WriteStructToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomode)

[**WriteStructToUserAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtouseraligned)

[**WriteStructToModeHelper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomodehelper)

[**ReadStructFromModeAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfrommodealigned)
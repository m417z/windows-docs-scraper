## Description

The **CopyFromUserNonTemporal** function safely copies data from user-mode memory to kernel memory using non-temporal instructions.

## Parameters

### `Destination`

[out] A pointer to the kernel memory location where the data will be copied.

### `Source`

[in] A pointer to the user-mode memory location from which to copy the data.

### `Length`

[in] The number of bytes to copy.

## Remarks

This function provides a safe way to copy data from user-mode memory to kernel memory using non-temporal (streaming) instructions. This allows for flexible memory operations when kernel-mode code needs to retrieve data from user-mode buffers while optimizing cache performance for large data transfers.

The function has the following properties:

* The function performs a volatile copy using [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum) with non-temporal instructions.

* The function isn't recognized as a compiler intrinsic so the compiler will never optimize away the call (either entirely or replace the call with an equivalent sequence of instructions).

* When the call returns, the data has been copied from **Source** to **Destination**. This function's memory accesses to the **Source** and **Destination** will only be performed within the function (for example, the compiler can't move memory accesses out of this function).

* The function might perform unaligned memory accesses if the platform allows for it.

* The function might access memory locations more than once as part of its copy operation.

* The function doesn't support copy operations when **Source** and **Destination** overlap each other.

* The function uses non-temporal instructions that can improve performance for large data transfers by bypassing the processor cache, reducing cache pollution.

The function raises a structured exception if the copy operation fails, such as when the source address is not a valid user-mode address or is inaccessible.

This function is particularly useful when copying large amounts of data that are unlikely to be accessed again soon, as it avoids evicting other useful data from the cache.

If you are copying from a fixed-sized structure, you should use [**ReadStructFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuser) instead to avoid the risk of passing the wrong size.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**CopyFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfromuser)

[**CopyFromModeNonTemporal**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfrommodenontemporal)

[**CopyToUserNonTemporal**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytousernontemporal)
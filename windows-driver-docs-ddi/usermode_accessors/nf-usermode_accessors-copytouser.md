## Description

The **CopyToUser** function safely copies data from kernel memory to user-mode memory.

## Parameters

### `Destination`

[out] A pointer to the user-mode memory location where the data will be copied.

### `Source`

[in] A pointer to the kernel memory location from which to copy the data.

### `Length`

[in] The number of bytes to copy.

## Remarks

This function provides a safe way to copy data from kernel memory to user-mode memory. This allows for flexible memory operations when kernel-mode code needs to transfer data to user-mode buffers.

The function has the following properties:

* The function performs a volatile copy using [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

* The function isn't recognized as a compiler intrinsic so the compiler will never optimize away the call (either entirely or replace the call with an equivalent sequence of instructions).

* When the call returns, the data has been copied from **Source** to **Destination**. This function's memory accesses to the **Source** and **Destination** will only be performed within the function (for example, the compiler can't move memory accesses out of this function).

* The function might perform unaligned memory accesses if the platform allows for it.

* The function might access memory locations more than once as part of its copy operation.

* The function doesn't support copy operations when **Source** and **Destination** overlap each other.

The function raises a structured exception if the copy operation fails, such as when the destination address is not a valid user-mode address or is inaccessible.

If you are copying a fixed-sized structure, you should use [**WriteStructToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtouser) instead to avoid the risk of passing the wrong size.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**CopyToUserNonTemporal**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytousernontemporal)

[**CopyToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytomode)

[**CopyFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfromuser)

[**CopyToUserFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytouserfromuser)
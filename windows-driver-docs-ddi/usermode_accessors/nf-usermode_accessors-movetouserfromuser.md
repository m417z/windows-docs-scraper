## Description

The **MoveToUserFromUser** function safely moves data from user-mode memory to user-mode memory, supporting overlapping memory regions.

## Parameters

### `Destination`

[out] A pointer to the starting address of the user-mode memory location where the data will be copied.

### `Source`

[in] A pointer to the starting address of the user-mode memory location from which to copy the data.

### `Length`

[in] The number of bytes to move.

## Remarks

This function provides a safe way to move data from user-mode memory to user-mode memory with support for overlapping memory regions.

The function has the following properties:

* The function performs a move using [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

* The function isn't recognized as a compiler intrinsic so the compiler will never optimize away the call (either entirely or replace the call with an equivalent sequence of instructions).

* When the call returns, the data has been copied from **Source** to **Destination**. This function's memory accesses to the **Source** and **Destination** will only be performed within the function (for example, the compiler can't move memory accesses out of this function).

* The function might perform unaligned accesses if the platform allows for it.

* The function might access memory locations more than once as part of its fill operation.

The function validates that both pointers refer to user-mode memory and raises a structured exception if the move operation fails, such as when the source or destination addresses are not valid user-mode addresses or are inaccessible.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**CopyToUserFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytouserfromuser)

[**CopyToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytouser)

[**CopyFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfromuser)
## Description

The **WriteInt16ToUserRelease** function safely writes an INT16 value to user-mode memory with [release semantics](https://learn.microsoft.com/windows-hardware/drivers/kernel/acquire-and-release-semantics).

## Parameters

### `Destination`

[out] A pointer to the user-mode memory location where the INT16 value will be written.

### `Value`

[in] The INT16 value to write to the destination memory location.

## Remarks

This function provides a safe way to write a INT16 value to user-mode memory. It ensures the provided address is a user-mode address before writing to it. The [release semantics](https://learn.microsoft.com/windows-hardware/drivers/kernel/acquire-and-release-semantics) ensure that preceding memory operations can't be reordered after this write operation.

This function doesn't enforce alignment.

It raises a structured exception if the memory access fails, such as when the destination address isn't a user-mode address or is inaccessible.

This function will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the function is called or after the function returns (unless the source code explicitly performs these accesses). The memory access is performed with [memory_order_release semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**WriteInt16ToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writeint16touser)

[**ReadInt16FromUserAcquire**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readint16fromuseracquire)
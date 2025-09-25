## Description

The **CopyFromUserAligned** macro safely copies data from user-mode memory to kernel memory, with alignment checking.

## Parameters

### `Destination`

[out] A pointer to the kernel memory location where the data will be copied.

### `Source`

[in] A pointer to the user-mode memory location from which to copy the data.

### `Length`

[in] The number of bytes to copy.

### `Alignment`

[in] The alignment boundary that the source pointer must satisfy.

## Syntax

```cpp
#define CopyFromUserAligned(Destination, Source, Length, Alignment)                                 \
            do {                                                                                    \
                ExProbeAlignment((Source), (Length), (Alignment));                                  \
                CopyFromUser((Destination), (Source), (Length));                                    \
            } while (0)
```

## Remarks

This macro provides a safe way to copy data from user-mode memory to kernel memory with alignment verification. This allows for flexible memory operations when kernel-mode code needs to retrieve data from user-mode buffers with specific alignment requirements.

The macro has the following properties:

* The macro performs a volatile copy using [memory_order_relaxed semantics](https://learn.microsoft.com/cpp/standard-library/atomic-enums?view=msvc-170#memory_order_enum).

* The macro isn't recognized as a compiler intrinsic so the compiler will never optimize away the call (either entirely or replace the call with an equivalent sequence of instructions).

* When the call returns, the data has been copied from **Source** to **Destination**. This macro's memory accesses to the **Source** and **Destination** will only be performed within the macro (for example, the compiler can't move memory accesses out of this macro).

* The macro might access memory locations more than once as part of its copy operation.

* The macro doesn't support copy operations when **Source** and **Destination** overlap each other.

The macro raises a structured exception if the copy operation fails, such as when the source address is not a valid user-mode address, is not properly aligned according to the **Alignment** parameter, or is inaccessible.

If you are copying from a fixed-sized structure, you should use [**ReadStructFromUserAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuseraligned) instead to avoid the risk of passing the wrong size.

This macro will never be optimized away by the compiler, nor will the compiler create additional accesses to this memory location before the macro is called or after the macro returns (unless the source code explicitly performs these accesses).

This macro works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the macro declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**CopyFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfromuser)

[**CopyFromUserNonTemporal**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfromusernontemporal)

[**CopyFromMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfrommode)

[**CopyFromModeAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copyfrommodealigned)

[**CopyToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-copytouser)
## Description

The **RtlSetVolatileMemory** function provides [**RtlFillMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory) behavior (for example, setting the contents of a buffer) in situations where the developer needs to be sure that the setting operation occurs (for example, isn't subject to compiler optimizations). The function returns a pointer to the filled memory.

## Parameters

### `Destination` [out]

A pointer to the starting address of the block of memory to fill.

### `Fill` [in]

The byte value with which to fill the memory block.

### `Length` [in]

The size of the block of memory to fill, in bytes. This value must be less than the size of the **Destination** buffer.

## Return value

Returns a pointer to the filled memory block (*Destination*).

## Remarks

- The function isn't recognized as a compiler intrinsic so the compiler will never optimize away the call (either entirely or replace the call with an equivalent sequence of instructions). This differs from **RtlFillMemory** which is subject to various compiler optimizations.

- When the call returns, the buffer has been overwritten with the desired value. This function's memory accesses to the *Destination* will only be performed within the function (for example, the compiler can't move memory accesses out of this function).

- The function might perform unaligned memory accesses if the platform allows for it.

- The function might access memory locations more than once as part of its operation.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the wdm.h header. You also need the library (volatileaccessk.lib) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

### Example

```cpp
UCHAR SensitiveData[100];

// Imagine we temporarily store some sensitive cryptographic
// material in a buffer.

StoreCryptographicKey(&SensitiveData);

DoCryptographicOperation(&SensitiveData);

// Now that we are done using the sensitive data we want to
// erase it from the stack. We can use RtlSetVolatileMemory
// to fill the buffer and get a pointer to the filled memory.
// This call will not be optimized away by the compiler.

volatile VOID* clearedBuffer = RtlSetVolatileMemory(&SensitiveData, 0, sizeof(SensitiveData));
```

## See also

[**RtlFillMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillmemory)

[**RtlFillVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillvolatilememory)
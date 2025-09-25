## Description

The **RtlSecureZeroMemory2** function is a convenience wrapper around [**RtlFillVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillvolatilememory) and is identical to [**RtlZeroVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzerovolatilememory).

## Parameters

### `Destination` [out]

A pointer to the starting address of the block of memory to fill with zeros.

### `Length` [in]

The size of the block of memory to fill with zeros, in bytes.

## Return value

Returns the value of *Destination*.

## Remarks

The **RtlSecureZeroMemory2** function is a convenience wrapper around **RtlFillVolatileMemory** and is identical to **RtlZeroVolatileMemory**.

For more information, see the remarks section of [**RtlFillVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillvolatilememory).

> [!NOTE]
> This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the wdm.h header. You also need the library (volatileaccessk.lib) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

### Example

```cpp
UCHAR SensitiveData[100];

// Imagine we temporarily store some sensitive cryptographic
// material in a buffer.

StoreCryptographicKey(&SensitiveData);

DoCryptographicOperation(&SensitiveData);

// Now that we are done using the sensitive data we want to
// erase it from the stack. We cannot call RtlFillMemory because
// if the compiler realizes that "SensitiveData" is not
// referenced again the compiler can remove the call to RtlFillMemory.
// Instead we can call RtlSecureZeroMemory2, RtlZeroVolatileMemory, or RtlFillVolatileMemory
// (the former two are convenience wrappers around the latter). These
// calls will not be optimized away by the compiler.
// Note that RtlSecureZeroMemory2 performs better than
// RtlSecureZeroMemory function.

RtlSecureZeroMemory2(&SensitiveData, sizeof(SensitiveData));
```

## See also

[**RtlFillVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillvolatilememory)

[**RtlZeroVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzerovolatilememory)
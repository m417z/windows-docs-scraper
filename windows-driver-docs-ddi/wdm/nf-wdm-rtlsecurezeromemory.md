## Description

The **RtlSecureZeroMemory** routine securely fills a block of memory with zeros in a way that is guaranteed not to be optimized away by the compiler.

## Parameters

### `Ptr` [in, out]

A pointer to the memory block to be securely filled with zeros.

### `cnt` [in]

The number of bytes to fill with zeros.

## Return value

**RtlSecureZeroMemory** returns a pointer to the memory block that was filled (*Ptr*).

## Syntax

```cpp
PVOID RtlSecureZeroMemory(
  [in, out] PVOID  Ptr,
  [in]      SIZE_T cnt
);
```

## Remarks

- The function uses volatile memory accesses to ensure that the compiler cannot optimize away the zeroing operation, even if the memory appears to be unused after the call.

- This differs from [**RtlZeroMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory), which may be optimized away by the compiler if the memory is not accessed again.

- The function guarantees that all specified bytes will be set to zero and that this operation will not be removed by compiler optimizations.

Callers of **RtlSecureZeroMemory** can be running at any IRQL if the destination memory block is in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

### Example

```cpp
UCHAR SensitiveData[256];
UCHAR CryptographicKey[32];

// Use sensitive data
ProcessSensitiveInformation(SensitiveData);
PerformCryptographicOperation(CryptographicKey);

// Securely clear sensitive data from memory
// This will not be optimized away by the compiler
RtlSecureZeroMemory(SensitiveData, sizeof(SensitiveData));
RtlSecureZeroMemory(CryptographicKey, sizeof(CryptographicKey));
```

## See also

[**RtlZeroMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)

[**RtlFillVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfillvolatilememory)

[**RtlSetVolatileMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetvolatilememory)
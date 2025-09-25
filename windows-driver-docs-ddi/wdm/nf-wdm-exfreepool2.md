## Description

The **ExFreePool2** routine deallocates a previously allocated block of pool memory. It extends [**ExFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool) by accepting optional extended parameters to free allocations associated with a secure pool created via [**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool).

## Parameters

### `P` [in]

Pointer to the start of the allocation to free. Must be the exact address returned by the pool allocation routine such as [**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2) or [**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3). This parameter must not be NULL.

### `Tag` [in]

Pool tag originally supplied when the allocation was made.

### `ExtendedParameters` [in, optional]

Pointer to an array of extended parameter descriptors (type [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter)). See Remarks.

### `ExtendedParametersCount` [in]

Number of entries in the **ExtendedParameters** array. See Remarks.

## Remarks

The following table shows the requirements for using **ExFreePool2** with different types of allocations:

| Allocation Type | ExtendedParametersCount | ExtendedParameters |
|----------------------|-------------------------|------------------------------------------------|
| Ordinary (non-secure)| 0 | NULL |
| Secure | 1 | Pointer to [**POOL_EXTENDED_PARAMS_SECURE_POOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_params_secure_pool) structure |

For secure pool frees, the associated **POOL_EXTENDED_PARAMS_SECURE_POOL** structure must:

* Contain a valid secure pool handle obtained from a successful allocation associated with a secure pool.
* Provide the correct cookie for the allocation being freed.
* Have all reserved fields (e.g., Buffer, SecurePoolFlags) set to NULL/0.
* Be the sole entry (ExtendedParametersCount == 1).

Validation failures (wrong count, unsupported parameter type, non-zero reserved fields, invalid handle, or secure kernel communication failure) cause a bug check (BAD_POOL_CALLER) rather than returning an error status.

This routine doesn't return an NTSTATUS value; it always completes the free or bug checks. A double free, corrupted header, tag mismatch, or freeing with incorrect secure pool metadata can also trigger pool integrity bug checks depending on system diagnostics.

**ExFreePool2** must be called at IRQL <= DISPATCH_LEVEL. If the allocation originated from paged pool the caller must be at IRQL <= APC_LEVEL. Secure pool allocations reside in nonpaged memory and can be freed at DISPATCH_LEVEL.

Use **ExFreePool2** for code that may free either standard or secure pool allocations to avoid branching on allocation origin.

## See also

[**ExFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool)

[**ExFreePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag)

[**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2)

[**ExAllocatePool3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool3)

[**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool)
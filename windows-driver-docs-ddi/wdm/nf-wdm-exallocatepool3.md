## Description

The **ExAllocatePool3** routine allocates pool memory of the specified type and returns a pointer to the allocated block. This routine is similar to **ExAllocatePool2** but it adds extended parameters.

## Parameters

### `Flags`

A ULONG64-typed value specifying the type of pool memory along with required and optional attributes. Multiple flag values can be combined using bit-wise OR. See [**POOL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/pool_flags) for possible values.

### `NumberOfBytes`

Specifies a non-zero number of bytes to allocate.

### `Tag`

The pool tag to use for the allocated memory. Specify the pool tag as a non-zero character literal of one to four characters delimited by single quotation marks (for example, `Tag1`). The string is usually specified in reverse order (for example, `1gaT`). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

### `ExtendedParameters`

A pointer to an array of [**POOL_EXTENDED_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pool_extended_parameter) structures that specify additional attributes for the allocation.

### `ExtendedParametersCount`

A ULONG value specifying the number of parameters in **ExtendedParameters**.

## Return value

**ExAllocatePool3** returns a pointer to the allocated memory.

The following conditions cause the function to return NULL by default. If **POOL_FLAG_RAISE_ON_FAILURE** is specified, the function raises an exception.

* Insufficient memory
* **Tag** is set to 0 or invalid POOL_FLAGS are specified
* Invalid **POOL_EXTENDED_PARAMETER** structures

## Remarks

If you are building a driver that targets versions of Windows prior to Windows 10, version 2004, use [**ExAllocatePoolPriorityZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolpriorityzero) or [**ExAllocatePoolPriorityUninitialized**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolpriorityuninitialized).

See the remarks of [**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2) for additional information.

## See also

[**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2)
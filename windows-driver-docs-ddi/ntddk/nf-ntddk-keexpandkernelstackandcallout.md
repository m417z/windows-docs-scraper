# KeExpandKernelStackAndCallout function

## Description

The **KeExpandKernelStackAndCallout** routine calls a routine with a guaranteed amount of stack space.

## Parameters

### `Callout` [in]

Pointer to an [ExpandedStackCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-expand_stack_callout) routine.

### `Parameter` [in, optional]

Specifies the parameter to pass to the *ExpandedStackCall* routine.

### `Size` [in]

Specifies the number of bytes on the stack to provide to the *ExpandedStackCall* routine. This value must be large enough to accommodate the stack usage of the *ExpandedStackCall* routine and any call that this routine might make. This value must not exceed MAXIMUM_EXPANSION_SIZE.

## Return value

Returns success if the stack allocation is successful and the callout has been called. Otherwise, returns a failure status.

## Syntax

```cpp
NTSTATUS
KeExpandKernelStackAndCallout (
    _In_ PEXPAND_STACK_CALLOUT Callout,
    _In_opt_ PVOID Parameter,
    _In_ SIZE_T Size
    );
```

## Remarks

**KeExpandKernelStackAndCallout** expands the kernel stack by *Size* bytes for use by the [ExpandedStackCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-expand_stack_callout) routine. If there is not enough space available on the stack, **KeExpandKernelStackAndCallout** allocates a new kernel stack segment. The routine then calls the *ExpandedStackCall* routine.

In Windows 7, Windows Server 2008 R2, and later versions of Windows, consider using the [**KeExpandKernelStackAndCalloutEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keexpandkernelstackandcalloutex) routine instead of **KeExpandKernelStackAndCallout**. **KeExpandKernelStackAndCalloutEx** is similar to **KeExpandKernelStackAndCallout** but has additional parameters and can be called at IRQL <= DISPATCH_LEVEL.

The calling thread must not call the [PsTerminateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psterminatesystemthread) routine until the thread's *ExpandedStackCall* routine returns. **PsTerminateSystemThread** checks to determine if the *ExpandedStackCall* routine is still active and, if it is, causes a bug check.

## See also

[ExpandedStackCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-expand_stack_callout)

[**KeExpandKernelStackAndCalloutEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keexpandkernelstackandcalloutex)

[PsTerminateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psterminatesystemthread)
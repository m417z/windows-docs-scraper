# ExSetResourceOwnerPointer function

## Description

The **ExSetResourceOwnerPointer** routine sets the owner thread pointer for an executive resource.

## Parameters

### `Resource` [in, out]

A pointer to an executive resource owned by the current thread.

### `OwnerPointer` [in]

A pointer to an owner thread pointer of type ERESOURCE_THREAD (for additional requirements, see the following Remarks section).

## Remarks

**ExSetResourceOwnerPointer**, used in conjunction with **ExReleaseResourceForThreadLite**, provides a means for one thread (acting as a resource manager thread) to acquire and release resources for use by another thread (acting as a resource user thread).

After calling **ExSetResourceOwnerPointer** for a specific resource, the only other routine that can be called for that resource is **ExReleaseResourceForThreadLite**.

The resource manager thread acquires ownership of the resource and passes ownership to the user thread by calling **ExSetResourceOwnerPointer**. The caller must allocate the memory for the ERESOURCE_THREAD value pointed to by *OwnerPointer* in system memory, and this memory must remain allocated until **ExReleaseResourceForThreadLite** returns. The caller must also set the two low-order bits of the ERESOURCE_THREAD value pointed to by *OwnerPointer* to one — this encoding is used internally by the resource services to distinguish between owner and thread addresses.

When the user thread is done with the resource, the resource manager thread releases the user thread's ownership of the resource by calling **ExReleaseResourceForThreadLite**. The *ResourceThreadId* input parameter is set to the value of the *OwnerPointer* parameter used in the previous call to **ExSetResourceOwnerPointer** that gave the worker thread ownership of the resource.

## See also

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85))
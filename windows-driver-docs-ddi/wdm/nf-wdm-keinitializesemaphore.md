# KeInitializeSemaphore function

## Description

The **KeInitializeSemaphore** routine initializes a semaphore object with a specified count and specifies an upper limit that the count can attain.

## Parameters

### `Semaphore` [out]

Pointer to a dispatcher object of type semaphore, for which the caller provides the storage.

### `Count` [in]

Specifies the initial count value to be assigned to the semaphore. This value must be positive. A nonzero value sets the initial state of the semaphore to signaled.

### `Limit` [in]

Specifies the maximum count value that the semaphore can attain. This value must be positive. It determines how many waiting threads become eligible for execution when the semaphore is set to the signaled state and can therefore access the resource that the semaphore protects.

## Remarks

The semaphore object is initialized with the specified initial count and limit.

Storage for a semaphore object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

For more information about semaphore objects, see [Semaphore Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/semaphore-objects).

## See also

[KeReadStateSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatesemaphore)

[KeReleaseSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasesemaphore)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)
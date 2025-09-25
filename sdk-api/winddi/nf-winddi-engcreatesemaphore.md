# EngCreateSemaphore function

## Description

The **EngCreateSemaphore** function creates a semaphore object.

## Return value

If the function succeeds, the return value is a handle to the semaphore object. A null pointer is returned if the function fails.

## Remarks

Graphics drivers can create and use a semaphore object for resource synchronization. For example:

* The *Permedia* display driver uses a semaphore when an asynchronous pointer requires access to the CRTC registers, because these registers are shared by both the asynchronous hardware pointers and the synchronous activities of the device.
* Multiple printer drivers sharing global data, such as font data on a print server, need to synchronize access to this data.

**Note** The Microsoft Windows Driver Kit (WDK) does not contain the 3Dlabs Permedia2 (*3dlabs.htm* ) and 3Dlabs Permedia3 (*Perm3.htm*) sample display drivers. You can get these sample drivers from the Windows Server 2003 SP1 Driver Development Kit (DDK), which you can download from the [DDK - Windows Driver Development Kit](https://learn.microsoft.com/windows-hardware/drivers/devtest/) page of the WDHC website.

## See also

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngDeleteSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesemaphore)

[EngIsSemaphoreOwned](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreowned)

[EngIsSemaphoreOwnedByCurrentThread](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreownedbycurrentthread)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)
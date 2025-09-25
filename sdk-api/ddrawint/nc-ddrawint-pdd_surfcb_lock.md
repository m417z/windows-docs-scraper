## Description

The *DdLock* callback function locks a specified area of surface memory and provides a valid pointer to a block of memory associated with a surface.

## Parameters

### `unnamedParam1`

Points to a [DD_LOCKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_lockdata) structure that contains the information required to perform the lockdown.

## Return value

*DdLock* returns one of the following callback codes:

## Remarks

*DdLock*
should set the **ddRVal** member
of the DD_LOCKDATA structure at *lpLock* to
DDERR_WASSTILLDRAWING and return DDHAL_DRIVER_HANDLED
if a blit or flip is in progress.

Unless otherwise specified by the
**dwFlags** member of
DD_LOCKDATA, the driver can return a memory pointer to
the top of the surface in the
**lpSurfData** member of
DD_LOCKDATA. If the driver needs to calculate its own
address for the surface, it can rely on the pointer
passed in the **fpProcess**
member of DD_LOCKDATA as being a per-process pointer to
the user-mode mapping of its DirectDraw-accessible frame
buffer.

A lock does not provide exclusive access to the
requested memory block; that is, multiple threads can
lock the same surface at the same time. It is the
application's responsibility to synchronize access to
the memory block whose pointer is being obtained.

A driver running on an NT-based operating system
should not return a pointer to system memory from
its *DdLock*
function unless that driver's
[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))
function previously allocated such memory with the
PLEASE_ALLOC_USERMEM flag. If PLEASE_ALLOC_USERMEM was
not used, applications could receive errors whenever they
attempted to access such memory. See
[NT Kernel's Implementation
of DDLOCK_NOSYSLOCK](https://learn.microsoft.com/) for more information.

*DdLock* can be called with a disabled
[PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled
or enabled by calling the display driver's
[DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode)
function. See
[Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs)
for more information.

### NT Kernel's Implementation of DDLOCK_NOSYSLOCK

Applications can use DirectDraw's and Direct3D's application programming interfaces (APIs) to obtain long-duration locks on video memory resources. Such locks are called "NOSYSLOCK" locks. These locks operate differently than typical video-memory locks as described in the following paragraphs.

After the DirectDraw runtime calls a driver's *DdLock* function with the DDLOCK_NOSYSLOCK flag specified in the **dwFlags** member of DD_LOCKDATA, the runtime examines the pointer to the surface contents returned by the driver. Instead of passing the driver-returned pointer directly to an application, the runtime creates a second user-mode mapping of video memory (both local and nonlocal) and calculates the equivalent virtual address within that mapping. This virtual address is known as the alias pointer to the memory lock. The runtime passes this alias-lock pointer to the application. The application uses this alias-lock pointer to read and write directly to video memory. Neither the application nor the driver is aware that it uses a different locked-memory pointer.

Later, at mode-switch time, the DirectDraw runtime notes any outstanding alias-lock pointers. Instead of waiting for the alias-lock pointers to complete--as it would for a typical video-memory lock--the runtime remaps the user-mode mapping of video memory and allows the mode switch to continue. The runtime remaps the user-mode mappings to a single dummy page; the application continues to read and write to that dummy page, otherwise unaware of any changes. The runtime must then clean up alias-lock pointers by calling the driver's [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) function. The runtime can clean up alias-lock pointers because the application is no longer writing into video memory. Because this clean up occurs at mode-switch time, the next step in the sequence is to lose surfaces, which means to destroy the driver's per-surface objects. In other words, the runtime calls the driver's [DdDestroySurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_destroysurface) function for all surfaces, including surfaces that the application continues to consider as locked. In fact, the application continues to read and write to a dummy page of system memory.

This whole process only works if the memory pointer returned by *DdLock* is some mapping of video memory. This video-memory mapping can be either the user-mode mapping of nonlocal video memory performed by the DirectDraw kernel-mode runtime or the mapping provided by the driver's [DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory) function. If the memory pointer cannot be attributed to one of these mappings, the runtime does not remap the lock. The mode switch continues, which means that the driver's surface object is unlocked and destroyed through calls to the driver's [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) and [DdDestroySurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_destroysurface) functions respectively. The driver then typically releases any system memory that the driver allocated at lock time. Because the application is still writing to this memory, an access violation occurs.

Consequently, a driver should not attempt to return system memory pointers from its *DdLock* function unless that driver's [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) function previously allocated such memory with the PLEASE_ALLOC_USERMEM flag. The DirectDraw runtime owns memory allocated in this manner and can defer release of this memory until the application unlocks the memory. Therefore, the driver's *DdLock* function can return pointers to memory allocated in this manner without risk of crashing the application.

## See also

[DD_LOCKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_lockdata)

[DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory)

[DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock)
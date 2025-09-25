# PFND3DDDI_LOCK2CB callback function

## Description

The **pfnLock2Cb** function locks an allocation and obtains a pointer to the allocation from the display miniport driver or video memory manager.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_LOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock2) structure that describes the allocation to lock.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

With the Windows Display Driver Model (WDDM) v2 it is now the user mode driver's responsibility to handle the following tasks:

* Support no-overwrite and discard semantics. The video memory manager no longer supports renaming so it is up to the driver to implement renaming itself.
* Synchronization of other lock types (not no-overwrite or discard)

  + Must return **WasStillDrawing** if the user attempts to lock an allocation while specifying the **D3D1X_MAP_FLAG_DO_NOT_WAIT** flag.
  + The user mode driver must block if synchronization is required (ex. hardware is accessing the allocation). This must be implemented as a non-polling wait and make use of the new monitored fence synchronization objects.

## See also

[D3DDDICB_LOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock2)
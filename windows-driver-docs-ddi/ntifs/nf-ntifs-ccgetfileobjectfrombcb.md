# CcGetFileObjectFromBcb function

## Description

Given a pointer to a pinned buffer control block (BCB) for a file, the **CcGetFileObjectFromBcb** routine returns a pointer to the file object that the cache manager is using for that file.

## Parameters

### `Bcb` [in]

Pointer to the pinned BCB.

## Return value

Pointer to the file object, or **NULL** if the file is not cached or is no longer cached.

## Remarks

The file object pointer is guaranteed to remain valid as long as the BCB exists.

## See also

[CcMapData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmapdata)

[CcPinMappedData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinmappeddata)

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)
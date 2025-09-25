# CcRepinBcb function

## Description

The **CcRepinBcb** routine pins a buffer control block (BCB) an additional time to prevent it from being freed by a subsequent call to [CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata).

## Parameters

### `Bcb` [in]

Buffer control block (BCB) pointer returned by [CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread) or [CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite).

## Remarks

File systems call **CcRepinBcb** to preserve a BCB for write-through or error recovery. Typically a file system would do this the first time it marks a BCB as dirty while processing a write-through request, or any time that it determines that a buffer will be required for write-through.

Every call to **CcRepinBcb** must be matched by a subsequent call to [CcUnpinRepinnedBcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpinrepinnedbcb).

## See also

[CcPinRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpinread)

[CcPreparePinWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccpreparepinwrite)

[CcUnpinData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpindata)

[CcUnpinRepinnedBcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccunpinrepinnedbcb)
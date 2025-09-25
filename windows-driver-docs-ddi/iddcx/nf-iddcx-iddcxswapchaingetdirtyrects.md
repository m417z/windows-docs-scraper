# IddCxSwapChainGetDirtyRects function

## Description

 An OS callback function the driver calls when it wants retrieve the dirty rects for the current frame

## Parameters

### `SwapChainObject` [in]

The swap-chain object whose current frame is being queried.

### `pInArgs` [in]

Input arguments of the function

### `pOutArgs` [out]

Output arguments of the function

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.
# IddCxSwapChainSetDevice function

## Description

An OS callback function the driver calls within its SetSwapChain routine to setup the swap-chain with a particular DXGI device.

## Parameters

### `SwapChainObject` [in]

The swap-chain object that will be setup with a particular DXGI device.

### `pInArgs` [in]

Input arguments to the function

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.
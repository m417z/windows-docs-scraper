# IddCxAdapterUpdateMaxDisplayPipelineRate function

## Description

 An OS callback function the driver calls to report that the max display pipeline rate has changed

## Parameters

### `hOsAdapterContext` [in]

This is the OS context handle for this adapter returned by the **IddCxStart** call

### `pInArgs` [in]

Input arguments to the function

## Return value

(NTSTATUS) The method returns S_OK if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.
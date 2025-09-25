## Description

Don't use the **D3DKMT_VIDMM_ESCAPE** structure; it's for testing purposes only.

The **D3DKMT_VIDMM_ESCAPE** structure describes how to control the video memory manager, which is a part of *Dxrngkl.sys*, in a call to the [**D3DKMTEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Members

### `Type`

### `SetFault`

### `SetFault.ProbeAndLock`

### `SetFault.SplitPoint`

### `SetFault.NoDemotion`

### `SetFault.SwizzlingAperture`

### `SetFault.PagingPathLockSubRange`

### `SetFault.PagingPathLockMinRange`

### `SetFault.ComplexLock`

### `SetFault.FailVARotation`

### `SetFault.NoWriteCombined`

### `SetFault.NoPrePatching`

### `SetFault.AlwaysRepatch`

### `SetFault.ExpectPreparationFailure`

### `SetFault.FailUserModeVAMapping`

### `SetFault.NeverDiscardOfferedAllocation`

### `SetFault.AlwaysDiscardOfferedAllocation`

### `SetFault.Reserved`

### `SetFault.Value`

### `Evict`

### `Evict.ResourceHandle`

### `Evict.AllocationHandle`

### `Evict.hProcess`

### `EvictByNtHandle`

### `EvictByNtHandle.NtHandle`

### `GetVads`

### `GetVads.GetNumVads`

### `GetVads.GetNumVads.NumVads`

### `GetVads.GetVad`

### `GetVads.GetVadRange`

### `GetVads.GetGpuMmuCaps`

### `GetVads.GetPte`

### `GetVads.GetSegmentCaps`

### `GetVads.Command`

### `GetVads.Status`

### `GetVads.GetPteExt`

### `SetBudget`

### `SetBudget.LocalMemoryBudget`

### `SetBudget.SystemMemoryBudget`

### `SuspendProcess`

### `SuspendProcess.hProcess`

### `SuspendProcess.bAllowWakeOnSubmission`

### `ResumeProcess`

### `ResumeProcess.hProcess`

### `GetBudget`

### `GetBudget.NumBytesToTrim`

### `SetTrimIntervals`

### `SetTrimIntervals.MinTrimInterval`

### `SetTrimIntervals.MaxTrimInterval`

### `SetTrimIntervals.IdleTrimInterval`

### `EvictByCriteria`

### `Wake`

### `Wake.bFlush`

### `Defrag`

### `Defrag.Operation`

### `Defrag.SegmentId`

### `Defrag.TotalCommitted`

### `Defrag.TotalFree`

### `Defrag.LargestGapBefore`

### `Defrag.LargestGapAfter`

### `DelayExecution`

### `DelayExecution.hPagingQueue`

### `DelayExecution.PhysicalAdapterIndex`

### `DelayExecution.Milliseconds`

### `DelayExecution.PagingFenceValue`

### `VerifyIntegrity`

### `VerifyIntegrity.PhysicalAdapterIndex`

### `VerifyIntegrity.SegmentId`

### `DelayEvictionConfig`

### `DelayEvictionConfig.TimerValue`

## See also

[**D3DKMTEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[**D3DKMT_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)
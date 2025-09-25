## Description

*Dxgkrnl* calls **DxgkDdiSetNativeFenceLogBuffer** to inform the kernel-mode display miniport driver (KMD) of the location of the specified native fence log buffer.

## Parameters

### `pSetNativeFenceLogBuffer`

[in] Pointer to a [**DXGKARG_SETNATIVEFENCELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setnativefencelogbuffer) structure that contains the native fence log buffer information.

## Return value

**DxgkDdiSetNativeFenceLogBuffer** returns STATUS_SUCCESS if KMD was able to successfully set the native fence log buffer. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

*Dxgkrnl* can destroy and recreate a log buffer. Each time it does, it calls **DxgkDdiSetNativeFenceLogBuffer** to inform KMD of the new location.

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_SETNATIVEFENCELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setnativefencelogbuffer)
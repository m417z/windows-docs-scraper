# ID3D10Device::Flush

## Description

Send queued-up commands in the command buffer to the GPU.

## Remarks

Most applications will not need to call this method. Calling this method when not necessary will incur a performance penalty. Each call to **Flush** incurs a significant amount of overhead.

When Direct3D state-setting, present, or draw commands are called by an application, those commands are queued into an internal command buffer. **Flush** sends those commands to the GPU for processing. Normally, these commands are sent to the GPU automatically whenever Direct3D determines that they need to be, such as when the command buffer is full or when mapping a resource. **Flush** will send the commands manually.

**Flush** should be used when the CPU waits for an arbitrary amount of time (such as when calling [Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep), [ID3DX10ThreadPump::WaitForAllItems](https://learn.microsoft.com/windows/desktop/direct3d10/id3dx10threadpump-waitforallitems), or [WaitForVBlank](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-waitforvblank).

For more information about how flushing works, see [Accurately Profiling Direct3D API Calls (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/accurately-profiling-direct3d-api-calls).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)
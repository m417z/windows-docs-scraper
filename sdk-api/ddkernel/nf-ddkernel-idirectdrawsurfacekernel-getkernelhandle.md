## Description

The **IDirectDrawSurfaceKernel::GetKernelHandle** method returns a kernel-mode handle to the DirectDraw surface.

## Parameters

#### `unnamedParam1`

Caller-supplied pointer into which the kernel-mode handle of the DirectDraw surface is returned.

## Return value

The method must return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |
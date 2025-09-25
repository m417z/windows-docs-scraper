## Description

The **IDirectDrawKernel::GetCaps** method returns the capabilities of this kernel-mode device.

## Parameters

#### `unnamedParam1`

Caller-supplied pointer to a [DDKERNELCAPS](https://learn.microsoft.com/windows/desktop/api/ddkernel/ns-ddkernel-ddkernelcaps) structure into which the kernel-mode capabilities of the DirectDraw device are returned.

## Return value

The method must return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |
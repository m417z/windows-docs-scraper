## Description

This method clones the current host context and returns a one-time modification interface to associate data with the context.

## Parameters

### `extensionHandle`

This parameter points to a IDebugHostContextExtension pointer, which is used to retrieve the host context extension. This is an Output parameter for the cloned context.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code.

## Remarks

The CloneContextForModification method is used to clone the current host context for one time modification and eventual immutability. It is necessary to call the [FinalizeContext method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostcontextextension-finalizecontext) to finalize the cloned context and get back to the actual cloned context. After this, the returned host context becomes immutable and cannot be modified further.

## See also

[IDebugHostContextExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextextensibility)
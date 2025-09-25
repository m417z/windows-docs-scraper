# ISynchronize::Reset

## Description

Sets the synchronization object to the nonsignaled state.

## Return value

This method returns S_OK to indicate that the method completed successfully.

## Remarks

The [ISynchronize::Wait](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isynchronize-wait) method implemented on a standard event object (CLSID_StdEvent) automatically calls **Reset** when the synchronization object has been signaled.

The implementation of [ISynchronize::Wait](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isynchronize-wait) on the manual reset event object (CLSID_ManualResetEvent) does not automatically call **Reset**. A server object usually calls **Reset** from a method that clients call after they detect that the synchronization object was signaled.

In general, it is the server's responsibility to call **Reset**. If, however, the client needs to begin with the synchronization object in an unsignaled state, the client should call **Reset**.

## See also

[ISynchronize](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isynchronize)
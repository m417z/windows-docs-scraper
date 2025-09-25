# IDebugHost::GetHostDefinedInterface

## Description

The GetHostDefinedInterface method returns the host's main private interface, if such exists for the given host. For Debugging Tools for Windows, the interface returned here is an IDebugClient (cast to IUnknown).

## Parameters

### `hostUnk`

The debug host's core private interface is returned here. For Debugging Tools for Windows, this is an IDebugClient interface.

## Return value

This method returns HRESULT that indicates success or failure. A host which does not have a private interface that it wishes to expose to data model clients may return E_NOTIMPL here.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHost> spHost; /* get the debug host */

// Get the debug host private interface back from the host interfaces.
// This is **HOST SPECIFIC**
ComPtr<IUnknown> spPrivate;
if (SUCCEEDED(spHost->GetHostDefinedInterface(&spPrivate)))
{
    // As an example, consider DbgEng:
    ComPtr<IDebugClient> spClient;
    if (SUCCEEDED(spPrivate.As(&spClient)))
    {
        // spClient now contains a DbgEng IDebugClient!
    }
}
```

## See also

[IDebugHost interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughost)
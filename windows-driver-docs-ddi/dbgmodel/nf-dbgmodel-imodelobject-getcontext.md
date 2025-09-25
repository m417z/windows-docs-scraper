# IModelObject::GetContext

## Description

The GetContext method returns the host context that is associated with the object. This represents which target, process, thread, etc... the object came from.

## Parameters

### `context`

The host context of the object will be returned in this argument.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHost> spHost;      // get the debug host
ComPtr<IModelObject> spObject;  // get an object within a process (or a process object)

ComPtr<IDebugHostContext> spContext;
ComPtr<IDebugHostMemory> spMemory;
if (SUCCEEDED(spObject->GetContext(&spContext)) &&
    SUCCEEDED(spHost.As(&spMemory)))
{
    // Read 4 bytes from address 0x100 in the process context represented by spObject
    char bytes[4];
    ULONG64 bytesRead;
    HRESULT hr = spMemory->ReadBytes(spContext.Get(), 0x100, bytes, ARRAYSIZE(bytes), &bytesRead);

    // Check / Use read.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)
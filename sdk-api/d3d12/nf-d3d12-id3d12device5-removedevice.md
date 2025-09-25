## Description

You can call **RemoveDevice** to indicate to the Direct3D 12 runtime that the GPU device encountered a problem, and can no longer be used. Doing so will cause all devices' monitored fences to be signaled. Your application typically doesn't need to explicitly call **RemoveDevice**.

## Remarks

Because device removal triggers all fences to be signaled to `UINT64_MAX`, you can create a callback for device removal using an event.

```cpp
HANDLE deviceRemovedEvent = CreateEventW(NULL, FALSE, FALSE, NULL);
assert(deviceRemovedEvent != NULL);
_deviceFence->SetEventOnCompletion(UINT64_MAX, deviceRemoved);

HANDLE waitHandle;
RegisterWaitForSingleObject(
  &waitHandle,
  deviceRemovedEvent,
  OnDeviceRemoved,
  _device.Get(), // Pass the device as our context
  INFINITE, // No timeout
  0 // No flags
);

void OnDeviceRemoved(PVOID context, BOOLEAN)
{
  ID3D12Device* removedDevice = (ID3D12Device*)context;
  HRESULT removedReason = removedDevice->GetDeviceRemovedReason();
  // Perform app-specific device removed operation, such as logging or inspecting DRED output
}
```

## See also
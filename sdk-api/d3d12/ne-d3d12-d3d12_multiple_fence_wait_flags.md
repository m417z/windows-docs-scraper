# D3D12_MULTIPLE_FENCE_WAIT_FLAGS enumeration

## Description

Specifies multiple wait flags for multiple fences.

## Constants

### `D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE:0`

No flags are being passed. This means to use the default behavior, which is to wait for all fences before signaling the event.

### `D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY:0x1`

Modifies behavior to indicate that the event should be signaled after any one of the fence values has been reached by its corresponding fence.

### `D3D12_MULTIPLE_FENCE_WAIT_FLAG_ALL:0`

An alias for **D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE**, meaning to use the default behavior and wait for all fences.

## Remarks

This enum is used by the [SetEventOnMultipleFenceCompletion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-seteventonmultiplefencecompletion) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)
## Description

Sets the mode for driver background processing optimizations.

## Parameters

### `Mode` [in]

Type: **[D3D12_BACKGROUND_PROCESSING_MODE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_background_processing_mode)**

The level of dynamic optimization to apply to GPU work that's subsequently submitted.

### `MeasurementsAction` [in]

Type: **[D3D12_MEASUREMENTS_ACTION](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_measurements_action)**

The action to take with the results of earlier workload instrumentation.

### `hEventToSignalUponCompletion` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An optional handle to signal when the function is complete. For example, if *MeasurementsAction* is set to [D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_measurements_action), then *hEventToSignalUponCompletion* is signaled when all resulting compilations have finished.

### `pbFurtherMeasurementsDesired` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

An optional pointer to a Boolean value. The function sets the value to `true` to indicate that you should continue profiling, otherwise, `false`.

## Return value

## Remarks

A graphics driver can use idle-priority background CPU threads to dynamically recompile shader programs. That can improve GPU performance by specializing shader code to better match details of the hardware that it's running on, and/or the context in which it's being used.

As a developer, you don't have to do anything to benefit from this feature (over time, as drivers adopt background processing optimizations, existing shaders will automatically be tuned more efficiently). But, when you're profiling your code, you'll probably want to call **SetBackgroundProcessingMode** to make sure that any driver background processing optimizations have taken place before you take timing measurements. Here's an example.

```cpp
SetBackgroundProcessingMode(
    D3D12_BACKGROUND_PROCESSING_MODE_ALLOW_INTRUSIVE_MEASUREMENTS,
    D3D_MEASUREMENTS_ACTION_KEEP_ALL,
    nullptr, nullptr);

// Here, prime the system by rendering some typical content.
// For example, a level flythrough.

SetBackgroundProcessingMode(
    D3D12_BACKGROUND_PROCESSING_MODE_ALLOWED,
    D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS,
    nullptr, nullptr);

// Here, continue rendering. This time with dynamic optimizations applied.
// And then take your measurements.
```

[PIX](https://devblogs.microsoft.com/pix/) automatically uses **SetBackgroundProcessingMode**—first to prime the system,and then to prevent any further changes from taking place in the middle of its analysis. PIX waits on an event (to make sure all background shader recompiles have finished) before it starts taking measurements.

## See also
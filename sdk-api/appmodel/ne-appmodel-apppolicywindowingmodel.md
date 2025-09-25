# AppPolicyWindowingModel enumeration

## Description

The AppPolicyWindowingModel enumeration indicates whether a process uses a CoreWindow-based, or a HWND-based, windowing model.

## Constants

### `AppPolicyWindowingModel_None`

Indicates that the process doesn't have a windowing model.

### `AppPolicyWindowingModel_Universal`

Indicates that the process's windowing model is CoreWindow-based.

### `AppPolicyWindowingModel_ClassicDesktop`

Indicates that the process's windowing model is HWND-based.

### `AppPolicyWindowingModel_ClassicPhone`

Indicates that the process's windowing model is Silverlight-based, and does not provide notifications for window state changes.
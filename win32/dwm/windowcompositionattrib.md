# WINDOWCOMPOSITIONATTRIB enumeration

Specifies options used by the [WINDOWCOMPOSITIONATTRIBDATA](https://learn.microsoft.com/windows/win32/dwm/windowcompositionattribdata) structure.

## Fields

`WCA_EXCLUDED_FROM_DDA`

Prevents a window from being captured by the Desktop Duplication API. The pvData member of the [WINDOWCOMPOSITIONATTRIBDATA](https://learn.microsoft.com/windows/win32/direct3ddxgi/desktop-dup-api) structure points to a value of type BOOL. If the value is TRUE, the window is not captured. Otherwise, the window exhibits normal behavior.\

## Requirements

| Requirement | Value |
|-|-|
| Minimum supported client | Windows 10 version 1709 (build 16299)] |
| Minimum supported server | None supported |
| Header | N/A |
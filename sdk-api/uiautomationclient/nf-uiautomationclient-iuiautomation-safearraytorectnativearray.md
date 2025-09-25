# IUIAutomation::SafeArrayToRectNativeArray

## Description

Converts a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) containing rectangle coordinates to an array of type [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect).

## Parameters

### `rects` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

A pointer to an array containing rectangle coordinates.

### `rectArray` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)****

Receives a pointer to an array of structures containing rectangle coordinates.

### `rectArrayCount` [out, retval]

Type: **int***

Receives the number of elements in *rectArray*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
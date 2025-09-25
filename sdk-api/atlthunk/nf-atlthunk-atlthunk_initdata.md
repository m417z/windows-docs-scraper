# AtlThunk_InitData function

## Description

Initializes an ATL thunk.

## Parameters

### `Thunk`

A non-null return value from [AtlThunk_AllocateData](https://learn.microsoft.com/windows/desktop/api/atlthunk/nf-atlthunk-atlthunk_allocatedata).

### `Proc`

See the example in remarks for more info.

### `FirstParameter`

See the example in remarks for more info.

## Remarks

An ATL thunk has a signature of WNDPROC. See the following sample for more info on an implementation.

```cpp
 LRESULT CALLBACK AtlThunk(
   _In_ HWND   hwnd,
   _In_ UINT   uMsg,
   _In_ WPARAM wParam,
   _In_ LPARAM lParam
   )
 {
   static void* FirstParameter;
   static WNDPROC Proc;
   return Proc((HWND)FirstParameter, uMsg, wParam, lParam);
 }

```

An arbitrary number of AtlThunk functions can be created; FirstParameter and Proc are set (differently) for each one.
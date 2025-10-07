# SHIsChildOrSelf function

## Description

\[This function is available through Windows XP and Windows Server 2003.
It might be altered or unavailable in subsequent versions of Windows.\]

Compares whether a window is equal to, a child of, or a descendant of, a second window.

```cpp
HRESULT SHIsChildOrSelf(
  _In_ HWND hwndParent,
  _In_ HWND hwnd
);
```

## Parameters

### hwndParent [in]

Type: **HWND**

A handle to the first window.

### hwnd [in]

Type: **HWND**

A handle to a window to be tested against *hwndParent*.

## Returns

Type: **HRESULT**

Returns **S_OK** if the window specified by *hwnd* is equal to, a child of, or a descendent of the window specified by *hwndParent*.
Returns **S_FALSE** if the window specified by hwnd is not equal to, not a child of, and not a descendent of the window specified by *hwndParent*.
The return value is undefined if either window handle is invalid.

## Remarks

## See also

[IsChild](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ischild)
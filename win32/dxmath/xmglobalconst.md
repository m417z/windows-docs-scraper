# XMGLOBALCONST macro

Declares an object to be a *pick-any* constant, to avoid redundant reloads of that object if it is used (and declared) in multiple places in the DirectXMath Library.

## Remarks

Using XMGLOBALCONST permits the specification of global constants. This helps to reduce the size of an application's data segment, avoid redundant object creation and destruction, and reduce load and store operations.

## Requirements

**Header:** Declared in DirectXMath.h.

## Related topics

[DirectXMath Library Macros](https://learn.microsoft.com/windows/win32/dxmath/ovw-xnamath-reference-macros)

[Global Constants in the DirectXMath Library](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-internals)

[selectany](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa273550(v=vs.60))

[declspec](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa273692(v=vs.60))


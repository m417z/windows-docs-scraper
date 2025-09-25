## Description

Increments the reference count for an interface pointer to a COM object. You should call this method whenever you make a copy of an interface pointer

## Return value

The method returns the new reference count. This value is intended to be used only for test purposes.

## Remarks

A COM object uses a per-interface reference-counting mechanism to ensure that the object doesn't outlive references to it. You use **AddRef** to stabilize a copy of an interface pointer. It can also be called when the life of a cloned pointer must extend beyond the lifetime of the original pointer. The cloned pointer must be released by calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)) on it.

The internal reference counter that **AddRef** maintains should be a 32-bit unsigned integer.

### Notes to callers

Call this method for every new copy of an interface pointer that you make. For example, if you return a copy of a pointer from a method, then you must call **AddRef** on that pointer. You must also call **AddRef** on a pointer before passing it as an in-out parameter to a method; the method will call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(refiid_void)) before copying the out-value on top of it.

## See also

* [IUnknown interface](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)
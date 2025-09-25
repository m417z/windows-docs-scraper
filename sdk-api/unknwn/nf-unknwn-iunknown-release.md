## Description

Decrements the reference count for an interface on a COM object.

## Return value

The method returns the new reference count. This value is intended to be used only for test purposes.

## Remarks

When the reference count on an object reaches zero, **Release** must cause the interface pointer to free itself. When the released pointer is the only (formerly) outstanding reference to an object (whether the object supports single or multiple interfaces), the implementation must free the object.

Note that aggregation of objects restricts the ability to recover interface pointers.

### Notes to callers

Call this method when you no longer need to use an interface pointer. If you are writing a method that takes an in-out parameter, call **Release** on the pointer you are passing in before copying the out-value on top of it.

## See also

* [IUnknown interface](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)
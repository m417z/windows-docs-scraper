# IModelIterator::Reset

## Description

The Reset method on an iterator returned from the iterable concept will restore the position of the iterator to where it was when the iterator was first created (before the first element). While it is strongly recommended that iterator's support the Reset method, it is not required. An iterator can be the equivalent of a C++ input iterator and only allow a single pass of forward iteration. In such case, the Reset method may fail with E_NOTIMPL.

## Return value

This method returns HRESULT.

## Remarks

**Code Sample**

```cpp
IFACEMETHOD(Reset)()
{
    // It is legal for an iterator to be unable to Reset().  E_NOTIMPL can
    // be returned in that case.  If an iterator is capable of a reset, it
    // should always prefer to implement such.
    m_position = 0;
    return S_OK;
}
```

## See also

[IModelIterator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodeliterator)
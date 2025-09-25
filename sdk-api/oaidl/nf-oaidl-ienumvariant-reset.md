# IEnumVARIANT::Reset

## Description

Resets the enumeration sequence to the beginning.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | Failure. |

## Remarks

There is no guarantee that exactly the same set of variants will be enumerated the second time as was enumerated the first time. Although an exact duplicate is desirable, the outcome depends on the collection being enumerated. You may find that it is impractical for some collections to maintain this condition (for example, an enumeration of the files in a directory).

#### Examples

The following code implements **IEnumVariant::Reset**. A complete example implementation of the **IEnumVariant** interface is available in the COM Fundamentals Lines sample (Enumvar.cpp).

```cpp
STDMETHODIMP
CEnumVariant::Reset()
{
   m_lCurrent = m_lLBound;
   return NOERROR;
}
```

## See also

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)
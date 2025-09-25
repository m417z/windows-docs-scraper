# IModelObject::Compare

## Description

The Compare method compares two model objects and returns an indication of how those objects relate. One of three states is returned:

```text
	< 0: (this < other)

	== 0: (this == other)

	> 0: (this > other)
```

Note that only intrinsic values can be compared using this method. Calling with any other object type will result in failure.

## Parameters

### `other`

The object to compare this object to. The instance object is on the left side of the comparison and the object supplied by this argument is on the right.

### `ppResult`

The result of the comparison is returned here. If less than zero, this < other; if equal to zero, this == other; if greater than zero, this > other.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spValue1; /* get some ordinal */
ComPtr<IModelObject> spValue2; /* get some other ordinal */

ComPtr<IModelObject> spResult;
if (SUCCEEDED(spValue1->Compare(spValue2.Get(), &spResult)))
{
    VARIANT vtVal;
    if (SUCCEEDED(spResult->GetIntrinsicValueAs(VT_I4, &vtVal)))
    {
        int compVal = vtVal.lVal;

        // compVal < 0 : spValue1 < spValue2
        // compVal == 0: spValue1 == spValue2
        // compVal > 0 : spValue1 > spValue2
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)
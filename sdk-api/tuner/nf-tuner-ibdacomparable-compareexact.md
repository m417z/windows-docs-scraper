# IBDAComparable::CompareExact

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **CompareExact** method compares two objects to determine whether they contain the same tuning information.

## Parameters

### `CompareTo` [in]

Pointer to the **IDispatch** interface of the object that is to be compared with the object that implements the **IBDAComparable** interface.

### `Result` [out]

Pointer to a variable that receives the result of the comparison. If the result is 0, the two objects are the same. If the result is nonzero, the two objects are not the same.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method compares two objects to determine whether they contain the same tuning properties. The first object in the comparison is the object that implements the **IBDAComparable** interface that the method is called on. The *CompareTo* parameter specifies the second object.

This method compares all of the tuning properties of the two objects and their associated objects. In contrast, the [CompareEquivalent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ibdacomparable-compareequivalent) method compares only a subset of these properties.

For example, DirectShow implements the **IBDAComparable::CompareExact** method for a tune-request object to include both the tuning space and locator in the comparison. Thus, two DVB tuning requests are the same only if they both tune to the same DVB URL (with the same original network ID, transport stream ID, and service ID) *and* have the same modulation type.

## See also

[IBDAComparable Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable)
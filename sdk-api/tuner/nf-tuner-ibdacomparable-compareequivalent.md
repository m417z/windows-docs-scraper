# IBDAComparable::CompareEquivalent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

**Note**This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **CompareEquivalent** method compares two objects to determine whether they contain equivalent tuning information.

## Parameters

### `CompareTo` [in]

Pointer to the **IDispatch** interface of the object that is to be compared with the object that implements the [IBDAComparable](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable) interface.

### `dwFlags` [in]

Specifies whether to alter the default equivalence comparison. Setting this parameter to 0 invokes the default behavior. Setting this parameter to the bitwise OR of one or more [BDA_Comp_Flags](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-comp-flags) enumeration values overrides the default behavior.

### `Result` [out]

Receives the result of the comparison. If the result is 0, the two objects are equivalent. If the result is nonzero, the two objects are not equivalent.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method compares two objects to determine whether they have equivalent tuning properties. The first object in the comparison is the object that implements the [IBDAComparable](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable) interface that the method is called on. The *CompareTo* parameter specifies the second object.

To determine whether the two objects contain equivalent tuning information, this method compares a subset of the tuning properties of the two objects and their associated objects. In contrast, the [CompareExact](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ibdacomparable-compareexact) method compares all of these properties.

The tuning information is *equivalent* if the information in either object tunes to the same content. The implementation of the equivalence comparison depends on the object type.

For example, DirectShow implements the **IBDAComparable::CompareEquivalent** method for a tune-request object to include the tuning space in the default comparison but not to include the locator. Thus, two DVB tuning requests are equivalent if they both tune to the same DVB URL (with the same original network ID, transport stream ID, and service ID) regardless of whether they have the same modulation type.

## See also

[IBDAComparable Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable)
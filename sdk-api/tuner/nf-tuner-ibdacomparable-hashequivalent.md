# IBDAComparable::HashEquivalent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **HashEquivalent** method generates a hash code for a subset of the tuning properties of an object.

## Parameters

### `dwFlags` [in]

Specifies whether to alter the subset of properties that are to be incorporated by default into the hash code. Setting this parameter to 0 invokes the default behavior. Setting this parameter to the bitwise **OR** of one or more [BDA_Comp_Flags](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-comp-flags) enumeration values overrides the default behavior.

### `Result` [out]

Pointer to a variable that receives the result of the hash operation. This result is the hash code for the subset of the tuning properties of the object and its associated objects that are to be included in comparisons with other objects.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method generates a hash code from a subset of the tuning properties in the object that implements the [IBDAComparable](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable) interface, and its associated objects.

The caller can compare the resulting hash code to the hash code for another object of the same type to determine whether the two objects contain equivalent tuning information. The hash code incorporates only the subset of properties in the object and its associated objects that is required to determine whether the properties are equivalent to those in another object. If the hash codes for the two objects are identical, the two objects contain equivalent tuning information.

## See also

[HashEquivalentIncremental](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ibdacomparable-hashequivalentincremental)

[IBDAComparable Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable)
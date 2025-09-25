# IBDAComparable::HashExact

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **HashExact** method generates a hash code for all of the tuning properties of an object.

## Parameters

### `Result` [out]

Receives the result of the hash operation. This result is the hash code for the tuning properties of the object and its associated objects that are to be included in comparisons with other objects.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method generates a hash code from the values of the tuning properties in the object that implements the **IBDAComparable** interface, and its associated objects.

The caller can compare the resulting hash code to the hash code for another object of the same type to determine whether the two objects contain the same tuning information. The hash code incorporates the tuning properties in the object and its associated objects. If the hash codes for the two objects are identical, the two objects contain the same tuning information.

## See also

[HashExactIncremental](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ibdacomparable-hashexactincremental)

[IBDAComparable Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacomparable)
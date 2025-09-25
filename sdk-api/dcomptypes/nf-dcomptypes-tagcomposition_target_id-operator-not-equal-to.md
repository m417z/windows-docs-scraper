## Description

Compares the values of two `COMPOSITION_TARGET_ID` objects to see if they contain different values.

## Parameters

### `rhs`

A reference to the `COMPOSITION_TARGET_ID` object that is compared to this one.

## Return value

`TRUE` if this composition target ID and the composition target ID specified by _rhs_ contain different values; otherwise, `FALSE`.

## Remarks

The `COMPOSITION_TARGET_ID` comparison operators (== != < <= > >=) have been overloaded to compare the values of two `COMPOSITION_TARGET_ID` objects.

The `uniqueId` value is considered to be the same if either `COMPOSITION_TARGET_ID` has a `uniqueID` of 0.

## See also
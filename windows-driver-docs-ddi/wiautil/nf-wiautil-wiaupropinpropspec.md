# wiauPropInPropSpec function

## Description

The **wiauPropInPropSpec** function determines whether a specified property specification ID is contained in an array of such values. The function optionally gets the index at which the property specification ID was found.

## Parameters

### `NumPropSpecs`

Specifies the number of property specification IDs in the array pointed to by *pPropSpecs*.

### `pPropSpecs`

Points to the first element of the property specification ID array.

### `PropId`

Specifies the property specification ID to search for in the array pointed to by *pPropSpecs*.

### `pIdx`

*Optional*. Pointer to a memory location that receives the index of the property specification ID in the property specification ID array. The default value of this parameter is **NULL**, in which case the function does not use it.

## Return value

This function returns **TRUE** if it found the property specification ID in the property specification ID array. Otherwise it returns **FALSE**.

## Remarks

The **wiauPropInPropSpec** function finds a single property specification ID within an array of property specification IDs. A related function, [wiauPropsInPropSpec](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaupropsinpropspec) can be used to determine whether any of a specified list of property specification IDs is found in another array of property specification IDs.

## See also

[wiauPropsInPropSpec](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaupropsinpropspec)
# wiauPropsInPropSpec function

## Description

The **wiauPropsInPropSpec** function determines whether any of a list of property specification IDs is contained within an array of such values.

## Parameters

### `NumPropSpecs`

Specifies the number of property specification IDs in the array pointed to by the *pPropSpecs* parameter.

### `pPropSpecs` [in]

Points to the first element of the array of property specification IDs.

### `NumProps`

Specifies the number of property specification IDs to search for.

### `pProps` [in]

Points to the first element of the array containing the property specification IDs to search for.

## Return value

This function returns **TRUE** as soon as it finds one of the property specification IDs given in the *pProps* array in the *pPropSpecs* array. If the function is unable to find any of the listed property specification IDs in that array, it returns **FALSE**.

## Remarks

The **wiauPropsInPropSpec** function finds one or more property specification IDs within an array of property specification IDs. A related function, [wiauPropInPropSpec](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaupropinpropspec), can be used to find a single property specification ID within such an array.

## See also

[wiauPropInPropSpec](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaupropinpropspec)
# ResUtilFreeParameterBlock function

## Description

Deallocates memory that has been allocated for a [parameter block](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks) by [ResUtilDupParameterBlock](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutildupparameterblock).

## Parameters

### `pOutParams` [in, out]

Pointer to the parameter block to deallocate.

### `pInParams` [in]

Pointer to the parameter block to use as a reference.

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures describing the properties in the input parameter block.

## Remarks

The **ResUtilFreeParameterBlock** utility function deallocates any memory allocated to each member of *pOutParams*, subject to the following limitations:

* It will only deallocate memory for members referenced in the *pPropertyTable* input parameter.
* It will not deallocate memory that is pointed to by any member of *pInParams*.

Do not use this function with parameter blocks that have not been allocated with [ResUtilDupParameterBlock](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutildupparameterblock).

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)

[ResUtilDupParameterBlock](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutildupparameterblock)
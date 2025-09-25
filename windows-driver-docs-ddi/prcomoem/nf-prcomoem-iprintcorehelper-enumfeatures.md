## Description

The **IPrintCoreHelper::EnumFeatures** method gets a list of all available features, including synthesized and core driver-implement features.

## Parameters

### `pFeatureList` [out]

A pointer to an array of ANSI character strings that contain all of the features that are available for the current device. The final array element is indicated by a **NULL** string. The array elements should be considered constants. The caller does not need to provide a buffer for the array, nor should the caller release the array.

### `pdwNumFeatures` [out]

A pointer to a variable that receives the number of feature keywords in the array that is pointed to by the *pFeatureList* parameter.

## Return value

**IPrintCoreHelper::EnumFeatures** should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

For Unidrv features, the feature list is based on the GPD view of the configuration file, so features that are surrounded by **Ifdef GDL_ENABLED** / **Endif** directives are not visible and will not be reported by **IPrintCoreHelper::EnumFeatures**.

## See also

[IPrintCoreHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelper)

[IPrintCoreHelper::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-enumoptions)
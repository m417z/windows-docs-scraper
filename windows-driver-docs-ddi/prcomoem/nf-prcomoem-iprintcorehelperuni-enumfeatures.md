## Description

The **IPrintCoreHelperUni::EnumFeatures** method gets a list of all available features, including synthesized and core driver-implement features.

## Parameters

### `pFeatureList` [out]

A pointer to an array of ANSI character strings that contain all of the features that are available for the current device. The final array element is indicated by a **NULL** string.

### `pdwNumFeatures` [out]

A pointer to a variable that receives the number of feature keywords in the array that is pointed to by the *pFeatureList* parameter.

## Return value

**IPrintCoreHelperUni::EnumFeatures** should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

For Unidrv features, the feature list is based on the GPD view of the configuration file, so features that are surrounded by **Ifdef GDL_ENABLED / Endif** directives cannot be configured by using this method.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-enumoptions)
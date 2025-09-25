## Description

The **IPrintCoreHelperPS::EnumFeatures** method gets a list of all available features, including synthesized and core driver-implement features.

## Parameters

### `pFeatureList` [out]

A pointer to an array of ANSI character strings that contain all of the features that are available for the current device. The final array element is indicated by a **NULL** string.

### `pdwNumFeatures` [out]

A pointer to a variable that receives the number of feature keywords in the array that is pointed to by the *pFeatureList* parameter.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## See also

[IPrintCoreHelperPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps)

[IPrintCoreHelperPS::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-enumoptions)
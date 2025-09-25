## Description

The **IPrintCoreHelperUni::EnumOptions** method gets a list of available options for the given feature.

## Parameters

### `pszFeatureKeyword` [in]

An ANSI character string that contains the feature whose options are requested.

### `pOptionList` [out]

A pointer to an array of ANSI character strings that contain all of the options for the feature specified in the *pszFeatureKeyword* parameter. **IPrintCoreHelperUni::EnumOptions** is responsible for allocating the memory for the array. The last element of the array must be a **NULL** string.

### `pdwNumOptions` [out]

A pointer to a variable that receives the number of options in the option array that is pointed to by the *pOptionList* parameter.

## Return value

**IPrintCoreHelperUni::EnumOptions** should return **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

When **IPrintCoreHelperUni::EnumOptions** returns, the option list contains all options, regardless of constraints or other factors.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::EnumConstrainedOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-enumconstrainedoptions)

[IPrintCoreHelperUni::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-enumfeatures)
# IPrintCoreHelperPS::WhyConstrained

## Description

The **IPrintCoreHelperPS::WhyConstrained** method provides a list of options that constrain the specified feature-option pair in the current configuration.

## Parameters

### `pDevmode` [in, optional]

A pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If this pointer is provided, **IPrintCoreHelperPS::WhyConstrained** should use the DEVMODEW structure that is pointed to by *pDevmode* instead of the default or current DEVMODEW structure. If this method is called from the plug-in provider or from [IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode), this parameter is required. In most other situations, the parameter should be **NULL**. When the core driver sets *pDevmode* to **NULL**, it modifies its internal state rather than that of the passed-in DEVMODEW structure. This is required during operations such as full UI replacement, where the DEVMODEW structure returned by a DDI, such as [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets), is being serviced by the core driver's UI module.

### `cbSize` [in]

The size, in bytes, of the DEVMODEW structure that is pointed to by the *pDevmode* parameter.

### `pszFeatureKeyword` [in]

A pointer to an ANSI string that contains the name of the feature. The feature name should correspond to the keyword that is used in the PPD file.

### `pszOptionKeyword` [in]

A pointer to an ANSI string that contains the name of the option. The option name should correspond to the keyword that is used in the PPD file.

### `ppFOConstraints` [out]

A pointer to an array of [PRINT_FEATURE_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/ns-prcomoem-_print_feature_option) elements. When **IPrintCoreHelperPS::WhyConstrained** returns, the array contains a list of feature-element pairs of the options that constrain the options that are specified in the *pszOptionKeyword* parameter.

### `pdwNumOptions` [out]

A pointer to a variable that receives the number of feature-option pairs in the array that is pointed to by the *ppFOConstraints* parameter.

## Return value

**IPrintCoreHelperPS::WhyConstrained** should return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_INVALIDARG** | One or more of the arguments is invalid, or the feature was not supported. |
| **E_OUTOFMEMORY** | Memory for the result array could not be allocated. |

For other failures, the method should return a standard COM error code.

## Remarks

If the specified feature-option pair is not constrained, **IPrintCoreHelperPS::WhyConstrained** will return S_OK but will return with **pdwFOPairs* set to 0 and with **ppFOConstraints*[0] set to **NULL**.

Note that the results from this method might not contain all of the options that affect the currently selected option. If there are invalid combinations, however, only one option from the combination will be included in the list.

## See also

[IPrintCoreHelperPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps)

[IPrintCoreHelperPS::EnumConstrainedOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-enumconstrainedoptions)
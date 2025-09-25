## Description

The **IPrintCoreHelperPS::EnumConstrainedOptions** method provides a list of all of the options that are constrained in a particular feature, based on current settings.

## Parameters

### `pDevmode` [in, optional]

A pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If this pointer is provided, **IPrintCoreHelperPS::EnumConstrainedOptions** should use the DEVMODEW structure that is pointed to by *pDevmode* instead of the default or current DEVMODEW structure. If this method is called from the plug-in provider or from [IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode), this parameter is required. In most other situations, the parameter should be **NULL**. When the core driver sets *pDevmode* to **NULL**, it modifies its internal state rather than that of the passed-in DEVMODEW structure. This is required during operations such as full UI replacement, where the DEVMODEW structure returned by a DDI, such as [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets), is being serviced by the core driver's UI module.

### `cbSize` [in]

The size, in bytes, of the DEVMODEW structure that is pointed to by the *pDevmode* parameter.

### `pszFeatureKeyword` [in]

A string of ANSI characters that contains the feature name.

### `pConstrainedOptionList` [out]

A pointer to an array of ANSI character strings. When **IPrintCoreHelperPS::EnumConstrainedOptions** returns, these strings will contain the names of all of the options that are constrained within the specified feature. The caller is not responsible for freeing the array or the individual strings in the array.

### `pdwNumOptions` [out]

A pointer to a variable that receives the number of constrained options in the array that is pointed to by the *pConstrainedOptionList* parameter.

## Return value

**IPrintCoreHelperPS::EnumConstrainedOptions** should return one of the following values.

| Return code | Description |
|--|--|
| **S_OK** | The constrained options were set for the specified feature. |
| **E_FAIL** | The caller provided information that resulted in an invalid request, such as a request for a feature that does not exist. |
| **E_INVALIDARG** | One or more of the arguments were invalid. This value might mean that the feature is not supported. |
| **E_OUTOFMEMORY** | There was not enough memory to create the options array or the core driver could not service the request because of lack of memory. |
| **E_UNEXPECTED** or other failures not listed here | An unexpected condition occurred. The core driver is probably in an invalid state. The caller should exit with a failure code. |

## See also

[IPrintCoreHelperPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperps)

[IPrintCoreHelperPS::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-enumoptions)
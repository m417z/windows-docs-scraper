# IPrintCoreHelper::GetOption

## Description

The **IPrintCoreHelper::GetOption** method gets a specified option for a given feature.

## Parameters

### `pDevmode` [in]

A pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If this pointer is provided, **IPrintCoreHelper::GetOption** should use the DEVMODEW structure that is pointed to by *pDevmode* instead of the default or current DEVMODEW structure. If this method is called from the plug-in provider or from either [IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode) or [IPrintOemUni::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-devmode), this parameter is required. In most other situations, the parameter should be **NULL**. When the core driver sets *pDevmode* to **NULL**, it modifies its internal state rather than that of the passed-in DEVMODEW structure. This is required during operations such as full UI replacement, where the DEVMODEW structure returned by a DDI, such as [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets), is being serviced by the core driver's UI module.

### `cbSize` [in]

The size, in bytes, of the DEVMODEW structure that is pointed to by the *pDevmode* parameter.

### `pszFeatureRequested` [in]

A pointer to the ANSI string that contains the name of the feature as it appears in the GPD file.

### `ppszOption` [out]

A pointer to a variable that contains the address of an ANSI string. When **IPrintCoreHelper::GetOption** returns, the string should contain the keyword for the currently selected option as it appears in the configuration file. The caller should not modify this string and should not free the memory that is associated with this string.

## Return value

**IPrintCoreHelper::GetOption** should return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method read the option for the specified feature. |
| **E_FAIL** | The caller provided information that resulted in an invalid request. For example, the feature that was requested does not exist. |
| **E_INVALIDARG** | The arguments were invalid. This value might mean that the feature is not supported or that too many options were requested for the feature. |
| **E_OUTOFMEMORY** | The core driver was not able to service the request because there was insufficient memory. |
| **E_UNEXPECTED, or other return codes not listed here** | The core driver seems to be in an invalid state. The caller should return a failure code. |

## Remarks

**IPrintCoreHelper::GetOption** cannot be used for features that allow multiple options to be set simultaneously.

Feature keywords are as defined in the GPD and PPD files. In addition, the Unidrv and Pscript5 drivers support several reserved keywords for options that are stored in their private [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structures.

The caller should not free the string that is pointed to by *ppszOption* and should not modify the string in any way.

## See also

[IPrintCoreHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelper)

[IPrintCoreHelper::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-enumoptions)

[IPrintCoreHelper::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-setoptions)
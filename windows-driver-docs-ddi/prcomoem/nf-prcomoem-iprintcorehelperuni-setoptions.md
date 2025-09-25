## Description

The **IPrintCoreHelperUni::SetOptions** method sets multiple feature-option pairs at the same time.

## Parameters

### `pDevmode` [in, optional]

A pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If this pointer is provided, **IPrintCoreHelperUni::SetOptions** should use the DEVMODEW structure that is pointed to by *pDevmode* instead of the default or current DEVMODEW structure. If this method is called from the plug-in provider or from [IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode), this parameter is required. In most other situations, the parameter should be **NULL**. When the core driver sets *pDevmode* to **NULL**, it modifies its internal state rather than that of the passed-in DEVMODEW structure. This is required during operations such as full UI replacement, where the DEVMODEW structure returned by a DDI, such as [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets), is being serviced by the core driver's UI module.

### `cbSize` [in]

The size, in bytes, of the **DEVMODEW** structure that is pointed to by the *pDevmode* parameter.

### `bResolveConflicts` [in]

A Boolean value that indicates whether **IPrintCoreHelperUni::SetOptions** should resolve conflicts that arise from one or more constraints in the GPD view of the configuration file, as well as constraints for functionality implemented by Unidrv or the print processor. If **TRUE**, this method should attempt to resolve the conflict. If **FALSE**, this method should not attempt to resolve conflicts.

### `pFOPairs` [in]

An array of [PRINT_FEATURE_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/ns-prcomoem-_print_feature_option) elements, where each element contains a feature-option pair. Each feature-option pair lists a feature and the option to select for that feature. All settings are applied sequentially. Duplicates are not disallowed, but settings that appear later in the array (that is, at a higher index) override those that appear earlier in the array.

### `cPairs` [in]

The number of feature-option pairs that are pointed to by the *pFOPairs* parameter.

### `pcPairsWritten` [out]

A pointer to a variable that receives the number of feature-option pairs that were successfully saved before **IPrintCoreHelperUni::SetOptions** returned or failed. If this method returns successfully, *pcPairsWritten* will have the same value as *cPairs*. If the method fails, *pcPairsWritten* can have any value from zero through the value of *cPairs*. This parameter is optional and can be **NULL**.

### `pdwResult` [out]

A pointer to a variable that receives the status of the conflict resolution. The status can be one of the following values.

| Value | Description |
|--|--|
| SETOPTIONS_RESULT_NO_CONFLICT | No constraint that was specified in the GPD view of the configuration file was violated, relative to the new setting. |
| SETOPTIONS_RESULT_CONFLICT_RESOLVED | At least one constraint that was specified in the GPD view of the configuration file was violated, and the caller requested that the method should resolve conflicts. This value results in changed settings with conflicts resolved. |
| SETOPTIONS_RESULT_CONFLICT_NOT_RESOLVED | At least one constraint that was specified in the GPD view of the configuration file was violated, and the caller requested that the method should not resolve conflicts. The settings do not change, and conflicts remain. |

## Return value

**IPrintCoreHelperUni::SetOptions** should return one of the following values.

| Return code | Description |
|--|--|
| **S_OK** | The operation succeeded. |
| **E_INVALIDARG** | One or more of the arguments is invalid, or the feature was not supported. |
| **E_OUTOFMEMORY** | Memory for the result array could not be allocated. |

For other failures, the method should return a standard COM error code.

## Remarks

**IPrintCoreHelperUni::SetOptions** can be used to make multiple settings changes simultaneously and to resolve constraints after all of the selected options have been set. Changes to options are applied sequentially, starting from the beginning of the *pFOPairs* array, so if the same feature appears twice in this array, only the last option for the feature will be selected. Changes to options are not committed unless the *bResolveConflicts* parameter is **TRUE**.

For most scenarios the *bResolveConflicts* parameter should be set to **TRUE**. Set this parameter to **FALSE** if you want to prompt the user to resolve conflicts.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::GetOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-getoption)
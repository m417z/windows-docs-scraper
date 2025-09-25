# _PRINT_FEATURE_OPTION structure

## Description

The PRINT_FEATURE_OPTION structure contains information about a feature-option pair, where the option is one option of a particular feature.

## Members

### `pszFeature`

The printing feature.

### `pszOption`

One of the options for the printing feature.

## Remarks

This structure is used by methods that belong to the **IPrintCoreHelper**, **IPrintCoreHelperPS**, and **IPrintCoreHelperUni** interfaces. The methods are listed in the See Also section.

## See also

[IPrintCoreHelper::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-setoptions)

[IPrintCoreHelper::WhyConstrained](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelper-whyconstrained)

[IPrintCoreHelperPS::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-setoptions)

[IPrintCoreHelperPS::WhyConstrained](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperps-whyconstrained)

[IPrintCoreHelperUni::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-setoptions)

[IPrintCoreHelperUni::WhyConstrained](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-whyconstrained)
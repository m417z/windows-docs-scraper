# IWDTFTarget2::get_Context

## Description

Gets and sets a name-value pair that represents user data for the target.

This property is read/write.

## Parameters

### `Tag`

### `pVal`

### Return value

## Remarks

The **Context** property is parameterized with the
**BSTR** *Tag* parameter. This parameterization
enables you to attach many different named values to an instance of the
[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2) interface.
You can then retrieve these same values by name at a later time.

Each value is stored as a **VARIANT**, which correctly
follows COM ref-counting rules. You can store object references within the target as
easily as any other variable data-type.

For more information about the **Context** property,
see [Creating WDTF Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdtf/creating-wdtf-scenarios).

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)
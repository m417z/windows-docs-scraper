# IWDTFTarget2::GetValue

## Description

Returns a value from the target that is associated with a specified attribute.

## Parameters

### `SDEL` [in]

An SDEL statement that specifies the attribute value to retrieve.

### `pValue` [out, retval]

The address of a variable that receives the result of this method.
The result can be any automation-compatible **VARIANT**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You specify the field that the **GetValue** method retrieves
by using a regular [SDEL](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview)
statement. Typically, an SDEL statement can contain comparison operators and value specifiers to
perform matches. However, you do not need these items for **GetValue**
to work properly.

For every field that is specified in the SDEL statement (including iterating over a
set of relations), this method collects a set of (non-**VT_EMPTY**)
**VARIANT** values. If only one value is found,
that **VARIANT** is returned. If more than one value is found,
the values are packaged into a **VARIANT** that contains a
**SAFEARRAY**. If no values are found, the method returns a
**VARIANT** that contains **VT_EMPTY**.

Additionally, the **AND** operator will permit collection
of the values on both sides of itself, but **OR** will allow collection
of only the first value found (starting with the left).

For more information about using **GetValue**,
see [Simple Data Evaluation Language Overview](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview).

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)
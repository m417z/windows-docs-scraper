# IWDTFTarget2::GetValueLongNumbers

## Description

Returns a collection of long number values from the target that are associated with a specified attribute.

## Parameters

### `SDEL` [in]

An SDEL statement that specifies the attribute value to retrieve.

### `ppValue` [out, retval]

The address of a variable that receives the result of this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You specify the field that the **GetValueLongNumbers** method retrieves
by using a regular [SDEL](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview)
statement. Typically, an SDEL statement can contain comparison operators and value specifiers to
perform matches. However, you do not need these items for **GetValueLongNumbers**
to work properly.

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)
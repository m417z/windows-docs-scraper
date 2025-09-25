# IWDTFTarget2::GetRelations

## Description

Returns a collection of related targets.

## Parameters

### `RelationSDEL` [in]

An SDEL statement that contains one or more relation tokens
that specify the desired targets.

### `MatchSDEL` [in]

The SDEL statement that each returned target must match.
If *MatchSDEL* is empty, all targets are returned.

### `ppRelations` [out, retval]

The address of the variable that will receive the
result of this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You use the **GetRelations** method to retrieve related
instances of the [IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2) interface.
You specify the desired targets by a relation
[SDEL](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview) statement.
Typically, an SDEL statement can contain attribute tokens, comparison operators,
and value specifiers to perform matches. However, you do not need these items in the
*RelationSDEL* parameter for the **GetRelations**
method to work properly (the *MatchSDEL* parameter follows the rules for
the [IWDTFTarget2::Eval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-eval) method).

The **IWDTFTarget2:GetRelations** method places every related
target that **GetRelations** finds by the *RelationSDEL*
statement into a new collection.

**GetRelations** returns only the subset of targets that satisfy the
*MatchSDEL* parameter constraints. If the *MatchSDEL*
parameter string is empty, **GetRelations** returns the entire collection of
targets. This process filters out all of the targets that return VARIANT_FALSE when you provide
*MatchSDEL* to the target's
[IWDTFTarget2::Eval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-eval) method.

For more information about using the **GetRelations** method,
see [Simple Data Evaluation
Language Overview](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview).

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)
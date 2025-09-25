# IXpsPartIterator::Current

## Description

The `Current` method provides the current URI and part.

## Parameters

### `pUri` [out]

A pointer to the URI of the part. If **NULL**, the *ppXpsPartparameter* might still be valid.

### `ppXpsPart` [out]

The current part in the iterator. If **NULL**, the *pUri* parameter might still be valid.

## Return value

`Current` returns an **HRESULT** value.

## Remarks

Filters should call the [IXpsPartIterator::IsDone](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ixpspartiterator-isdone) method before calling `Current`. One or both parameters can be **NULL**.
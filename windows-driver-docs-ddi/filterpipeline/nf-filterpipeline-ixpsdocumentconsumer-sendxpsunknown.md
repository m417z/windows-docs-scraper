# IXpsDocumentConsumer::SendXpsUnknown

## Description

The `SendXpsUnknown` method sends an XPS document part that cannot be identified to the filter pipeline.

## Parameters

### `pUnknown` [in]

A pointer to an unrecognized document part interface.

## Return value

`SendXpsUnknown` returns an HRESULT value.

## Remarks

If the [IXpsDocumentProvider::GetXpsPart](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ixpsdocumentprovider-getxpspart) method returns an object that the filter cannot identify, the filter should forward the unrecognized object to the next filter in the filter pipeline by calling `SendXpsUnknown`. Passing unrecognized objects to the next filter helps the filter maintain compatibility with future document formats.
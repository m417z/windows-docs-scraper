# IXpsDocumentProvider::GetXpsPart

## Description

The `GetXpsPart` method retrieves several objects that make up an XPS document.

## Parameters

### `ppIXpsPart` [out]

The XPS part. This part is the **IUnknown** interface of an object that is an XPS part. If *ppIXpsPart* is NULL, there are no more XPS parts to consume and the filter is ready to finish processing.

## Return value

`GetXpsPart` returns an **HRESULT**.

## Remarks

Use **QueryInterface** on the value that the **GetXpsPart** method returns to determine the type of object that it retrieved.
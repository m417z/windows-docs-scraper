# IPrintDocumentPackageTarget::GetPackageTargetTypes

## Description

Enumerates the supported target types.

## Parameters

### `targetCount` [out]

The number of supported target types.

### `targetTypes` [out]

The array of supported target types. An array of GUIDs.

## Return value

If the **GetPackageTargetTypes** method completes successfully, it returns an S_OK. Otherwise it returns the appropriate HRESULT error code.

## Remarks

In the case of a multi-format driver, the first GUID returned in the *targetTypes* array is the XPS format preferred by the driver.

## See also

[IPrintDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetarget)
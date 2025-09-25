# IPrintDocumentPackageTarget::GetPackageTarget

## Description

Retrieves the pointer to the specific document package target, which allows the client to add a document with the given target type. Clients can call this method multiple times but they always have to use the same target ID.

## Parameters

### `guidTargetType` [in]

The target type GUID obtained from [GetPackageTargetTypes](https://learn.microsoft.com/windows/desktop/api/documenttarget/nf-documenttarget-iprintdocumentpackagetarget-getpackagetargettypes).

### `riid` [in]

The identifier of the interface being requested.

### `ppvTarget` [out]

The requested document target interface. The returned pointer is a pointer to an [IXpsDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsdocumentpackagetarget) interface.

## Return value

If the **GetPackageTarget** method completes successfully, it returns an S_OK. Otherwise it returns the appropriate HRESULT error code.

## See also

[IPrintDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/documenttarget/nn-documenttarget-iprintdocumentpackagetarget)
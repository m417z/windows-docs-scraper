# IPlayToSourceClassFactory::CreateInstance

## Description

Creates an instance of the **PlayToController** object.

## Parameters

### `dwFlags` [in]

A bitwise **OR** of flags from the [PLAYTO_SOURCE_CREATEFLAGS](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/ne-mfsharingengine-playto_source_createflags) enumeration.

### `pControl` [in]

A pointer to the [IPlayToControl](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-iplaytocontrol) interface.

### `ppSource` [out]

Receives a pointer to the [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPlayToSourceClassFactory](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-iplaytosourceclassfactory)
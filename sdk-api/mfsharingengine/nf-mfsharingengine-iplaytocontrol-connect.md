# IPlayToControl::Connect

## Description

Connects the media element to the media sharing engine.

## Parameters

### `pFactory` [in]

A pointer to the [IMFSharingEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfsharingengineclassfactory) interface. The media element uses this interface to create the Sharing Engine.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPlayToControl](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-iplaytocontrol)
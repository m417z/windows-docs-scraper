# IWICStreamProvider::RefreshStream

## Description

Informs the component that the content of the stream it's holding onto may have changed. The component should respond by dirtying any cached information from the stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
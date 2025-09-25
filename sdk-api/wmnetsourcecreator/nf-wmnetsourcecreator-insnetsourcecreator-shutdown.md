# INSNetSourceCreator::Shutdown

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Shutdown** method properly disposes of all allocated memory used by the network source creator. You must call this method when you are finished using the network source creator, to ensure that all resources are released.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[INSNetSourceCreator Interface](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nn-wmnetsourcecreator-insnetsourcecreator)

[INSNetSourceCreator::Initialize](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nf-wmnetsourcecreator-insnetsourcecreator-initialize)
# INSNetSourceCreator::Initialize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Initialize** method prepares the network source creator for operations. You must call this method before calling any of the other methods in the **INSNetSourceCreator** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method could not allocate memory for an internal resource. |

## Remarks

When you are finished using the network source creator, you must call the [Shutdown](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nf-wmnetsourcecreator-insnetsourcecreator-shutdown) method to ensure that all resources are released properly.

## See also

[INSNetSourceCreator Interface](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nn-wmnetsourcecreator-insnetsourcecreator)

[INSNetSourceCreator::Shutdown](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nf-wmnetsourcecreator-insnetsourcecreator-shutdown)
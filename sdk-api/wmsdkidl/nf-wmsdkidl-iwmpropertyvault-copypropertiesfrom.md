# IWMPropertyVault::CopyPropertiesFrom

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CopyPropertiesFrom** method copies all of the properties from another property vault to this one.

## Parameters

### `pIWMPropertyVault` [in]

Pointer to an **IWMPropertyVault** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory needed to copy. |

## Remarks

Passing **NULL** as *pIWMPropertyVault* will result in unpredictable errors.

**CopyPropertiesFrom** makes calls to other methods of **IWMPropertyVault**. Because all of the data is coming from the objects themselves, no errors should be returned from the other methods. A return code that is not in the table indicates the corruption of data in the property vault from which you are copying.

## See also

[IWMPropertyVault Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpropertyvault)
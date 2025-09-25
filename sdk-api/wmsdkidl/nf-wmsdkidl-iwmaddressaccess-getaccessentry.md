# IWMAddressAccess::GetAccessEntry

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAccessEntry** method retrieves an entry from the IP address access list.

## Parameters

### `aeType` [in]

A member of the [WM_AETYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wm_aetype) enumeration specifying the type of entry to retrieve (exclusion or inclusion).

### `dwEntryNum` [in]

Specifies the zero-based index of the entry. Use the [IWMAddressAccess::GetAccessEntryCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmaddressaccess-getaccessentrycount) method to get the number of entries.

### `pAddrAccessEntry` [out]

Pointer to a [WM_ADDRESS_ACCESSENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_address_accessentry) structure that receives the access entry.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |
| **NS_E_INVALID_INDEX** | Invalid index number. |

## See also

[IWMAddressAccess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmaddressaccess)
# IWMAddressAccess2::GetAccessEntryEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAccessEntryEx** method retrieves an entry from the IP address access list.

## Parameters

### `aeType` [in]

A member of the [WM_AETYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wm_aetype) enumeration specifying the type of entry to retrieve (exclusion or inclusion).

### `dwEntryNum` [in]

Zero-based index of the entry. Use the [IWMAddressAccess::GetAccessEntryCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmaddressaccess-getaccessentrycount) method to get the number of entries.

### `pbstrAddress` [out]

Pointer to a variable that receives the IP address.

### `pbstrMask` [out]

Pointer to a variable that receives the bit mask.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

For more information about the meaning of the *pbstrAddress* and *pbstrMask* parameters, see [IWMAddressAccess2::AddAccessEntryEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmaddressaccess2-addaccessentryex).

The caller must release the returned **BSTR** values, by calling **SysFreeString**.

## See also

[IWMAddressAccess2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmaddressaccess2)
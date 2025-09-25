# IWMAddressAccess2::AddAccessEntryEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddAccessEntryEx** method adds an entry to the IP address access list.

## Parameters

### `aeType` [in]

A member of the [WM_AETYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wm_aetype) enumeration specifying the specifying the access permissions (exclusion or inclusion).

### `bstrAddress` [in]

Specifies an IP address as a **BSTR**, using standard "dot" notation. Both IPv4 and IPv6 addresses are supported. For example, `206.73.118.1` is an IPv4 address and `fe80::201:3ff:fee8:5058` is an IPv6 address.

### `bstrMask` [in]

Bit mask that defines which bits in the IP address are matched against. For example, if the IP address is `206.73.118.1` and the mask is `255.255.255.0`, only the first 24 bits of the address are examined. Thus, any IP addresses in the range 206.73.118.*XXX* would match this entry.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMAddressAccess2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmaddressaccess2)
# IWMPropertyVault::GetPropertyByName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetPropertyByName** method retrieves a property from the vault by its name.

## Parameters

### `pszName` [in]

Pointer to a **null**-terminated string containing the name of the property to be retrieved.

### `pType` [out]

Pointer to a member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. This parameter specifies the type of data pointed to by *pValue*.

### `pValue` [out]

Pointer to a data buffer containing the value of the property. This value can be one of several types. The type of data that the buffer contains on output is specified by the value of *pType*.

### `pdwSize` [in, out]

Pointer to a **DWORD** containing the size, in bytes, of the data at *pValue*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pszName* or *pdwSize* or *pType* is **NULL**.<br><br>OR<br><br>*pszName* contains an invalid property name. |
| **ASF_E_BUFFERTOOSMALL** | *pdwSize* specifies a size for *pValue* that is not large enough to hold the data. |

## Remarks

You must make two calls to **GetPropertyByName** to properly retrieve the value of the property. On the first call, pass **NULL** for *pValue*. When the call returns, *pdwSize* will point to the correct sizes of the buffer. Then on the second call, pass a properly sized buffer as *pValue* to receive the data.

## See also

[IWMPropertyVault Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpropertyvault)

[IWMPropertyVault::GetPropertyByIndex](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmpropertyvault-getpropertybyindex)

[IWMPropertyVault::SetProperty](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmpropertyvault-setproperty)
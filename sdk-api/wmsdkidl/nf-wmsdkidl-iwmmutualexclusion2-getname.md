# IWMMutualExclusion2::GetName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetName** method retrieves the name of the current mutual exclusion object. A mutual exclusion object has a name only if a name has been assigned using the [IWMMutualExclusion2::SetName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-setname) method.

## Parameters

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name of the mutual exclusion object. Pass **NULL** to retrieve the length of the name.

### `pcchName` [in, out]

On input, a pointer to a variable containing the length of the *pwszName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchName* parameter is **NULL**. |

## Remarks

You can pass *pwszName* as **NULL** to retrieve the correct size of the name in *pcchName* and then make another call to this method with a properly sized string. If you do, the value you pass as *pcchName* is irrelevant. It will be replaced with the correct length of the name.

If you pass an address as *pwszName*, and the length you specified in *pcchName* is shorter than the number of characters required to store the name, **GetName** ignores *pwszName* and returns the correct number of characters in *pcchName*. In this case the method still returns S_OK.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)
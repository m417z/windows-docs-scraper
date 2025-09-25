# IWMDRMReader3::GetInclusionList

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetInclusionList** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetInclusionList** method retrieves a list of identifiers specifying approved protection systems.

## Parameters

### `ppGuids` [out]

Address of a variable that receives a pointer to an array of identifiers. The array is allocated by using **CoTaskMemAlloc**. When finished with the list, release the memory by calling **CoTaskMemFree**.

### `pcGuids` [out]

Number of elements in the array received by the *ppGuids* parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The license issuer can specify other protection systems to which the encrypted content may be converted. The list of GUIDs retrieved by this method identifies the allowed protection systems. When you enter into a license agreement with Microsoft to get the stub library, you will receive a list of currently supported protection systems and the GUIDs used to identify them.

## See also

[IWMDRMReader3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader3)
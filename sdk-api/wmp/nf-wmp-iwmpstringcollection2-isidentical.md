# IWMPStringCollection2::isIdentical

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **isIdentical** method retrieves a value indicating whether the supplied object is the same as the current one.

## Parameters

### `pIWMPStringCollection2` [in]

Pointer to an **IWMPStringCollection2** interface that represents the object to compare with current one.

### `pvbool` [out]

Pointer to a **VARIANT_BOOL** that receives the result of the comparison. VARIANT_TRUE indicates that the objects are the same.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To use this method, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPStringCollection2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection2)
# IMFASFMultiplexer::SetFlags

## Description

Sets multiplexer options.

## Parameters

### `dwFlags` [in]

Bitwise **OR** of zero or more members of the [MFASF_MULTIPLEXERFLAGS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-mfasf_multiplexerflags) enumeration. These flags specify which multiplexer options to use. For more information, see "Multiplexer Initialization and Leaky Bucket Settings" in [Creating the Multiplexer Object](https://learn.microsoft.com/windows/desktop/medfound/creating-the-multiplexer-object).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)
# IMFASFMultiplexer::GetFlags

## Description

Retrieves flags indicating the configured multiplexer options.

## Parameters

### `pdwFlags` [out]

Receives a bitwise **OR** of zero or more values from the [MFASF_MULTIPLEXERFLAGS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-mfasf_multiplexerflags) enumeration. To set these flags, call [IMFASFMultiplexer::SetFlags](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-setflags).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Creating the Multiplexer Object](https://learn.microsoft.com/windows/desktop/medfound/creating-the-multiplexer-object)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)
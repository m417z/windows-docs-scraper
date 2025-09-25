# IMFStreamDescriptor::GetStreamIdentifier

## Description

Retrieves an identifier for the stream.

## Parameters

### `pdwStreamIdentifier` [out]

Receives the stream identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The stream identifier uniquely identifies a stream within a presentation. It does not change throughout the lifetime of the stream. For example, if the presentation changes while the source is running, the index number of the stream may change, but the stream identifier does not.

In general, stream identifiers do not have a specific meaning, other than to identify the stream. Some media sources may assign stream identifiers based on meaningful values, such as packet identifiers, but this depends on the implementation.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)
# IIsdbSIParameterDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies a service information (SI) parameter descriptor.

## Parameters

### `pbVal` [out]

Receives the tag value. For SI parameter descriptors, this value is 0xD7.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSIParameterDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparameterdescriptor)
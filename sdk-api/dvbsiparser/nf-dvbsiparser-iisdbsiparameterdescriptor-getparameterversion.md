# IIsdbSIParameterDescriptor::GetParameterVersion

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the version number of a parameter from a service information (SI) parameter descriptor. This version number is incremented by one each time the parameter is updated.

## Parameters

### `pbVal` [out]

Receives the version number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSIParameterDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparameterdescriptor)
# IIsdbDataContentDescriptor::GetSelectorBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the selector data from an Integrated Services Digital Broadcasting (ISDB) data content descriptor. The contents of the selector depend on the type of data transmitted in the data component.

## Parameters

### `bBufLength` [in]

Specifies the length of the buffer that receives the selector data.

### `pbBuf` [out]

Receives the selector data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Table J-1 in Annex J, *SERVICE INFORMATION FOR DIGITAL
BROADCASTING SYSTEM
ARIB STANDARD
ARIB, STD-B10, Version 4.6* shows the contents of this descriptor for different component types.

## See also

[IIsdbDataContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdatacontentdescriptor)
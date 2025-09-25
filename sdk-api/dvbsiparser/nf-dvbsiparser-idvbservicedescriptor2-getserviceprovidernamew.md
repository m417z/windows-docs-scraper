# IDvbServiceDescriptor2::GetServiceProviderNameW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a string containing the service provider name from a Digital Video Broadcast (DVB) service descriptor.

## Parameters

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrName` [out]

Receives the service provider name string as a **BSTR**. The caller must free the string by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbServiceDescriptor2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbservicedescriptor2)
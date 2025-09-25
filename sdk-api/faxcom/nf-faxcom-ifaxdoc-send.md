# IFaxDoc::Send

## Description

The **Send** method transmits the document specified by the [FileName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-filename-vb) property of a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The method can send the fax to the fax number specified by the [FaxNumber](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-faxnumber-vb) property.

## Parameters

### `pVal` [out, retval]

Type: **LONG***

Specifies a pointer to a variable to receive a unique number that identifies the queued job that will send the fax transmission.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [FileName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-filename-vb) property is required to send a fax transmission using a call to the **IFaxDoc::Send** method. The [FaxNumber](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-faxnumber-vb) property is also required. For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[IFaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxdoc)
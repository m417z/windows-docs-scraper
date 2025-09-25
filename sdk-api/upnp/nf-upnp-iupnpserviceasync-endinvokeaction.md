# IUPnPServiceAsync::EndInvokeAction

## Description

The **EndInvokeAction** method retrieves the results of a previous [BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction) operation and retrieves the resultant output arguments.

## Parameters

### `ullRequestID` [in, out]

On input, contains a reference to an empty array. On output, receives a reference to the array of service-specific output arguments. In the event the action doesn't have output arguments, this parameter contains an empty array.

**Note** Clear this parameter with [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

### `pvOutActionArgs` [in, out]

On input contains a reference to an empty array. On output, receives a reference to a VARIANT that contains the return value of the invoked action.

**Note** Clear this parameter with [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

### `pvRetVal` [in]

A 64-bit **ULONG** value that corresponds to the [BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction) operation initiated prior to this call.

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_TIMEOUT** | The device has not responded within the 30 second time-out period. |
| **UPNP_E_DEVICE_ERROR** | An unknown error has occurred. |
| **UPNP_E_INVALID_ARGUMENTS** | One or more of the arguments passed is invalid. |
| **UPNP_E_INVALID_ACTION** | This action is not supported by the device. |
| **UPNP_E_ERROR_PROCESSING_RESPONSE** | The device has sent a response that cannot be processed; for example, the response was corrupted. |
| **UPNP_E_PROTOCOL_ERROR** | An error occurred at the UPnP control-protocol level. |
| **UPNP_E_TRANSPORT_ERROR** | An HTTP error occurred. Use the [IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus) property to obtain the actual HTTP status code. <br><br>**Note** This error code is also returned when the SOAP response exceeds 100 kilobytes. |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## See also

[IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus)

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::BeginInvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-begininvokeaction)
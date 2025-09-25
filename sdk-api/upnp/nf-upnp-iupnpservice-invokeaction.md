# IUPnPService::InvokeAction

## Description

The
**InvokeAction** method invokes a method on the device.

## Parameters

### `bstrActionName` [in]

Specifies the method to invoke.

### `vInActionArgs` [in]

Specifies an array of input arguments to the method. If the action has no input arguments, this parameter must contain an empty array.

The contents of this array are service-specific.

### `pvOutActionArgs` [in, out]

On input, contains a reference to an empty array. On output, receives a reference to the array of output arguments. If the action has no output arguments, this parameter contains an empty array.

The contents of this parameter are service-specific.

Free this parameter with [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

### `pvRetVal` [in, out]

On input, contains a reference to an empty array. On output, receives a reference to a **VARIANT** that contains the return value of this action.

If the device returns an error after the action is invoked on it and this parameter is not set to **NULL**, this parameter will contain specific text describing the error upon return. For more information on the errors returned by devices, please refer to the [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes) documentation.

Free this parameter with [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in WinError.h or one of the UPnP-specific return values shown in the following table. Some of these values indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

| Return code | Description |
| --- | --- |
| **UPNP_E_ACTION_REQUEST_FAILED** | The device had an internal error; the request could not be executed. |
| **UPNP_E_DEVICE_ERROR** | An unknown error occurred. |
| **UPNP_E_DEVICE_TIMEOUT** | The device has not responded within the 30 second time-out period. |
| **UPNP_E_ERROR_PROCESSING_RESPONSE** | The device has sent a response that cannot be processed; for example, the response was corrupted. |
| **UPNP_E_INVALID_ACTION** | The action is not supported by the device. |
| **UPNP_E_INVALID_ARGUMENTS** | One or more of the arguments passed in *vInActionArgs* is invalid. |
| **UPNP_E_PROTOCOL_ERROR** | An error occurred at the UPnP control-protocol level. |
| **UPNP_E_TRANSPORT_ERROR** | An HTTP error occurred. Use the [IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus) property to obtain the actual HTTP status code.<br><br>**Note** This error code is also returned when the SOAP response exceeds 100 kilobytes. |

## Remarks

When an application invokes the method **InvokeAction**, it includes a list of arguments that should match the arguments expected by the service. The Control Point maps these **VARIANT** arguments to the required type. The following table shows the mappings that are used.

| Data type | Type returned by MSXML |
| --- | --- |
| **SDT_STRING** = 0 | **VT_BSTR** |
| **SDT_NUMBER** | **VT_BSTR** |
| **SDT_INT** | **VT_I4** |
| **SDT_FIXED_14_4** | **VT_CY** |
| **SDT_BOOLEAN** | **VT_BOOL** |
| **SDT_DATETIME_ISO8601** | **VT_DATE** |
| **SDT_DATETIME_ISO8601TZ** | **VT_DATE** |
| **SDT_DATE_ISO8601** | **VT_DATE** |
| **SDT_TIME_ISO8601** | **VT_DATE** |
| **SDT_TIME_ISO8601TZ** | **VT_DATE** |
| **SDT_I1** | **VT_I1** |
| **SDT_I2** | **VT_I2** |
| **SDT_I4** | **VT_I4** |
| **SDT_UI1** | **VT_UI1** |
| **SDT_UI2** | **VT_UI2** |
| **SDT_UI4** | **VT_UI4** |
| **SDT_R4** | **VT_FLOAT** |
| **SDT_R8** | **VT_DOUBLE** |
| **SDT_FLOAT** | **VT_DOUBLE** |
| **SDT_UUID** | **VT_BSTR** |
| **SDT_BIN_BASE64** | **VT_ARRAY** |
| **SDT_BIN_HEX** | **VT_ARRAY** |
| **SDT_CHAR** | **VT_UI2** (a wchar) |
| **SDT_URI** | **VT_BSTR** |

**Note** Parameters that receive values must not be passed a **NULL** value when the method is called.

**Note** A floating-point value sent by a device as an [out] argument or a return value will be changed when received by the control point. For example, consider a device with an action Action1Out_float that returns a single [out] floating-point argument. When a control point invokes this action, the device returns the value -234.567; however, the control point actually receives the value -234.567001342773 instead of the expected value -234.567.

To work around this issue, use r4 instead of float as the UPnP data type for non-integer numeric values.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)
# MI_DestinationOptions_GetEncodePortInSPN function

## Description

Gets the port's Service Principal Name encoding value.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `encodePort` [out]

The returned Boolean value. **MI_TRUE** means to include the server port in the Kerberos SPN; otherwise, **MI_FALSE** is returned.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.
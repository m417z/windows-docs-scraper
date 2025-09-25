# PWSD_SOAP_MESSAGE_HANDLER callback function

## Description

References a SOAP message handler for incoming messages. This is an internal function pointer, and it should not be used by WSDAPI clients or services.

## Parameters

### `thisUnknown`

Pointer to the object calling this function.

### `event`

A [WSD_EVENT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_event) structure containing the message to be handled.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
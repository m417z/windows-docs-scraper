# WSD_STUB_FUNCTION callback function

## Description

Describes a stub function used to handle an incoming message. This function should only be implemented in and used by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Parameters

### `server`

Pointer to the service object that was registered as a handler for messages of this type. Service objects are registered by calling one of the following methods: [IWSDDeviceHost::RegisterService](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-registerservice), [IWSDDeviceHost::AddDynamicService](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-adddynamicservice), or [IWSDServiceProxy::SubscribeToOperation](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdserviceproxy-subscribetooperation).

### `session`

Pointer to an [IWSDServiceMessaging](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsdservicemessaging) object used for sending a fault or message response.

### `event`

Pointer to a [WSD_EVENT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_event) structure that contains the data for the current request.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
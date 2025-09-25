# IFaxDevice::AnswerCall

## Description

The **IFaxDevice::AnswerCall** method causes the fax device to answer an incoming call.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IFaxDevice::AnswerCall** method will only work on a fax device on the local server. The method will work regardless of the value of the [ReceiveMode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-receivemode) property.

You can use this method to manually answer a call. You may use this method if the [ReceiveMode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-receivemode) property is set to answer manually, automatically, or not at all. The fax device must be idle for the incoming call to succeed.

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

If the method succeeds, the service has successfully accepted the request and has validated the parameters and the access rights. Method success does not indicate that the service answered the call and started to receive a fax. If the method succeeds but the service fails to answer a call on a device, as in the case when the device does not respond as expected, no notification is sent.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)
# WSDUdpRetransmitParams structure

## Description

Defines the parameters for repeating a message transmission.

## Members

### `ulSendDelay`

Time to wait before sending the first transmission, in milliseconds. Specify zero for no delay. Cannot be INFINITE.

### `ulRepeat`

Maximum number of transmissions to send. Specify a value between 1 and 256, inclusively.

### `ulRepeatMinDelay`

Minimum value of the range used to generate the initial delay value, in milliseconds. This value must be less than or equal to **ulRepeatMaxDelay**, can be zero, but cannot be INFINITE. See Remarks.

### `ulRepeatMaxDelay`

Maximum value of the range used to generate the initial delay value, in milliseconds. This value be less than or equal to **ulRepeatUpperDelay**, can be zero, but cannot be INFINITE. See Remarks.

### `ulRepeatUpperDelay`

Maximum delay to wait before sending message, in milliseconds. This value be can be zero, but cannot be INFINITE.

## Remarks

If **ulRepeatMinDelay**, **ulRepeatMaxDelay**, and **ulRepeatUpperDelay** are all zero, there is no delay in retransmission of the message.

WSD sends the first transmission after waiting **ulSendDelay**. WSD uses the other members to determine when to repeat the transmission, if necessary. WSD repeats the transmission up to **ulRepeat** times with increasing delays between transmission. WSD uses the **ulRepeatMinDelay**, **ulRepeatMaxDelay**, and **ulRepeatUpperDelay** members to determine the delay.

WSD generates a random delay value in the range **ulRepeatMinDelay** to **ulRepeatMaxDelay** and waits this amount of time before repeating the transmission. All subsequent repeat attempts then double the current delay value until **ulRepeatUpperDelay** is reached. For example, if the initial random delay value is 50 and the upper delay value is 250, the second attempt will wait 50 milliseconds, the third attempt will wait 100 milliseconds, the fourth attempt will wait 200 milliseconds, and the remaining attempts will wait 250 milliseconds.

For details on how WSD uses these values to send messages, see Appendix I of the [SOAP-over-UDP](https://schemas.xmlsoap.org/ws/2004/09/soap-over-udp/) specification.

## See also

[IWSDUdpMessageParameters::GetRetransmitParams](https://learn.microsoft.com/windows/desktop/api/wsdbase/nf-wsdbase-iwsdudpmessageparameters-getretransmitparams)

[IWSDUdpMessageParameters::SetRetransmitParams](https://learn.microsoft.com/windows/desktop/api/wsdbase/nf-wsdbase-iwsdudpmessageparameters-setretransmitparams)
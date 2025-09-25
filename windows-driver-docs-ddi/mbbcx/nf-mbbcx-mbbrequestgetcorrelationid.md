# MbbRequestGetCorrelationId function

## Description

Client drivers can call the **MbbRequestGetCorrelationId** method to correlate a pair of send and receive requests that exchange MBIM control messages between the MBBCx framework and the client driver.

## Parameters

### `Request`

A handle to the framework object that represents a request from the MBBCx framework, either to send a MBIM control command message to the device or to receive an MBIM control response message from the device.

## Return value

Returns a GUID value.

The GUID's purpose is similar to the **TransactionId** field of the MBIM message header defined in the MBIM specification. The MBBCx framework provides this value, so the client driver is not required to parse the MBIM message if some sort of correlation is needed.

## Remarks

The MBBCx framework calls into the client driver to issue an MBIM command message, and later calls into the client driver again to retrieve the response message for that command. The GUID value returned for both calls will be the same, and it would only change if a new command and response message pair is requested.

Sometimes, the command and response message pair might get fragmented due to size limitations. In that case, all fragments from the same pair will have the same GUID value.

## See also
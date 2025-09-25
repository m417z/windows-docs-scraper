# WSD_APP_SEQUENCE structure

## Description

Represents application sequence information relating to WS-Discovery messages.

## Members

### `InstanceId`

The instance identifier.

### `SequenceId`

The sequence identifier.

### `MessageNumber`

The message number.

## Remarks

The application sequencing header block allows a receiver to maintain the sequence messages that contain this header block though they may have been received out of order. This allows proper sequencing of [Hello](https://learn.microsoft.com/windows/desktop/WsdApi/hello-message) and [Bye](https://learn.microsoft.com/windows/desktop/WsdApi/bye-message) messages from a target service.

The normative outline for the application sequence header block is:

``` syntax
<s:Envelope ...>
  <s:Header ...>
    <d:AppSequence InstanceId='xs:nonNegativeInteger' [SequenceId='xs:anyURI']? MessageNumber='xs:nonNegativeInteger' ... />
  </s:Header>
  <s:Body ...> ...
  </s:Body>
</s:Envelope>
```

The following describes normative constraints of this outline.

`/s:Envelope/s:Header/d:AppSequence/@InstanceId`

This setting must be incremented by a value of at least 1 each time the service has terminated, lost state, and been restored. An application can set this value by using a counter that is incremented each time a service is restarted. The restart time of the service is expressed as seconds elapsed since 12:00 a.m. January 1, 1970.

`/s:Envelope/s:Header/d:AppSequence/@SequenceId`

This setting identifies a sequence within the context of an instance identifier. If it is omitted, the implied value is the null sequence. The value in this setting must be unique within ./@InstanceId.

`/s:Envelope/s:Header/d:AppSequence/@MessageNumber`

This setting identifies a message within the context of a sequence identifier and an instance identifier. must be incremented by a value of at least 1 for each message sent. Retransmission of this message at the transport level must maintain this value.

## See also

[AppSequence Validation Rules](https://learn.microsoft.com/windows/desktop/WsdApi/appsequence-validation-rules)
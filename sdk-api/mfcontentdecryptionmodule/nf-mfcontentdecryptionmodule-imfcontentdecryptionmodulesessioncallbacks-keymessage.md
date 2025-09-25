## Description

Called when the Content Decryption Module (CDM) has generated a message for the session.

## Parameters

### `messageType`

A value from the [MF_MEDIAKEYSESSION_MESSAGETYPE](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_mediakeysession_messagetype) enumeration specifying the type of the message.

### `message`

A pointer to a **BYTE** array containing the message contents. Messages are Key System-specific.

### `messageSize`

The size of the array in the *message* parameter.

### `destinationURL`

A optional parameter containing the destination URL.

## Return value

Returns an HRESULT.

## Remarks

**KeyMessage** is based on the Encrypted Media Extension specification's [MediaKeyMessageEvent](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeymessageevent).

## See also
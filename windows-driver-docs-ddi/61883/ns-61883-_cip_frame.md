# _CIP_FRAME structure

## Description

The CIP_FRAME structure describes a frame to be attached to an input or output plug.

## Members

### `Reserved`

### `pNext`

Reserved for internal use.

### `Flags`

Specifies options associated with this frame.

For packets to be received, **Flags** can be one of the following:

#### CIP_VALIDATE_FIRST_SOURCE

Instructs the IEC-61883 protocol driver to call the client-driver-supplied function at **pfnValidate** to validate only the first source packet.

#### CIP_VALIDATE_ALL_SOURCE

Instructs the IEC-61883 protocol driver to call the client-driver-supplied function at **pfnValidate** to validate all source packets.

For packets to be received, CIP_VALIDATE_XXX can be combined with either or both of the following:

#### CIP_STRIP_SOURCE_HEADER

Instructs the protocol driver to strip the source header packet within a source packet.

#### CIP_USE_SOURCE_HEADER_TIMESTAMP

Instructs the protocol driver to timestamp the frame with the timestamp found within the source header packet.

For packets to be transmitted, **Flags** can be one of the following:

#### CIP_DV_STYLE_SYT

The value at **TimeStamp** is formatted for data transmission to digital video devices (SD-DVCR, HD-DVCR, or SDL-DVCR).

#### CIP_AUDIO_STYLE_SYT

The value at **TimeStamp** is formatted for audio and music data transmission to audio devices.

For packets to be transmitted or received, **Flags** can also be set with the following:

#### CIP_RESET_FRAME_ON_DISCONTINUITY

Instructs the protocol driver to resume a stopped stream at the beginning of the frame instead of the next source packet.

### `pfnValidate`

Points to a caller-supplied function to validate a source packet. This function uses the following prototype: The parameter **ValidateInfo** must point to a [CIP_VALIDATE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_validate_info) structure that contains information about the frame.

```
ULONG
  (*PCIP_VALIDATE_ROUTINE) (
    IN PCIP_VALIDATE_INFO ValidateInfo
   );
```

### `ValidateContext`

Points to an optional caller-defined context for the function at **pfnValidate**. If the function does not require a context, **ValidateContext** can be **NULL**.

### `pfnNotify`

Points to a caller-supplied function to be called by the protocol driver when the requested frame is completed. The protocol driver calls this function at IRQL = DISPATCH_LEVEL.

This function uses the following prototype:

```
ULONG
  (*PCIP_NOTIFY_ROUTINE) (
     IN PCIP_NOTIFY_INFO NotifyInfo
 );
```

### `NotifyContext`

Points to an optional caller-defined context for the caller-supplied function at **pfnNotify**. If the function does not require a context, **NotifyContext** can be **NULL**.

### `Timestamp`

The time associated with completion of the frame.

For packets to be received, the protocol driver sets this member to the time when transmission of the frame was completed, unless CIP_USE_SOURCE_HEADER_TIMESTAMP is set in **Flags**.

For packets to be transmitted, CIP-DV_STYLE_SYT or CIP_AUDIO_STYLE_SYT in **Flags** indicates the format of the timestamp.

### `Status`

The status of the frame. Can be one of the following:

CIP_STATUS_SUCCESS

CIP_STATUS_CORRUPT_FRAME

CIP_STATUS_FIRST_FRAME

### `Packet`

Points to the beginning of a caller-allocated data buffer to be transmitted or received with this frame. The frame length specified in the associated [Av61883_AttachFrame](https://msdn.microsoft.com/library/windows/hardware/ff536950) request indicates the size of the buffer.

### `CompletedBytes`

## See also

[AV_61883_REQUEST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)
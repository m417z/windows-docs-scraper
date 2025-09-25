# MI_DestinationOptions_AddDestinationCredentials function

## Description

Sets the credentials for talking to the destination.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) structure that contains the destination options.

### `credentials` [in]

A pointer to a [MI_UserCredentials](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_usercredentials) structure that contains the credentials used when communicating with the destination machine.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

The credentials supported will vary depending on the destination, the protocol and the transport. If dual-factor authentication is required this method can be called twice. The default credentials will vary depending on the protocol and transport selected.
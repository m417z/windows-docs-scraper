# _DXVA_EncryptProtocolHeader structure

## Description

The DXVA_EncryptProtocolHeader structure is sent by the host decoder to the accelerator to indicate use of an encryption protocol.

## Members

### `dwFunction`

Indicates whether encryption is being used and the operation to which encryption applies. The 24 most significant bits of **dwFunction** indicate that an encryption protocol is being used. These bits must be 0xFFFF00 when sent by the host software decoder, and 0xFFFF08 when sent by the accelerator. The 8 least significant bits of **dwFunction** contain a [bDXVA_Func](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) variable that indicates the operation to which the encryption protocol applies. Currently, the only relevant defined value of *bDXVA_Func* for use in these bits is 1, which indicates that the encryption protocol applies to compressed picture decoding.

There are only two possible values for **dwFunction** in this structure: 0xFFFF0001 when sent by a host software decoder, and 0xFFFF0801 when sent by the hardware accelerator.

### `ReservedBits`

Reserved bits used for packing and alignment. This must be zero.

### `guidEncryptProtocol`

Contains the GUID associated with the encryption protocol.

## Remarks

The encryption protocol in use is externally defined and operates as described in [Encryption Support](https://learn.microsoft.com/windows-hardware/drivers/display/encryption-support).
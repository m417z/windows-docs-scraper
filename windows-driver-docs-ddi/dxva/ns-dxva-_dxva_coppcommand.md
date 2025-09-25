# _DXVA_COPPCommand structure

## Description

The DXVA_COPPCommand structure describes a command sent to a protected video session that is associated with a COPP DirectX VA device.

## Members

### `macKDI`

Specifies a message authentication code (MAC) GUID for the command at **CommandData**. The display driver can use the MAC to verify that the transmission of the command was secure (that is, it was not tampered with in transit to the driver).

### `guidCommandID`

Specifies the GUID that identifies the command. The following GUIDs are supported:

#### DXVA_COPPSetProtectionLevel

Sets the protection type and level on the physical connector associated with the COPP device.

The DXVA_COPPSetProtectionLevel GUID is defined as follows:

```cpp
DEFINE_GUID(DXVA_COPPSetProtectionLevel,
    0x9bb9327c,0x4eb5,0x4727,0x9f,0x00,0xb4,0x2b,0x09,0x19,0xc0,0xda);
```

#### DXVA_COPPSetSignaling

An instruction about how to protect the signal that goes through the physical connector associated with the DirectX VA COPP device.

The DXVA_COPPSetSignaling GUID is defined as follows:

```cpp
DEFINE_GUID(DXVA_COPPSetSignaling,
    0x9a631a5,0xd684,0x4c60,0x8e,0x4d,0xd3,0xbb,0xf,0xb,0xe3,0xee);
```

### `dwSequence`

Specifies a sequence number. For the [COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/display/coppcommand) function to process the command, the value in **dwSequence** must match the 32-bit random starting status sequence number that was passed in the [DXVA_COPPSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsignature) structure to the [COPPSequenceStart](https://learn.microsoft.com/windows-hardware/drivers/display/coppsequencestart) function.

### `cbSizeData`

Specifies the size, in bytes, of the command data at **CommandData**.

### `CommandData`

Specifies an array that comprises the command data.

## Remarks

For a DXVA_COPPSetProtectionLevel command, the protection information is supplied in the first 16 bytes of the **CommandData** array (the protection type in the first 4 bytes, the protection level in the next 4 bytes, and possibly some extended information in the last 8 bytes). In the call to the [COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/display/coppcommand) function, the **CommandData** array should be cast to a pointer to a [DXVA_COPPSetProtectionLevelCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsetprotectionlevelcmddata) structure, which contains protection type, protection level, and extended information members.

For a DXVA_COPPSetSignaling command, the signaling information is supplied by casting the **CommandData** array to a pointer to a [DXVA_COPPSetSignalingCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsetsignalingcmddata) structure.

## See also

[COPPCommand](https://learn.microsoft.com/windows-hardware/drivers/display/coppcommand)

[COPPSequenceStart](https://learn.microsoft.com/windows-hardware/drivers/display/coppsequencestart)

[DXVA_COPPSetProtectionLevelCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsetprotectionlevelcmddata)

[DXVA_COPPSetSignalingCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsetsignalingcmddata)

[DXVA_COPPSignature](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsignature)
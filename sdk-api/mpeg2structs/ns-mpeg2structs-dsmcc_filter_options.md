# DSMCC_FILTER_OPTIONS structure

## Description

The **DSMCC_FILTER_OPTIONS** structure specifies additional filtering criteria for the DSM-CC portions of the section header.

## Members

### `fSpecifyProtocol`

If this flag is **TRUE**, the protocolDiscriminator field in the header must match the value of the **Protocol** structure member. Otherwise, the protocolDiscriminator field is ignored.

### `Protocol`

Specifies a value for the protocolDiscriminator field. For MPEG-2 DSM-CC messages, this field must equal 0x11.

### `fSpecifyType`

If this field is **TRUE**, the dsmccType field in the header must match the value of the **Type** structure member. Otherwise, the dsmccType field is ignored.

### `Type`

Specifies a value for the dsmccType field, which defines the DSM-CC message type.

### `fSpecifyMessageId`

If this flag is **TRUE**, the messageId field in the header must match the value of the **MessageId** structure member. Otherwise, the messageId field is ignored.

### `MessageId`

Specifies a value for the messageId field, which defines the DSM-CC message within the scope of the message type.

### `fSpecifyTransactionId`

If this flag is **TRUE**, the transactionId (or downloadId) field in the header must match the value of the **TransactionId** structure member. Otherwise, the transactionId/downloadId field is ignored.

### `fUseTrxIdMessageIdMask`

If this flag is **TRUE**, the transactionId bits are masked so that the following subfields are ignored:

* Updated flag
* Version

The following subfields are matched against the **TransactionId** structure member:

* Identification
* Originator

For more information about the subfields within the transactionId, see section 4.6.5 of TR 101 202, *Digital Video Broadcasting (DVB); Implementation Guidelines for Data Broadcasting*. (This resource may not be available in some languages

and countries.)

This flag is ignored if **fSpecifyTransactionId** is **FALSE**.

### `TransactionId`

Specifies a value for the transactionId field.

### `fSpecifyModuleVersion`

If this flag is **TRUE**, the moduleVersion field in the header must match the value of the **ModuleVersion** structure member. Otherwise, the moduleVersion field is ignored.

### `ModuleVersion`

Specifies a value for the moduleVersion field.

### `fSpecifyBlockNumber`

If this flag is **TRUE**, the blockNumber field in the header must match the value of the BlockNumber structure member. Otherwise, the moduleVersion field is ignored.

### `BlockNumber`

Specifies a value for the blockNumber field.

### `fGetModuleCall`

If this flag is **TRUE**, the **NumberOfBlocksInModule** structure member specifies the number of blocks in the module. Applies only to download data block (DDB) messages.

### `NumberOfBlocksInModule`

Specifies the number of blocks in the module. Applies only to DDB messages.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)

[MPEG2_FILTER Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg2_filter)
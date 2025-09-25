# _NFC_CX_SEQUENCE enumeration

## Description

The NFC_CX_SEQUENCE enumeration specifies sequences.

## Constants

### `SequencePreInit`

This sequence is invoked by CX during the idle to init state transition, that is, prior to start of initialization by NFC CX. No NCI commands including CORE_RESET_CMD have been sent to the NFC controller by NFC CX. In this sequence, the client can invoke any non-NCI command. NCI commands should not be sent to the controller because neither CORE_RESET_CMD nor CORE_INIT_CMD has been sent to the controller.

### `SequenceInitComplete`

This sequence is invoked by CX during the idle to init state transition, that is, prior to start of initialization by NFC CX. No NCI commands including CORE_RESET_CMD has been sent to the NFC controller by NFC CX. In this sequence, the client can invoke any non-NCI command. NCI commands should not be sent to the controller since neither CORE_RESET_CMD nor CORE_INIT_CMD has been sent to the controller.

### `SequencePreRfDiscStart`

This sequence is invoked by CX prior to start of RF discovery i.e. through RF_DISCOVER_CMD. The client driver can use this opportunity to perform any related RF configuration including any optimizations to the discovery loop.

### `SequenceRfDiscStartComplete`

This sequence is invoked by CX immediately after the start of RF discovery. Any configuration post-discovery start can be supported through this extensibility point.

### `SequencePreRfDiscStop`

This sequence is invoked by CX prior to stopping the RF discovery loop.

### `SequenceRfDiscStopComplete`

This sequence is invoked immediately after discovery loop is stopped. The client driver can use this extensibility point to enable any standby mode configuration.

### `SequencePreNfceeDisc`

This sequence is invoked by CX prior to start of NFCEE discovery. The NFCEE discovery happens with the discovery loop deactivated. The client driver can use this sequence to enable any internal NFC-NFCEE interfaces which could have been disabled post-initialization for power optimizations.

### `SequenceNfceeDiscComplete`

This sequence is invoked immediately post-NFCEE discovery operation.

### `SequencePreShutdown`

This sequence is invoked prior to start of shutdown.

### `SequenceShutdownComplete`

This sequence is invoked by CX after shutdown sequence is complete. The client driver can clean up any NCI state maintained.

### `SequencePreRecovery`

This sequence is invoked by CX if it needs to perform a recovery sequence due to a fatal failure. The client driver can use this sequence to capture RAM dumps for diagnostic purposes.

### `SequenceRecoveryComplete`

This sequence is invoked by the CX after the completion of the recovery sequence and when the driver is back to the work-state.

### `SequenceMaximum`

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)
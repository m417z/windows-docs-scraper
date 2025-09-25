# _SMARTCARD_EXTENSION structure

## Description

The **SMARTCARD_EXTENSION** structure is used by both the smart card reader driver and the smart card driver library to access all other smart card data structures.

## Members

### `Version`

Indicates the version of this structure.

### `VendorAttr`

Contains information that identifies the reader driver, such as the vendor name, unit number, and serial number.

### `ReaderFunction`

The line in the syntax block should read `NTSTATUS (*ReaderFunction[16])(PSMARTCARD_EXTENSION);`

A pointer to an array of callback functions for readers. The callback functions that a vendor-supplied reader driver can implement. A reader driver makes these callback functions available for the smart card library routine, [SmartcardDeviceControl](https://learn.microsoft.com/previous-versions/ff548939(v=vs.85)), to call by storing pointers to them in the smart card device extension.

*RDF_ATR_PARSE*

*RDF_CARD_EJECT*

*RDF_CARD_POWER*

*RDF_CARD_TRACKING*

*RDF_IOCTL_VENDOR*

*RDF_READER_SWALLOW*

*RDF_SET_PROTOCOL*

*RDF_TRANSMIT*

For more information, see Remarks.

### `CardCapabilities`

Contains capabilities of the inserted smart card.

### `LastError`

Not used.

### `IoRequest`

 A structure with the following members:

### `IoRequest.Information`

Contains the number of bytes returned.

### `IoRequest.RequestBuffer`

A pointer to the data in the user's I/O request to be sent to the card.

### `IoRequest.RequestBufferLength`

Indicates the number of bytes to send to the card.

### `IoRequest.ReplyBuffer`

A pointer to the buffer that holds the data that is returned by the I/O request.

### `IoRequest.ReplyBufferLength`

Indicates the number of bytes of the data that are returned by the I/O request.

### `MajorIoControlCode`

Contains the major I/O control code.

### `MinorIoControlCode`

Contains the minor I/O control code.

### `OsData`

Contains information that is specific to the operating system and the driver type.

### `ReaderCapabilities`

Contains the capabilities of the keyboard reader.

### `ReaderExtension`

Contains data that is specific to the smart card reader.

### `SmartcardReply`

Contains data that comes from the reader.

### `SmartcardRequest`

Contains the current command and the data that is sent to the smart card.

### `T0`

Contains the data for use with the T=0 protocol.

### `T1`

Contains the data that is used with the T=1 protocol.

### `PerfInfo`

### `Reserved`

Reserved for system use.

## Remarks

This structure is passed to all callback functions.

 Individual callback functions are identified by a series of constant values that should be used as indexes into the **ReaderFunction** array.

| Index | Description |
| --- | --- |
| RDF_ATR_PARSE | Optional. The RDF_ATR_PARSE parse function parses an answer-to-reset (ATR) for the smart card driver library when the driver library is unable to recognize or parse the smart card driver library. |
| RDF_CARD_EJECT | Optional. RDF_CARD_EJECT callback function<br><br>The RDF_CARD_EJECT callback function ejects an inserted smart card from the reader. |
| RDF_CARD_POWER | The RDF_CARD_POWER callback function resets or turns off an inserted smart card.It is mandatory for smart card reader drivers to implement this callback function. <br><br>On input, the structure pointed to by **SmartcardExtension** should have the following member values: <br><br>**MajorIoControlCode**<br><br>Should have a value of [IOCTL_SMARTCARD_POWER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548907(v=vs.85)).<br><br>**IoRequest.ReplyBufferLength**<br><br>Should contain the length of the buffer.<br><br>**MinorIoControlCode**<br><br>Should have one of the following minor codes:<br><br>SCARD_COLD_RESET<br><br>Performs a cold reset of the smart card.<br><br>SCARD_WARM_RESET<br><br>Performs a warm reset of the smart card.<br><br>SCARD_POWER_DOWN<br><br>Turns off smart card power.<br><br>On output, the structure pointed to by **SmartcardExtension** should have the following values:<br><br>**IoRequest.ReplyBuffer**<br><br>Receives the ATR that is returned by the smart card. In addition, you must transfer the ATR to *SmartcardExtension->CardCapabilities.ATR.Buffer* so that the library can parse the ATR.<br><br>**IoRequest.Information**<br><br>Receives the length of the ATR.<br><br>**CardCapabilities.ATR.Length**<br><br>Contains the length of the ATR. |
| RDF_CARD_TRACKING | The RDF_CARD_TRACKING callback function installs an event handler to track every time a card is inserted in or removed from a card reader.It is mandatory for smart card reader drivers to implement this callback function. <br><br>Upon receiving an [IOCTL_SMARTCARD_IS_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_is_present) request, the driver library determines if the smart card is already present. If the smart card is present, the driver library completes the request with a status of STATUS_SUCCESS. If there is no smart card present, the driver library calls the reader driver's smart card tracking callback function, and the reader driver starts looking for the smart card. After initiating smart card tracking, the driver library marks the request as having a status of STATUS_PENDING. <br><br>The driver library completes the request.<br><br>**WDM Device Drivers**<br><br>The corresponding WDM driver library adds a pointer to the request in **SmartcardExtension->OsData->NotificationIrp**. The reader driver must complete the request as soon as it detects that a smart card has been inserted or removed. The reader driver completes the request by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest), after which, the reader driver must set the **NotificationIrp** member of **SmartcardExtension -> OsData** back to **NULL** to inform the driver library that the reader driver can accept further smart card tracking requests. <br><br>Because this call can have an indefinite duration and the caller can terminate the request before it is complete, it is important to mark this IRP as cancelable.<br><br>``` MyDriverCardSupervision( SmartcardExtension,  OtherParameters) // //    This function is called whenever the card status changes //    For example, the card has been inserted or the card has been removed // {     if (SmartcardExtension->OsData->NotificationOverlappedData != NULL){<br><br>        SmartcardCompleteCardTracking(SmartcardExtension);     }     //     // Do additional tasks     // } ``` |
| RDF_IOCTL_VENDOR | The RDF_IOCTL_VENDOR callback function performs vendor-specific IOCTL operations.It is optional for smart card reader drivers to implement this callback function. <br><br>On input, the caller must pass the following values to the function:<br><br>**SmartcardExtension->MajorIoControlCode**<br><br>Contains a vendor-specific IOCTL code. Refer to the macro SCARD_CTL_CODE in *Winsmcrd.h* for information about how to define a vendor-specific IOCTL code. Note that the code must be between 2048 and 4095.<br><br>**SmartcardExtension->IoRequest.RequestBuffer**<br><br>A pointer to the user's input buffer.<br><br>**SmartcardExtension->IoRequest.RequestBufferLength**<br><br>The size, in bytes, of the user's input buffer.<br><br>**SmartcardExtension->IoRequest.ReplyBuffer**<br><br>A pointer to the user's output buffer.<br><br>**SmartcardExtension->IoRequest.ReplyBufferLength**<br><br>The size, in bytes, of the user's output buffer.<br><br>**SmartcardExtension->IoRequest.Information**<br><br>The value supplied by the request. Must be set to the number of bytes returned.<br><br>As with all other IOCTLs, a user-mode application dispatches a vendor-defined IOCTL to a smart card reader device by calling the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function. When the IOCTL is vendor-defined, however, the application must first open the reader device for "overlapped" (that is, asynchronous) access. The application must also define an OVERLAPPED structure and pass it to the system in the last argument of **DeviceIoControl** (The OVERLAPPED structure is also described in the Windows SDK documentation.). When the operating system calls the driver's I/O control dispatch routine, it passes a DIOCPARAMETERS structure to the driver. The **lpoOverlapped** member of the DIOCPARAMETERS structure contains a pointer to the OVERLAPPED structure. |
| RDF_READER_SWALLOW | The RDF_READER_SWALLOW callback function performs a mechanical swallow, which is what happens when the smart card is fully inserted into the smart card reader.It is optional for smart card reader drivers to implement this callback function. |
| RDF_SET_PROTOCOL | The RDF_SET_PROTOCOL callback function selects a transmission protocol for the inserted smart card.Smart card reader drivers must implement this callback function. <br><br>On input, the caller must pass the following values to the function:<br><br>**SmartcardExtension->MajorIoControlCode**<br><br>Contains [IOCTL_SMARTCARD_SET_PROTOCOL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548909(v=vs.85)).<br><br>**SmartcardExtension->MinorIoControlCode**<br><br>Contains a bitwise OR of one or more protocols than the caller accepts. The driver must select a protocol that the inserted smart card supports. We recommend that the T = 1 protocol is given precedence over the T = 0 protocol. <br><br>| Value | Meaning | | --- | --- | | SCARD_PROTOCOL_RAW | Selects the raw protocol. | | SCARD_PROTOCOL_T0 | Selects the ISO T = 0 protocol. | | SCARD_PROTOCOL_T1 | Selects the ISO T = 1 protocol. |<br><br>**SmartcardExtension->IoRequest.ReplyBufferLength**<br><br>Contains the length of the reply buffer.<br><br>**SmartcardExtension->CardCapabilities.PtsData**<br><br>Contains the required parameters to perform the PTS request. For more information, see [PTS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_pts_data).<br><br>The request returns the following values:<br><br>**SmartcardExtension->IoRequest.ReplyBuffer**<br><br>Contains the selected protocol.<br><br>**SmartcardExtension->IoRequest.Information**<br><br>Set to **sizeof**(ULONG).<br><br>The caller can supply a mask of acceptable protocols. The driver's set protocol callback routine selects one of the protocols in the mask and returns the selected protocol in **SmartcardExtension->IoRequest.ReplyBuffer**. |
| RDF_TRANSMIT | The RDF_TRANSMIT callback function performs data transmissions.Smart card reader drivers must implement this callback function. <br><br>On input, the caller must pass the following values to the function:<br><br>**SmartcardExtension->MajorIoControlCode**<br><br>Contains [IOCTL_SMARTCARD_TRANSMIT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548911(v=vs.85)).<br><br>**SmartcardExtension->IoRequest.RequestBuffer**<br><br>A pointer to an SCARD_IO_REQUEST structure followed by data to transmit to the card.<br><br>**SmartcardExtension->IoRequest.RequestBufferLength**<br><br>The number of bytes to transmit to the card.<br><br>**SmartcardExtension->IoRequest.ReplyBufferLength**<br><br>The size, in bytes, of the reply buffer.<br><br>The request returns the following values:<br><br>**SmartcardExtension->IoRequest.ReplyBuffer**<br><br>A pointer to the buffer that receives the SCARD_IO_REQUEST structure, plus the result of the card.<br><br>**SmartcardExtension->IoRequest.Information**<br><br>Receives the actual number of bytes returned by the smart card, plus the size of the SCARD_IO_REQUEST structure. For a definition of the SCARD_IO_REQUEST structure, see IOCTL_SMARTCARD_TRANSMIT.<br><br>When this function is called, **SmartcardExtension->IoRequest.RequestBuffer** points to an SCARD_IO_REQUEST structure followed by the data to transmit.<br><br>```cpp typedef struct _SCARD_IO_REQUEST{ DWORD dwProtocol; // Protocol identifier DWORD cbPciLength; // Protocol Control Information Length } SCARD_IO_REQUEST, *PSCARD_IO_REQUEST, *LPSCARD_IO_REQUEST; ```<br><br>The **dwProtocol** member must contain the protocol identifier that is returned by a call to IOCTL_SMARTCARD_SET_PROTOCOL. <br><br>The **cbPciLength** member contains the size, in bytes, of the SCARD_IO_REQUEST structure. The size of this structure is usually 8 bytes. <br><br>The SCARD_IO_REQUEST structure is followed by (protocol) data to transmit to the card. Depending on the protocol to use for the transmission, the library offers several support functions. For more information about these support functions, see SmartcardT0Request (WDM) and SmartcardT1Request (WDM). <br><br>*RequestBuffer* and *ReplyBuffer* point to the same system buffer. If you use the library function *SmartcardxxRequest* and *SmartcardxxReply*, you will not overwrite the input buffer. If you do not use these functions, make a copy of the *RequestBuffer* before you start transmissions.<br><br>You must copy the SCARD_IO_REQUEST structure to the *ReplyBuffer* parameter, followed by the data received from the card. Again, if you use the *SmartcardxxRequest* and *SmartcardxxReply* functions, the library will copy the structure for you. |
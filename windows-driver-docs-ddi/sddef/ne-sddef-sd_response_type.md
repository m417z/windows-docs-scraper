# SD_RESPONSE_TYPE enumeration

## Description

The SD_RESPONSE_TYPE enumeration lists the types of response data that a Secure Digital (SD) card returns in response to a command.

## Constants

### `SDRT_UNSPECIFIED`

Indicates that the response from the card is unspecified.

### `SDRT_NONE`

Indicates that the command does not require a response from the card.

### `SDRT_1`

Indicates a response of type R1 that contains 32 bits of card status information. For an explanation of the R1 response, see the *SD Card Association* specification.

### `SDRT_1B`

Indicates a response of type R1b that is identical to R1 with an optional busy signal transmitted on the data line. For an explanation of the R1b response, see the *SD Card Association* specification.

### `SDRT_2`

Indicates a response of type R2 that contains either the contents of the Card Identification Register (CID) or the contents of the Card Specific Data Register (CSD), depending on which command provoked the response. For an explanation of the R2 response, see the *SD Card Association* specification.

### `SDRT_3`

Indicates a response of type R3 that contains the contents of the operating condition register (OCR). For an explanation of the R3 response, see the *SD Card Association* specification.

### `SDRT_4`

Indicates a response of type R4 that contains the contents of the relative card address register. For an explanation of the R4 response, see the *SD Card Association* specification.

### `SDRT_5`

Indicates a response of type R5 that the card uses to notify the host of an interrupt request. If the host itself generates the interrupt request, the RCA field is 0x0. For an explanation of the R5 response, see the *SD Card Association* specification.

### `SDRT_5B`

Indicates a response of type R5b. For an explanation of the R5b response, see the *SD Card Association* specification.

### `SDRT_6`

Indicates a response of type R6. For an explanation of the R6 response, see the *SD Card Association* specification.

## See also

[**SDCMD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor)
# SCARD_READERSTATEW structure

## Description

The **SCARD_READERSTATE** structure is used by functions for tracking [smart cards](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) within [readers](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Members

### `szReader`

A pointer to the name of the reader being monitored.

Set the value of this member to "\\\\?PnP?\\Notification" and the values of all other members to zero to be notified of the arrival of a new smart card reader.

### `pvUserData`

Not used by the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This member is used by the application.

### `dwCurrentState`

Current [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the reader, as seen by the application. This field can take on any of the following values, in combination, as a bitmask.

| Value | Meaning |
| --- | --- |
| **SCARD_STATE_UNAWARE** | The application is unaware of the current [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), and would like to know. The use of this value results in an immediate return from state transition monitoring services. This is represented by all bits set to zero. |
| **SCARD_STATE_IGNORE** | The application is not interested in this reader, and it should not be considered during monitoring operations. If this bit value is set, all other bits are ignored. |
| **SCARD_STATE_UNAVAILABLE** | The application expects that this reader is not available for use. If this bit is set, then all the following bits are ignored. |
| **SCARD_STATE_EMPTY** | The application expects that there is no card in the reader. If this bit is set, all the following bits are ignored. |
| **SCARD_STATE_PRESENT** | The application expects that there is a card in the reader. |
| **SCARD_STATE_ATRMATCH** | The application expects that there is a card in the reader with an ATR that matches one of the target cards. If this bit is set, SCARD_STATE_PRESENT is assumed. This bit has no meaning to [SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea) beyond SCARD_STATE_PRESENT. |
| **SCARD_STATE_EXCLUSIVE** | The application expects that the card in the reader is allocated for exclusive use by another application. If this bit is set, SCARD_STATE_PRESENT is assumed. |
| **SCARD_STATE_INUSE** | The application expects that the card in the reader is in use by one or more other applications, but may be connected to in shared mode. If this bit is set, SCARD_STATE_PRESENT is assumed. |
| **SCARD_STATE_MUTE** | The application expects that there is an unresponsive card in the reader. |
| **SCARD_STATE_UNPOWERED** | This implies that the card in the reader has not been powered up. |

### `dwEventState`

Current [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), as known by the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). This field can take on any of the following values, in combination, as a bitmask.

| Value | Meaning |
| --- | --- |
| **SCARD_STATE_IGNORE** | This reader should be ignored. |
| **SCARD_STATE_CHANGED** | There is a difference between the state believed by the application, and the state known by the resource manager. When this bit is set, the application may assume a significant state change has occurred on this reader. |
| **SCARD_STATE_UNKNOWN** | The given reader name is not recognized by the resource manager. If this bit is set, then SCARD_STATE_CHANGED and SCARD_STATE_IGNORE will also be set. |
| **SCARD_STATE_UNAVAILABLE** | The actual state of this reader is not available. If this bit is set, then all the following bits are clear. |
| **SCARD_STATE_EMPTY** | There is no card in the reader. If this bit is set, all the following bits will be clear. |
| **SCARD_STATE_PRESENT** | There is a card in the reader. |
| **SCARD_STATE_ATRMATCH** | There is a card in the reader with an ATR matching one of the target cards. If this bit is set, SCARD_STATE_PRESENT will also be set. This bit is only returned on the [SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa) function. |
| **SCARD_STATE_EXCLUSIVE** | The card in the reader is allocated for exclusive use by another application. If this bit is set, SCARD_STATE_PRESENT will also be set. |
| **SCARD_STATE_INUSE** | The card in the reader is in use by one or more other applications, but may be connected to in shared mode. If this bit is set, SCARD_STATE_PRESENT will also be set. |
| **SCARD_STATE_MUTE** | There is an unresponsive card in the reader. |
| **SCARD_STATE_UNPOWERED** | This implies that the card in the reader has not been powered up. |

### `cbAtr`

Number of bytes in the returned ATR.

### `rgbAtr`

ATR of the inserted card, with extra alignment bytes.

## See also

[SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea)

[SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa)

## Remarks

> [!NOTE]
> The winscard.h header defines SCARD_READERSTATE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
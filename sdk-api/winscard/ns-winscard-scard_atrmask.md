# SCARD_ATRMASK structure

## Description

The **SCARD_ATRMASK** structure is used by
the [SCardLocateCardsByATR](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsbyatra) function to locate cards.

## Members

### `cbAtr`

The number of bytes in the ATR and the mask.

### `rgbAtr`

An array of **BYTE** values for the ATR of the card with extra alignment bytes.

### `rgbMask`

An array of **BYTE** values for the mask for the ATR with extra alignment bytes.
# DSMCC_ELEMENT structure

## Description

The **DSMCC_ELEMENT** structure contains information from a DSM-CC element.

## Members

### `pid`

Packet identifier (PID).

### `bComponentTag`

Component tag.

### `dwCarouselId`

Carousel identifier.

### `dwTransactionId`

Transaction identifier.

### `pNext`

Pointer to the next **DSMCC_ELEMENT** structure in the list, or **NULL** if this element is the end of the list.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)
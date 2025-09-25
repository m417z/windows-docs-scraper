# _CHANGER_ELEMENT_LIST structure

## Description

The CHANGER_ELEMENT_LIST structure indicates a range of elements of a single type.

## Members

### `Element`

Describes the first element of type [CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element) in a range **NumberOfElements** long.

### `NumberOfElements`

Specifies the number of elements in the range.

## Remarks

A changer class driver uses CHANGER_ELEMENT_LIST to indicate a range of elements of a single type, typically for an operation such as getting or initializing the status of multiple elements.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)
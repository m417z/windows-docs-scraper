# FILE_LINKS_INFORMATION structure

## Description

The **FILE_LINKS_INFORMATION** structure is used to query or set researchNTFS hard links to an existing file.

## Members

### `BytesNeeded`

The number of bytes needed to hold all available names returned in **Entry**. This value must be greater than 0.

### `EntriesReturned`

The number of [**FILE_LINK_ENTRY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_entry_information) structures that have been returned using the **Entry** member.

### `Entry`

A buffer that contains the returned [**FILE_LINK_ENTRY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_entry_information) structures.

## Remarks

If **EntriesReturned** has a value of 0, there is not enough available memory to return an entry. The error STATUS_BUFFER_OVERFLOW (0x80000005) indicates that not all available entries were returned.

**Entry** is the first [**FILE_LINK_ENTRY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_entry_information) structure in a list of entries. If an entry’s **NextEntryOffset** field has a value of 0, no further entries were returned; otherwise, the next entry returned is located **NextEntryOffset** bytes from the previous entry.

## See also

[**FILE_LINK_ENTRY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_link_entry_information)
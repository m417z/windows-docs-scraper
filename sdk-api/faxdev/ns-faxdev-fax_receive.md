## Description

The **FAX_RECEIVE** structure contains information about an inbound fax document. This information includes the name of the file that will receive the fax data stream, and the name and telephone number of the receiving device.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_RECEIVE** structure. Before calling the [FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive) function, the fax service sets this member to **sizeof**(**FAX_RECEIVE**). For more information, see the following Remarks section.

### `FileName`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the full path to the file in which the FSP must store the data stream of an inbound fax document. The data stream is a TIFF Class F file. For more information, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format). The fax service creates the file before it calls the [FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive) function. The FSP must specify the OPEN_EXISTING flag when opening this file.

### `ReceiverName`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the name of the receiving device. The FSP will send the name to the remote sending device after the receiving device receives an inbound fax. For more information, see the following Remarks section.

### `ReceiverNumber`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the telephone number of the receiving device. The FSP will send the number to the remote sending device after the receiving device receives an inbound fax. For more information, see the following Remarks section.

### `Reserved`

Type: **DWORD**

This member is reserved for future use by Microsoft. It must be set to zero.

## Remarks

The FSP must set the **ReceiverName** and **ReceiverNumber** members in this structure. The fax service allocates the memory for these strings. The size of the memory the service allocates is equal to **sizeof**(**FAX_RECEIVE**) + **FAXDEVRECEIVE_SIZE**. The FSP must place the strings in the block of memory that follows the **FAX_RECEIVE** structure. Note that you must allow for the size of the **FileName** string that follows immediately after the **FAX_RECEIVE** structure. The **ReceiverName** and **ReceiverNumber** members must point to the location of the strings in the memory block.

The following code sample and diagram illustrate how to fill in the memory that the fax service allocates.

```
PWSTR ReceiverName;
PWSTR ReceiverNumber;

//
// Routine to retrieve the receiver name
//   and receiver number here.

//
// Set the receiver name and receiver number data
//  in the FAX_RECEIVE structure; then
//  copy the data to the appropriate offset.
//
FaxReceive->ReceiverNumber = (LPWSTR) ( (LPBYTE)FaxReceive->FileName + sizeof(WCHAR)*(wcslen(FaxReceive->FileName) + 1));
wcscpy_s(  FaxReceive->ReceiverNumber, ReceiverNumber );

FaxReceive->ReceiverName = (LPWSTR) ( (LPBYTE)FaxReceive->ReceiverNumber+ sizeof(WCHAR)*(wcslen(FaxReceive->ReceiverNumber) + 1));
wcscpy_s(  FaxReceive->ReceiverName, ReceiverName );

```

![Filling in the memory that the fax service allocates](https://learn.microsoft.com/windows/win32/api/faxdev/images/faxover.png)
The FSP can reformat the **ReceiverName** and **ReceiverNumber** members and transmit the reformatted data to the remote sending device as the called subscriber identifier (CSI) to comply with the recommendation of the standards body of the International Telecommunication Union (ITU) from Study Group 8 (SG8). For more information, see the **RoutingInfo** and **CSI** members of the [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure.

## See also

[FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status)

[Fax Service Provider Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-structures)

[FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)
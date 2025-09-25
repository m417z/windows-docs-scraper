## Description

The **FAX_SEND** structure contains information about an outbound fax document. The structure contains the name of the file that holds the fax data stream, the name and telephone number of the calling device, and the name and telephone number of the receiving device.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies, in bytes, the size of the **FAX_SEND** structure. Before calling the [FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend) function, the fax service sets this member to **sizeof**(**FAX_SEND**).

### `FileName`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the full path to the file that contains the data stream for an outbound fax document. The data stream is a TIFF Class F file. For more information, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format).

### `CallerName`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the name of the calling device. The FSP will send this name to the remote receiving device when the FSP sends the fax. For more information, see the following Remarks section.

### `CallerNumber`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the telephone number of the calling device. (This number is also the TSID.) The FSP will send this number to the remote receiving device when the FSP sends the fax. For more information, see the following Remarks section.

### `ReceiverName`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the name of the device that will receive the outbound fax document.

### `ReceiverNumber`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the telephone number of the device that will receive the outbound fax document. This is the telephone number that the FSP will dial.

If you specify the **CallHandle** member, the **ReceiverNumber** member must be **NULL**.

### `Branding`

Type: **BOOL**

Reserved.

### `CallHandle`

Type: **HCALL**

Reserved; must be set to **NULL**.

### `Reserved`

Type: **DWORD**

This member is reserved by Microsoft. It must be set to zero.

## Remarks

The FSP can reformat the **CallerName** and **CallerNumber** members. The FSP can then transmit the reformatted data to the remote sending device as the called subscriber identifier (CSI) to comply with the recommendation of the standards body of the International Telecommunication Union (ITU) from Study Group 8 (SG8). For more information, see the **RoutingInfo** and **CSI** members of the [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure.

The FSP can also use the reformatted data to add a brand to the fax transmission.

## See also

[FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status)

[Fax Service Provider Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-structures)

[FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)
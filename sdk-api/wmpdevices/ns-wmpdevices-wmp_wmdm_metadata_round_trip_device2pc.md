# WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC structure

## Description

The **WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC** structure is used by Windows Media Player to receive accelerated metadata synchronization information from portable devices that do not support MTP.

## Members

### `dwCurrentTransactionID`

The current transaction ID for the device. Windows Media Player stores this value and uses it for future requests.

### `dwReturnedObjectCount`

The number of object path names returned in the **wsObjectPathnameList** member.

### `dwUnretrievedObjectCount`

The number of objects that were changed or deleted, but that are not part of this response. A value greater than zero signals Windows Media Player to make a further request.

### `dwDeletedObjectStartingOffset`

The index of the first character of the first deleted object path name. If the path name list contains only deleted objects, specify zero. If the path name list contains no deleted objects, specify the index of the last null character in the path name list. Note that this value is the number of Unicode characters to skip in **wsObjectPathnameList**, not the number of bytes.

### `dwFlags`

The status information. Status is indicated in a bitwise fashion by using the following flags.

| Value | Meaning |
| --- | --- |
| **WMP_MDRT_FLAGS_UNREPORTED_DELETED_ITEMS**<br><br>0x1 | Items were deleted before the first object path name being reported. This often indicates that the device was reformatted. |
| **WMP_MDRT_FLAGS_UNREPORTED_ADDED_ITEMS**<br><br>0x2 | Some additional items were added that were not returned in the list of PUOIDs. |

Bits 2 through 31 are reserved for future use. These bits should be set to zero.

### `wsObjectPathnameList`

Contains a contiguous list of null terminated Unicode path name strings, terminated with an extra null character. The list must be created in the following manner:

First, path name strings for all objects that have been added to the device or have had a change for the PlayCount, UserRating, or BuyNow attributes.

Second, path name strings for all objects that have been deleted. The index of the first character of this part of the list is contained in the **dwDeletedObjectStartingOffset** member.

## Remarks

The Windows Media Device Manager service provider should return as many object path names as will fit in the buffer size specified by the *pnOutBufferSize* parameter of the **DeviceIoControl** method. If the buffer is not large enough to contain the path name strings for all the changes, the device must set the **dwUnretrievedObjectCount** member to the appropriate (nonzero) value.

## See also

[Windows Media Device Manager Device Extensions for Metadata Transfer](https://learn.microsoft.com/windows/desktop/WMP/windows-media-device-manager-device-extensions-for-metadata-transfer)
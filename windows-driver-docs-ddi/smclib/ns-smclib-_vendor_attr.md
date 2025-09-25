# _VENDOR_ATTR structure

## Description

The VENDOR_ATTR structure defines the data that is stored in the **VendorAttr** member of the [SMARTCARD_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension) structure. VENDOR_ATTR also holds information that identifies the smart card reader, such as the vendor name, unit number, and serial number.

## Members

### `VendorName`

 A structure with the following members:

### `VendorName.Length`

Contains the length of the ANSI-coded name of the vendor. This member is required.

### `VendorName.Buffer`

Contains the ANSI-coded name of the vendor. Because a length field is provided, no terminating NULL character is necessary. This member is required.

### `IfdType`

 A structure with the following members:

### `IfdType.Length`

Contains the length of the ANSI-coded designation of the reader. This member is required.

### `IfdType.Buffer`

Contains the ANSI-coded reader name. This member is required.

### `UnitNo`

Contains the zero-based number of this unit. Because you can have more than one reader of this kind installed, **UnitNo** can distinguish the readers. This member is required.

### `IfdVersion`

 A structure with the following members:

### `IfdVersion.BuildNumber`

Contains the build number of the reader driver. This member can be used for support purposes and should be maintained only if the reader allows the value to be queried. This member is optional.

### `IfdVersion.VersionMinor`

Contains the minor version number of the reader driver. This member can be used for support purposes and should be maintained only if the reader allows the value to be queried. This member is optional.

### `IfdVersion.VersionMajor`

Contains the major version number of the reader driver. This member can be used for support purposes and should be maintained only if the reader allows the value to be queried. This member is optional.

### `IfdSerialNo`

 A structure with the following members:

### `IfdSerialNo.Length`

Contains the length of the serial number, in bytes, of the connected reader.

### `IfdSerialNo.Buffer`

A pointer to the serial number of the connected reader. This field should only be maintained if the reader allows the serial number to be queried. This member is optional.

### `Reserved`

Reserved for system use.
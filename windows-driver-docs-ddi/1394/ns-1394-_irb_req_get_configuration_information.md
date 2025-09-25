# _IRB_REQ_GET_CONFIGURATION_INFORMATION structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a GetConfigurationInformation request.

## Members

### `ConfigRom`

Points to the buffer that the bus driver uses to store a copy of the device's configuration ROM. The configuration ROM is defined by the *IEEE 1394-1995 Specification*

### `UnitDirectoryBufferSize`

Specifies the size, in bytes, of the buffer pointed to by the **UnitDirectory** member of **u.GetConfigurationInformation**. On completion, the bus driver fills in this member with the minimum of the buffer size passed in and the number of bytes of data that were actually available. If the **UnitDirectoryBufferSize**, **UnitDependentDirectoryBufferSize**, **VendorLeafBufferSize**, and **ModelLeafBufferSize** members of **u.GetConfigurationInformation** are all zero, the bus driver fills in this member with the minimum buffer size needed to hold all the available information.

### `UnitDirectory`

Points to where the bus driver returns the unit directory. See the *IEEE 1394-1995 Specification* for a description of the internals of the unit directory.

### `UnitDirectoryLocation`

Specifies the starting location of the unit directory.

### `UnitDependentDirectoryBufferSize`

Specifies the size of the buffer pointed to by **UnitDependentDirectory** member of **u.GetConfigurationInformation**. On completion, the bus driver fills in this member with the minimum of the buffer size passed in and the number of bytes of data that were actually available. If the **UnitDirectoryBufferSize**, **UnitDependentDirectoryBufferSize**, **VendorLeafBufferSize**, and **ModelLeafBufferSize** members of **u.GetConfigurationInformation** are all zero, the bus driver fills in this member with the minimum buffer size needed to hold all the information.

### `UnitDependentDirectory`

Points to a buffer that receives the unit dependent directory, as defined by the *IEEE 1394-1995 Specification*. See the *IEEE 1394-1995 Specification* for a description of the internals of the unit directory.

### `UnitDependentDirectoryLocation`

 The Unit Dependent Directory location for this device. Only the lower 48 bits are valid in this **IO_ADDRESS**.

### `VendorLeafBufferSize`

Specifies the size of the buffer pointed to by **VendorLeaf** member of **u.GetConfigurationInformation**. On completion, the bus driver fills in this member with the minimum of the buffer size passed in and the number of bytes of data that were actually available. If the **UnitDirectoryBufferSize**, **UnitDependentDirectoryBufferSize**, **VendorLeafBufferSize**, and **ModelLeafBufferSize** members of **u.GetConfigurationInformation** are all zero, the bus driver fills in this member with the minimum buffer size needed to hold all the information.

### `VendorLeaf`

Points to a buffer to receive the vendor leaf TEXTUAL_LEAF structure, which describes the device vendor.

### `ModelLeafBufferSize`

Specifies the size of the buffer pointed to by **ModelLeaf** member of **u.GetConfigurationInformation**. On completion, the bus driver fills in this member with the minimum of the buffer size passed in and the number of bytes of data that were actually available. If the **UnitDirectoryBufferSize**, **UnitDependentDirectoryBufferSize**, **VendorLeafBufferSize**, and **ModelLeafBufferSize** members of **u.GetConfigurationInformation** are all zero, the bus driver fills in this member with the minimum buffer size needed to hold all the information.

### `ModelLeaf`

Points to a buffer to receive the model leaf TEXTUAL_LEAF structure, which describes the device model type.
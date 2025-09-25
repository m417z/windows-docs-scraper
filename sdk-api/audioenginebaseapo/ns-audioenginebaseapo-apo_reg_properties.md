# APO_REG_PROPERTIES structure

## Description

The APO_REG_PROPERTIES structure is used by [IAudioProcessingObject::GetRegistrationProperties](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobject-getregistrationproperties) for returning the registration properties of an audio processing object (APO).

## Members

### `clsid`

The class ID for this APO.

### `Flags`

The flags for this APO. This parameter is an enumerated constant of type [APO_FLAG](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ne-audioenginebaseapo-apo_flag).

### `szFriendlyName`

The friendly name of this APO. This is a string of characters with a max length of 256.

### `szCopyrightInfo`

The copyright info for this APO. This is a string of characters with a max length of 256.

### `u32MajorVersion`

The major version number for this APO.

### `u32MinorVersion`

The minor version number for this APO.

### `u32MinInputConnections`

The minimum number of input connections for this APO.

### `u32MaxInputConnections`

The maximum number of input connections for this APO.

### `u32MinOutputConnections`

The minimum number of output connections for this APO.

### `u32MaxOutputConnections`

The maximum number of output connections for this APO.

### `u32MaxInstances`

The maximum number of instances of this APO.

### `u32NumAPOInterfaces`

The number of interfaces for this APO.

### `iidAPOInterfaceList`

## See also

[IAudioProcessingObject::GetRegistrationProperties](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobject-getregistrationproperties)
# KsUnserializeObjectPropertiesFromRegistry function

## Description

The **KsUnserializeObjectPropertiesFromRegistry** function, when given a destination object and a registry path, enumerates the named values and applies them as serialized data to the specified property sets listed in the serialized data. An IRP is generated when sending the serialized data, so no assumption is made on use of KS property structures to internally define the property sets. The function does not use the names of the values.

## Parameters

### `FileObject` [in]

Specifies the file object whose properties are being set.

### `ParentKey` [in, optional]

Optionally contains a handle to the parent of the path, or **NULL**. The Parent Key and/or the *RegistryPath* must be passed.

### `RegistryPath` [in, optional]

Optionally contains the path to the key whose subkeys will be enumerated as property sets, or otherwise **NULL**. The *ParentKey* and/or the Registry Path must be passed.

## Return value

The **KsUnserializeObjectPropertiesFromRegistry** function returns STATUS_SUCCESS if the property sets were unserialized. The function returns an error if the registry path was invalid, one of the subkeys was invalid, setting a property was unsuccessful, the serialized format was invalid, or a property set was not supported on the object.